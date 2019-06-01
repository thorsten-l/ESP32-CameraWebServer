# Firmware Binary

If you do not wish to compile this firmware by your own, you can use the
precompiled firmware in this directory.

## Predefined WiFi Network

- SSID: IoT
- Password: HelloIot123

---

## USB_UPLOAD script

A sample script to upload the firmware via USB connection.

**Change the USB device in the script
to your device path.**

### esptool

The [esptool](https://github.com/espressif/esptool) is needed to upload the firmware over USB.
I used the `esptool` comes with [PlatformIO](https://platformio.org/).

## References

- [PlatformIO](https://platformio.org/)
- [esptool](https://github.com/espressif/esptool)
