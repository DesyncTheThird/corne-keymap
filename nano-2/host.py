import time
import threading
from datetime import datetime
import hid

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

#===============================================================================
# Utils
#===============================================================================

RECONNECT_INTERVAL = 0.5
TIME_SEND_INTERVAL = 0.5

running = threading.Event()
last_time_sent = 0

def log(prefix, data):
    ts = datetime.now().strftime("%H:%M:%S.%f")[:-3]
    hexdata = " ".join(f"{b:02X}" for b in data)
    ascii_str = "".join(chr(b) if 32 <= b <= 126 else '.' for b in data)
    print(f"[{ts}] {prefix}: {ascii_str} | {hexdata}")

def logtime(prefix, data):
    ts = datetime.now().strftime("%H:%M:%S.%f")[:-3]
    dec = " ".join(f"{b:03d}" for b in data)
    print(f"[{ts}] {prefix}: {dec}")

def find_device(cfg):
    for entry in hid.enumerate():
        if (
            entry["vendor_id"] == cfg["vendor_id"]
            and entry["product_id"] == cfg["product_id"]
            and entry.get("usage_page") == cfg["usage_page"]
            and entry.get("usage") == cfg["usage"]
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
    while device is None and running.is_set():
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
# Message passing
#===============================================================================

def time_format(dt):
    report = [0] * 4
    report[0] =  0x54
    report[1] = dt.hour
    report[2] = dt.minute
    report[3] = dt.second
    return bytes(report)

def pass_messages():
    global last_time_sent

    devA = None
    devB = None

    print("Pass-through loop started.\n")

    while running.is_set():
        devA = ensure_connected(devA, KEYBOARD)
        devB = ensure_connected(devB, TRACKBALL)

        if not running.is_set():
            break

        now = time.time()
        if abs(now - last_time_sent) >= TIME_SEND_INTERVAL:
            last_time_sent = now
            dt = datetime.now()
            time_report = make_report(time_format(dt), KEYBOARD["report_length"])
            if devA:
                safe_write(devA, time_report)
                logtime("Host → KB", time_report[1:])

        dataA = safe_read(devA, KEYBOARD["report_length"])
        if dataA is None:
            devA = handle_disconnect(devA, "Keyboard")
            continue
        if dataA:
            report = make_report(process_A_to_B(dataA), TRACKBALL["report_length"])
            if not safe_write(devB, report):
                devB = handle_disconnect(devB, "Trackball")
                continue
            log("KB → TB", report[1:])

        dataB = safe_read(devB, TRACKBALL["report_length"])
        if dataB is None:
            devB = handle_disconnect(devB, "Trackball")
            continue
        if dataB:
            report = make_report(process_B_to_A(dataB), KEYBOARD["report_length"])
            if not safe_write(devA, report):
                devA = handle_disconnect(devA, "Keyboard")
                continue
            log("TB → KB", report[1:])

        time.sleep(0.001)

#===============================================================================
# Tray mode
#===============================================================================

def run_tray_mode():
    import pystray
    from pystray import MenuItem as item
    from PIL import Image, ImageDraw

    def make_icon(colour):
        img = Image.new("RGB", (64, 64), "black")
        d = ImageDraw.Draw(img)
        d.rectangle([16, 16, 48, 48], fill=colour)
        return img

    ICON_RUNNING = make_icon("white")
    ICON_STOPPED = make_icon("red")

    def update_icon(icon, running_flag):
        icon.icon = ICON_RUNNING if running_flag else ICON_STOPPED
        icon.visible = True

    def start(icon=None, _=None):
        if not running.is_set():
            running.set()
            threading.Thread(target=pass_messages, daemon=True).start()
            if icon:
                update_icon(icon, True)

    def stop(icon=None, _=None):
        if running.is_set():
            running.clear()
            if icon:
                update_icon(icon, False)

    def exit_app(icon, _):
        running.clear()
        update_icon(icon, False)
        icon.stop()


    menu = (
        item("Start", start),
        item("Stop", stop),
        item("Exit", exit_app),
    )

    start()
    icon = pystray.Icon("DevicePassThrough", ICON_RUNNING, "Device Pass-through", menu)
    icon.run()

#===============================================================================
# Entry point
#===============================================================================

if __name__ == "__main__":
    import sys

    has_console = sys.stdout and sys.stdout.isatty()

    if has_console:
        print("Running in terminal mode.")
        running.set()
        try:
            pass_messages()
        except KeyboardInterrupt:
            print("\nStopping.")
            running.clear()
    else:
        run_tray_mode()
