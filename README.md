# DIY-Simulator-Stick-Shift

[![GitHub release](https://img.shields.io/github/v/release/ElyOshri/DIY-Simulator-Stick-Shift?color=g&label=Release)](https://github.com/ElyOshri/DIY-Simulator-Stick-Shift/releases)
[![Donate](https://img.shields.io/badge/Donate-PayPal-blue.svg)](https://www.paypal.me/ElyOshri1)

A 3D Printed DIY Simulator Stick Shift Using Potentiometers And Arduino Nano Or ESP32

![image](https://github.com/ElyOshri/DIY-Simulator-Stick-Shift/blob/main/Resources/Banner.jpg)

## Topics
 - [Tutorial](https://github.com/ElyOshri/DIY-Simulator-Stick-Shift#tutorial)
 - [Tested Boards](https://github.com/ElyOshri/DIY-Simulator-Stick-Shift#tested_boards)
 - [Hardware](https://github.com/ElyOshri/DIY-Simulator-Stick-Shift#hardware)
 - [Credits](https://github.com/ElyOshri/DIY-Simulator-Stick-Shift#credits)

## Tutorial:
Download the hardware and firmware folders from [releases](https://github.com/ElyOshri/DIY-Simulator-Stick-Shift/releases) start printing the parts from the hardware folder according to 3d printing list from [Hardware](#Hardware:) (some of the parts need support).

After you finish printing the Base, Hinge and the Main Stick you can start assembling the parts ([use this 3d model for reference](https://a360.co/3D5aO7Y)) ,
then insert the potentiometers to they're spots and wire them to your board according to this wiring diagram 
([Arduino Nano](https://user-images.githubusercontent.com/79017393/132395478-2bf8ad6f-0b95-429a-84c2-f516c4f6ddcb.png), 
[ESP32](https://user-images.githubusercontent.com/79017393/132395408-584d270a-1471-4dd1-976c-bccc9487b785.png) (for ESP32 use 3V3 instead of 5V)) You can look at the firmware for the exact pins that i used. 

After you wired everything up you can start uploading the firmware by choosing the correct file in the Firmware folder, changing the pins in the code, choosing your board and downloading all of the drivers and libraries necessary you can start uploading the firmware.(some boards needs you to press a button on them while uploading firmware)
* Note that for each board its going to be different and you may need to install libraries and drivers for your board (the links for the libraries and drivers are at the top of the file)
* In the serial monitor your need to set the baud rate to `115200` to see the correct values

Then check the serial monitor move the gear lever into each position and start assigning the rows values, then upload the firmware again and you should be finished.


**Here Are Some Good Tutorial To Help You With All Of This:**
- [Arduino Nano Original Guide](https://www.arduino.cc/en/Guide/ArduinoNano)
- [Arduino Nano Clone Driver](https://electropeak.com/learn/how-to-install-ch340-driver/)
- [ESP32 Driver And Guide](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/)
- [Installing a Library](https://www.arduino.cc/en/guide/libraries)

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
* 3d printer filament (PLA or anyother ridgid filament)

**3D Printed Parts:**
* Bottom Hinge
* Top Hinge
* Main Stick
* Base Right
* Base Left
* Base Top
* Base Bottom
* H Frame
* Right Frame / + Arduino Nano Case (depends on your board)
* Left Frame / + ESP32 Case (depends on your board)
* Base Attachment (optional)
* Case Cover ESP32/Arduino Nano (optional and depends on your board)

**Tools:**
* Soldering Iron / Crimping Set
* 3D Printer / A way to get the parts
* A computer with a USB port and the Arduino IDE app to program the board


## Credits
* Arduino Joystick Library (By: MHeironimus): https://github.com/MHeironimus/ArduinoJoystickLibrary
* ESP32 Gamepad Library (By: lemmingDev): https://github.com/lemmingDev/ESP32-BLE-Gamepad
* ESP32 Case (By: Antonio Garcia): https://www.thingiverse.com/thing:2071188
* Arduino Nano Case (By: Jonathan Prive): https://www.thingiverse.com/thing:4850125
