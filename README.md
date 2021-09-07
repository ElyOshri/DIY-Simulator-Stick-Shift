# DIY-Simulator-Stick-Shift

[![GitHub release](https://img.shields.io/github/v/release/ElyOshri/DIY-Simulator-Stick-Shift?include_prereleases&label=Release)](https://github.com/ElyOshri/DIY-Simulator-Stick-Shift/releases)
[![Downloads](https://img.shields.io/github/downloads/ElyOshri/DIY-Simulator-Stick-Shift/total?label=Downloads)](https://github.com/ElyOshri/DIY-Simulator-Stick-Shift/releases)
[![Donate](https://img.shields.io/badge/Donate-PayPal-blue.svg)](https://www.paypal.me/ElyOshri1)

A 3D Printed DIY Simulator Stick Shift Using Potentiometers And Arduino Nano Or ESP32

![image](https://github.com/ElyOshri/DIY-Simulator-Stick-Shift/blob/main/Resources/Banner.jpg)

## Topics
 - [Tested_Boards:](#Tested_Boards:)
 - [Hardware:](#Hardware:)
 - [Credits](#Credits)

## Tutorial:
Download the hardware and firmware folders from [releases](https://github.com/ElyOshri/DIY-Simulator-Stick-Shift/releases) start printing the parts from the hardware folder according to 3d printing list from [Hardware](#Hardware:) (some of the parts need support).

After you finish printing the Base, Hinge and the Main Stick you can start assmbeling the parts and wire the potantiometers to your board according to this wiring diagram

## Tested_Boards:
```
* Arduino Nano
* ESP-WROOM-32
```

## Hardware:

* Arduino Nano or ESP32 (ESP32 for Bluetooth)
* WL b10k ohm Potentiometer (2x)
* 1mm or thinner metal wire (solder or paper clips can be used)
* 26 gauge or bigger electrical wire (2 meters should be enough)
* USB cable (depending on your board)
* Solder or a crimping set (JST connectors 5 pin JST-XH 2.54mm should work) 

**3D Printed Parts:**
* Bottom Hinge
* Top Hinge
* Main Stick
* Base Right
* Base Left
* Base Top
* Base Bottom
* H Frame
* Right Frame / + Arduino Nano Case (depened on your board)
* Left Frame / + ESP32 Case (depened on your board)
* Base Attachment (optional)
* Case Cover ESP32/Arduino Nano (optional and depened on your board)

**Tools:**
* Soldering Iron / Crimping Set
* 3D Printer / A way to get the parts
* A computer with a usb port and the Arduino IDE to program the board


## Credits
* Arduino Joystick Library (By: MHeironimus): https://github.com/MHeironimus/ArduinoJoystickLibrary
* ESP32 Gamepad Library (By: lemmingDev): https://github.com/lemmingDev/ESP32-BLE-Gamepad
* ESP32 Case (By: Antonio Garcia): https://www.thingiverse.com/thing:2071188
