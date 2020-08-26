# Cloudboard Micro-controller
The Cloudboard is an artifact from a previous project that was intended to be used in future projects. Only 100 of the boards were made. This repo has the files needed to extend PlatformIO to support the Cloudboard. This repo holds the Board Definition for PLatformIO, an install script as well as a handful of examples to get you up and running.

![Cloudboard Image](https://raw.githubusercontent.com/Phando/Cloudboard32/master/assets/board.png)

## Features

* Dual Core
* WI-FI 2.4ghz
* Bluetooth - dual mode (classic and BLE)
* OLED Display - 128x64
* Single Onboard Neopixel
* 4 x Sensor Input
* 2 x Motor Control
* 2 x Capacitive Leads
* 2 x RGB LED Strip Drivers
* Rotary Input
* Battery and USB power input

## Development Environment
The best way to work with the Cloudboard is by using VS Code and the PlatformIO (PIO) extension. This a very popular IDE that supports extensions which enable all sorts of development, including [Salesforce DX](https://developer.salesforce.com/platform/dx). Once installed, you will need to add the PIO extension. PIO is explicitly built for working with micro controllers.

Install VS Code from [https://code.visualstudio.com](https://code.visualstudio.com/)﻿. 

![PlatformIO IDE Image](https://raw.githubusercontent.com/Phando/Cloudboard32/master/assets/pioIcon.png)

Once installed, open the application to complete the setup.

* Press the Extensions button on the left column inside VS Code.
* Search for Platform in the top left
* Select PlatformIO from the results
* Choose install in the right pane.

## Board Definition
Since the Cloudboard is a short run custom product, PlatformIO has no way of knowing about it. By following the instructions below, you will be able to create PIO projects and select Cloudboard as your desired platform.

Download the Cloudboard repo from ﻿[https://github.com/Phando/Cloudboard32](https://github.com/Phando/Cloudboard32).

### Script Installation:
* Open the repo and run the addBoard.sh script
* If the script is not executable type *chmod +x addBoard.sh*

### Manual Installation:
* **copy** platformio/packages/framework-arduinoespressif32/variants/Cloudboard-32 **to**
~/.platformio/packages/framework-arduinoespressif32/variants
* **copy** platformio/platforms/espressif32/boards/cloudboard-32.json **to** 
~/.platformio/platforms/espressif32/boards
* **copy** platformio/platforms/espressif32/examples/* **to**
~/.platformio/platforms/espressif32/examples

## Pin Definitions
Use the pin names below in your code to ensure you are using the right pin for the right purpose. The pin names below match the text written on the Cloudboard. 
### OLED Display Pins
* OLED_CS — 4
* OLED_DC — 5
* OLED_MOSI — 13
* OLED_CLK — 14
* OLED_RST — -1 // Not Connected

### Sensor Pins
* GPIO18 — 18
* GPIO19 — 19
* GPIO22 — 22
* GPIO23 — 23

### LED Pins
* NEOPIXEL16 — 16
* NEOPIXEL17 — 17
* PIXEL — 12

### PWM Pins
* PWM26 — 26
* PWM27 — 27

### Touch Pins
* TOUCH2 — 2
* TOUCH3 — 15
