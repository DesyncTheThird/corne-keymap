import time
import logging
import threading
from datetime import datetime
import hid

#===============================================================================
# Logging config
#===============================================================================

logging.basicConfig(
    level=logging.INFO,
    format="[%(asctime)s] %(levelname)-8s %(message)s",
    datefmt="%H:%M:%S",
)

# Suppress overly verbose library loggers if needed
# logging.getLogger("hid").setLevel(logging.WARNING)

logger = logging.getLogger(__name__)

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
TIME_SEND_INTERVAL = 0.2

running = threading.Event()
last_time_sent = 0


def log_data(prefix, data):
    hexdata = " ".join(f"{b:02X}" for b in data)
    ascii_str = "".join(chr(b) if 32 <= b <= 126 else "." for b in data)
    logger.debug("%s: %s | %s", prefix, ascii_str, hexdata)


def log_time(prefix, data):
    dec = ":".join(f"{b:02d}" for b in data[1:4])
    logger.debug("%s: Time %s", prefix, dec)


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


OPEN_RETRIES = 5
OPEN_RETRY_DELAY = 0.1

def open_device(cfg):
    for attempt in range(1, OPEN_RETRIES + 1):
        info = find_device(cfg)
        if info is None:
            return None
        try:
            dev = hid.Device(path=info["path"])
            logger.info("Connected: %s — %s", dev.manufacturer, dev.product)
            return dev
        except hid.HIDException as e:
            if "Permission denied" in str(e) and attempt < OPEN_RETRIES:
                logger.debug("Permission denied on attempt %d/%d, retrying...",
                             attempt, OPEN_RETRIES)
                time.sleep(OPEN_RETRY_DELAY)
            else:
                logger.exception("Failed to open device (VID=%s, PID=%s)",
                                 hex(cfg["vendor_id"]), hex(cfg["product_id"]))
                return None


def ensure_connected(device, cfg):
    while device is None and running.is_set():
        logger.debug("Waiting for device (VID=%s, PID=%s)...",
                       hex(cfg["vendor_id"]), hex(cfg["product_id"]))
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
    logger.warning("%s disconnected.", name)
    try:
        dev.close()
    except Exception:
        logger.debug("Exception while closing %s device.", name, exc_info=True)
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
    report[0] = 0x54
    report[1] = dt.hour
    report[2] = dt.minute
    report[3] = dt.second
    return bytes(report)


def pass_messages():
    global last_time_sent

    devA = None
    devB = None

    logger.info("Pass-through loop started.")

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
                log_time("Host → KB", time_report[1:])

        dataA = safe_read(devA, KEYBOARD["report_length"])
        if dataA is None:
            devA = handle_disconnect(devA, "Keyboard")
            continue
        if dataA:
            report = make_report(process_A_to_B(dataA), TRACKBALL["report_length"])
            if not safe_write(devB, report):
                devB = handle_disconnect(devB, "Trackball")
                continue
            log_data("KB → TB", report[1:])

        dataB = safe_read(devB, TRACKBALL["report_length"])
        if dataB is None:
            devB = handle_disconnect(devB, "Trackball")
            continue
        if dataB:
            report = make_report(process_B_to_A(dataB), KEYBOARD["report_length"])
            if not safe_write(devA, report):
                devA = handle_disconnect(devA, "Keyboard")
                continue
            log_data("TB → KB", report[1:])

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
            logger.info("Pass-through started.")

    def stop(icon=None, _=None):
        if running.is_set():
            running.clear()
            if icon:
                update_icon(icon, False)
            logger.info("Pass-through stopped.")

    def exit_app(icon, _):
        running.clear()
        update_icon(icon, False)
        logger.info("Exiting.")
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
    silent = "--silent" in sys.argv
    verbose = "--verbose" in sys.argv

    if verbose:
        logging.getLogger().setLevel(logging.DEBUG)

    if has_console or silent:
        running.set()
        try:
            pass_messages()
        except KeyboardInterrupt:
            running.clear()
            logger.info("Interrupted by user.")
    else:
        run_tray_mode()
