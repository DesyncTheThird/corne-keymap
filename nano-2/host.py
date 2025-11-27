import hid
import time
from datetime import datetime

#===============================================================================
# Device Config
#===============================================================================

KEYBOARD = {
    "vendor_id": 0x4653,
    "product_id": 0x0001,
    "usage_page": 0xFF60,
    "usage": 0x61,
    "report_length": 32,
}

TRACKBALL = {
    "vendor_id": 0x5043,
    "product_id": 0x4CE5,
    "usage_page": 0xFF60,
    "usage": 0x61,
    "report_length": 32,
}

RECONNECT_INTERVAL = 0.5

#===============================================================================
# Utils
#===============================================================================

def log(prefix, data):
    ts = datetime.now().strftime("%H:%M:%S.%f")[:-3]
    hexdata = " ".join(f"{b:02X}" for b in data)
    ascii_str = "".join(chr(b) if 32 <= b <= 126 else '.' for b in data)
    print(f"[{ts}] {prefix}: {ascii_str} | {hexdata}")

def find_device(cfg):
    for entry in hid.enumerate():
        if (
            entry["vendor_id"] == cfg["vendor_id"] and
            entry["product_id"] == cfg["product_id"] and
            entry.get("usage_page") == cfg["usage_page"] and
            entry.get("usage") == cfg["usage"]
        ):
            return entry
    return None

def open_device(cfg):
    info = find_device(cfg)
    if info is None:
        return None
    try:
        dev = hid.Device(path=info["path"])
        print(f"Connected: {dev.manufacturer} — {dev.product}")
        return dev
    except Exception:
        return None

def ensure_connected(device, cfg):
    while device is None:
        print(f"Waiting for device (VID={hex(cfg['vendor_id'])}, PID={hex(cfg['product_id'])})...")
        time.sleep(RECONNECT_INTERVAL)
        device = open_device(cfg)
    return device

def safe_read(device, length):
    try:
        return device.read(length, 0)
    except Exception:
        return None

def safe_write(device, report):
    try:
        device.write(report)
        return True
    except Exception:
        return False

def make_report(data, length):
    buf = [0x00] * (length + 1)
    buf[1:1 + len(data)] = data
    return bytes(buf)

def handle_disconnect(dev, name):
    print(f"{name} disconnected.")
    try:
        dev.close()
    except Exception:
        pass
    return None

#===============================================================================
# Processing hooks (currently unused)
#===============================================================================

def process_A_to_B(data):
    return data

def process_B_to_A(data):
    return data

#===============================================================================
# Message passing loop
#===============================================================================

def pass_messages():
    devA = None
    devB = None

    print("Pass-through started. Reconnection enabled.\n")

    while True:
        devA = ensure_connected(devA, KEYBOARD)
        devB = ensure_connected(devB, TRACKBALL)

        dataA = safe_read(devA, KEYBOARD["report_length"])
        if dataA is None:
            devA = handle_disconnect(devA, "Keyboard")
            continue
        if dataA:
            report = make_report(process_A_to_B(dataA), TRACKBALL["report_length"])
            if not safe_write(devB, report):
                devB = handle_disconnect(devB, "Trackball")
                continue
            log("KB → TB ", report[1:])

        dataB = safe_read(devB, TRACKBALL["report_length"])
        if dataB is None:
            devB = handle_disconnect(devB, "Trackball")
            continue
        if dataB:
            report = make_report(process_B_to_A(dataB), KEYBOARD["report_length"])
            if not safe_write(devA, report):
                devA = handle_disconnect(devA, "Keyboard")
                continue
            log("TB → KB ", report[1:])

        time.sleep(0.001)

if __name__ == "__main__":
    try:
        pass_messages()
    except KeyboardInterrupt:
        print("\nStopping.")
