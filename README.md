avr_boot SD Bootloader for Arduino
==========

The avr_boot bootloader loads a program from the SD card on startup. This documentation is specific to [Arduino](http://arduino.cc) IDE boards installation. The main documentation is located [here](https://github.com/zevero/avr_boot).

## Table of Contents
- [Installation](#installation)
  - [Boards Manager Installation](#boards-manager-installationrequires-arduino-ide-version-164-or-greater)
  - [Manual Installation](#manual-installationrequires-arduino-ide-version-161-or-greater)
- [Using the Board Menu Entries](#using-the-board-menu-entries)
  - [Processor Menu](#processor-menu)
  - [BOD Menu](#bod-menu)
  - [Model Menu](#model-menu)
  - [SD CS Pin Menu](#sd-cs-pin-menu)
  - [Clock Menu](#clock-menu)
  - [Pinout Menu](#pinout-menuatmega1284p-and-atmega644papa-only)
- [Burning the Bootloader](#burning-the-bootloader)
- [Uploading Your Sketch](#uploading-your-sketch)
- [Troubleshooting](#troubleshooting)
- [Supported Microcontrollers](#supported-microcontrollers)
- [Supported Boards](#supported-boards)
- [Board Addition Requests](#board-addition-requests)
- [Acknowledgments](#acknowledgments)


## Installation
**WARNING: avr_boot is not compatible with Arduino AVR Boards 1.6.12(included with Arduino IDE 1.6.10).**

There are two options for installing **avr_boot** boards in the Arduino IDE:
#### Boards Manager Installation(requires Arduino IDE version 1.6.4 or greater)
- Open the Arduino IDE.
- Open the **File > Preferences** menu item.
- Enter the following URL in **Additional Boards Manager URLs**: https://zevero.github.io/avr_boot/package_zevero_avr_boot_index.json
- Open the **Tools > Board > Boards Manager...** menu item.
- Wait for the platform indexes to finish downloading.
- Scroll down until you see the **avr_boot** entry and click on it.
  - **Note**: If you are using Arduino IDE 1.6.6 you may need to close **Boards Manager** and then reopen it before the **avr_boot** entry will appear.
- Click **Install**.
- After installation is complete close the **Boards Manager** window.

#### Manual Installation(requires Arduino IDE version 1.6.1 or greater)
- Download the avr_boot files here: https://zevero.github.io/avr_boot/avr_boot_manualinstall_1.3.0.zip
- Extract the .zip file.
- Move the **avr_boot** folder into the **hardware** folder in your sketchbook folder. You can find the location of your sketchbook folder at **File > Preferences > Sketchbook location:**.
- If the Arduino IDE is running then restart it.


## Using the Board Menu Entries
After installing avr_boot several new boards are added to the **avr_boot** section of the **Tools** > **Board** menu. When any of these boards are selected additional menus will appear under the **Tools** menu.

Whenever you change a setting in these menus you need to **[Burn Bootloader](#burning-the-bootloader)** to reconfigure your board.

#### Processor Menu
Provides a list of the available microprocessor versions(e.g. ATmega328P, ATmega328). Note that although Arduino calls the microprocessor on their Uno and similar boards "ATmega328" they actually are ATmega328P.

#### BOD Menu
BOD stands for Brown-out Detection. This feature is intended to avoid improper operation caused by insufficient supply voltage. If the supply voltage drops below the BOD value then the microcontroller is reset.

#### Model Menu
Displays a list of board models for your **Board** menu selection. You don't need to re-burn the bootloader after changing the model menu selection

#### SD CS Pin Menu
The SD CS pin may be connected to different Arduino pins depending on which shield you are using or your wiring preference if not using a shield.
- Ethernet Shield: **4**
- Arduino Ethernet: **4**
- Seeed SD card shield: **4**
- SparkFun MicroSD Shield: **8**
- Adafruit Data Logger Shield: **10**

#### Clock Menu
Note that ATmel has recently removed full swing support from some of the AVR models(http://img.digikey.com/Retractions/WC154601%20-%20PCN-12-23-2015.pdf).
- **16MHz External Low Power** - This is usually the best setting to use for commercially produced boards that run at 16MHz as it will decrease power usage compared to the **16MHz Full Swing** setting.
- **16MHz External Full Swing** - This setting can be used for breadboard or homemade 16MHz boards where the **16MHz Low Power** setting causes unreliability due to electrical interference.
- **20MHz External** - If your board has a 20MHz crystal this is the one for you.
- **8MHz External Low Power** - For boards with an external 8MHz crystal.
- **8MHz External Full Swing** - For boards with an external 8MHz crystal where the **8MHz Low Power** setting causes unreliability due to electrical interference.
- **8MHz Internal** - For boards without an external crystal or to reduce power consumption.

#### Pinout Menu
- ATmega1284/P, ATmega644/P/A/PA, ATmega324P/A/PA, and ATmega32/A
  - Included pinout variants:
    - [avr_developers](https://github.com/zevero/avr_boot/blob/gh-pages/avr/variants/avr_developers/pins_arduino.h)
    - [Calunium PCB](https://github.com/zevero/avr_boot/blob/gh-pages/avr/variants/calunium-pcb/pins_arduino.h)
    - [Calunium Stripboard](https://github.com/zevero/avr_boot/blob/gh-pages/avr/variants/calunium-stripboard/pins_arduino.h)
    - [Goldilocks v1.1/Analogue](https://github.com/zevero/avr_boot/blob/gh-pages/avr/variants/goldilocks/pins_arduino.h)
    - [WildFire v2](https://github.com/zevero/avr_boot/blob/gh-pages/avr/variants/wildfirev2/pins_arduino.h)
    - [WildFire v3](https://github.com/zevero/avr_boot/blob/gh-pages/avr/variants/wildfirev3/pins_arduino.h)
    - [Wiring S](https://github.com/zevero/avr_boot/blob/gh-pages/avr/variants/WiringS/pins_arduino.h)
    - [Wiring Play Shield](https://github.com/zevero/avr_boot/blob/gh-pages/avr/variants/WiringSPlayShield/pins_arduino.h)
  - Supported with installation of **[Mighty 1284P](https://github.com/JChristensen/mighty-1284p/tree/v1.6.3)**(ATmega1284/P only) or **[MightyCore](https://github.com/MCUdude/MightyCore)**(ATmega32/A, 324/P/A/PA, 644/P/A/PA, 1284/P):
    - [Standard](https://github.com/JChristensen/mighty-1284p/blob/v1.6.3/avr/variants/standard/pins_arduino.h)
    - [Bobuino](https://github.com/JChristensen/mighty-1284p/blob/v1.6.3/avr/variants/bobuino/pins_arduino.h)
- ATmega1284/P
  - Supported with installation of **[Mighty 1284P](https://github.com/JChristensen/mighty-1284p/tree/v1.6.3)**
    - [Sleeping Beauty](https://github.com/JChristensen/mighty-1284p/blob/v1.6.3/avr/variants/sleepingbeauty/pins_arduino.h)
- ATmega1281, ATmega128/A ATmega64/A
  - [MegaCore](https://github.com/zevero/avr_boot/blob/gh-pages/avr/variants/megacore-standard/pins_arduino.h)
  - [Wiring 1.0/1.1](https://github.com/zevero/avr_boot/blob/gh-pages/avr/variants/Wiring1/pins_arduino.h)

## Burning the Bootloader
To burn the bootloader, you will need an ISP(in-system programmer). After you have connected the Arduino board and the programmer to your computer navigate to the **Tools** > **Board** menu and select the correct board. Then go to **Tools** > **Programmer** and select the programmer you are using. In case you are using **Arduino as ISP**, make sure that the selected port in the **Tools** > **Serial Port** menu refers to the **Arduino as ISP** board and not the board that you want to burn the bootloader on. Now, just launch the **Tools** > **Burn Bootloader** command and wait until the operation completes. You will no longer be able to upload sketches to your board using USB once the avr_boot bootloader is installed. To go back to normal uploading repeat the bootloader burning process with a non-avr_boot board selected.


## Uploading Your Sketch
See the **Compile and put your sketch on SD Card** instructions **[here](https://github.com/zevero/avr_boot#put-your-sketch-on-sd-card)**.


## Troubleshooting
- `java.lang.NullPointerException`(Arduino IDE 1.6.5-r5 or previous) or `panic: runtime error: invalid memory address or nil pointer dereference`(Arduino IDE 1.6.6 or higher) error while compiling/uploading with ATmega1284/P or ATmega644/P/A/PA.
  - Your **Pinout** menu selection requires the installation of [Mighty 1284P](https://github.com/JChristensen/mighty-1284p/tree/v1.6.3) or [MightyCore](https://github.com/MCUdude/MightyCore). Either install it or choose a different pinout.
- avr_boot boards don't appear in the **Tools > Board** menu after manual installation.
  - avr_boot requires Arduino IDE 1.6.1 or higher.
- `avrdude: verification error; content mismatch` error during lock verification while burning bootloader with AVRISP mkII or other STK500v2 programmer.
  - avr_boot is not compatible with Arduino AVR Boards 1.6.12. Please use any other version of Arduino AVR Boards.
- avr_boot entry doesn't appear in Boards Manager when using Arduino IDE 1.6.6.
  - Close Boards Manager and then open it again.
- `Bootloader file specified but missing` warning when compiling when using Arduino IDE 1.6.6.
  - Please ignore, this is caused by a bug in that IDE version and will not cause any problems.
-  `Warning: This core does not support exporting sketches. Please consider upgrading it or contacting its author` when doing **Sketch > Export compiled Binary** while using Arduino IDE 1.6.5 on Windows.
  - This is caused by a bug in Arduino IDE 1.6.5. Please either use the [alternate method](https://github.com/zevero/avr_boot#put-your-sketch-on-sd-card) of obtaining the compiled .hex file or upgrade to a more recent version of the Arduino IDE.
- `avrdude: AVR Part "build.mcu" not found.` or `avr-g++: error: unrecognized argument in option '-mmcu=build.mcu'`.
  - avr_boot requires Arduino IDE 1.6.1 or greater,
- `avrdude: AVR Part "atmega644a" not found.` or similar error during **Upload** or **Upload Using Programmer** to ATmega644A, ATmega644PA, ATmega1284, ATmega32A, ATmega128A or ATmega64A.
  - This is caused by a limitation of the Arduino IDE that does not allow avr_boot's custom avrdude.conf file to be used for these actions when one of the Arduino AVR Boards programmers is selected.  Since it doesn't interfere with avr_boot's intended usage for SD card program uploads, the issue will not be fixed at this time. You can solve the issue by installing [MightyCore](https://github.com/MCUdude/MightyCore) or [ATTinyCore](https://github.com/SpenceKonde/ATTinyCore) and selecting the version of your programmer marked `(MightyCore)` or `(ATtiny)` from the **Tools > Programmer** menu.
- Using non-A*n* analog pin numbers notation with `analogRead()` doesn't work correctly(e.g. 4 instead of A4).
  - This is a known limitation of Arduino's `analogRead()` function with non-standard microcontroller parts. Please use A*n* pin notation or use the equivalent digital pin number(e.g. 14 for A0 on Uno).
- An Arduino core or other library doesn't work correctly with one of the microcontrollers supported by avr_boot
  - avr_boot is a bootloader, not a core. The Arduino AVR Boards core and the Arduino libraries are used by avr_boot. These will often work well for non-standard microcontrollers but not always. For improved support of ATmega1284/644/324/32 microcontrollers please use [MightyCore](https://github.com/MCUdude/MightyCore). For improved support of ATmega128/64 please use [MegaCore](https://github.com/MCUdude/MegaCore). You can use the avr_boot bootloader with the files generated by compiling with these cores.
- My SD card reader's CS line is connected to to a pin not included in the menu.
  - Please compile avr_boot from source. You can set any SD CD pin you like.
- I found a bug.
  - Make sure you are using the latest version of avr_boot and the latest version of the Arduino IDE.
  - Spend some time troubleshooting and doing research to verify the issue and make sure it's caused by avr_boot.
  - Do a search of https://github.com/zevero/avr_boot/issues to make sure your issue hasn't already been reported.
  - Report the issue at https://github.com/zevero/avr_boot/issues or submit a pull request at https://github.com/zevero/avr_boot/pulls
    - Please give as much information as possible, including:
      - avr_boot version
      - Arduino IDE version
      - Operating system
      - Installation method(Boards Manager, Manual, or compile from source)
      - Which selections you are using in the **Tools > Board**, **Tools > Processor**, **Tools > Pinout**, **Tools > Clock**, **Tools > BOD** menus.
      - Complete error messages.
      - Full description of the steps required to reproduce the issue.


## Supported Microcontrollers:
- ATmega328, ATmega328P
- ATmega32U4
- ATmega1284, ATmega1284P
- ATmega644, ATmega644A, ATmega644P, ATmega644PA
- ATmega324, ATmega324A, ATmega324P, ATmega324PA
- ATmega32, ATmega32A
- ATmega1281
- ATmega128, ATmega128A
- ATmega64, ATmega64A
- ATmega1280
- ATmega640
- Other microcontrollers can be used if you compile avr_boot from source.


## Supported Boards:
- ATmega328P based:
  - Uno
  - Duemilanove(ATmega328P version)
  - Diecimila(ATmega328P version)
  - Nano(ATmega328P version)
  - Mini(ATmega328P version)
  - Ethernet
  - Fio
  - BT(ATmega328P version)
  - LilyPad(ATmega328P version)
  - Pro(ATmega328P version)
  - Pro Mini(ATmega328P version)
  - SparkFun RedBoard
  - Metro
  - Pro Trinket
  - Digital Sandbox
  - RedBot
- ATmega32U4 based:
  - Leonardo
  - Micro
  - Esplora
  - LilyPad USB
  - Flora
  - Bluefruit Micro
  - Feather 32u4
  - Adafruit 32u4 Breakout
  - Circuit Playground 32u4
  - MaKey MaKey
  - Pro Micro
  - Fio v3
  - Qduino Mini
- ATmega1280 based
  - Arduino Mega 1280
- ATmega1284P based:
  - Mighty 1284P
  - Mighty Mini 1284P
  - Bobuino
  - Skinny Bob
  - Sleeping Beauty
  - Calunium PCB
  - Calunium Stripboard
  - Firebirduino UU(**Sleeping Beauty** pinout)
  - Mbili(**Standard** pinout)
  - Ndogo(**Standard** pinout)
  - Tatu(**Standard** pinout)
  - EMC01(**avr-developers.com** pinout)
  - Goldilocks v1.1
  - Goldilocks Analogue
  - WildFire v2
  - WildFire v3
- ATmega644/P/A/PA based:
  - Sanguino(**avr-developers.com** pinout)
  - Wiring S
  - Wiring S with Play Shield
- ATmega1281 based:
  - Wiring 1.1
- ATmega128 based:
  - Wiring 1.0


## Board Addition Requests
Do you have a board or microcontroller that has not been added to avr_boot's Arduino IDE support files? I am willing to consider adding it provided you can meet the following requirements:
- If you only want a model of board for a preexisting microcontroller added please provide a link to its standard boards support files. This should be a simple process and you can disregard the rest of the requirements.
- ATmega2560 can not be supported currently. I have already tried and failed(see https://github.com/zevero/avr_boot/issues/4). If you can help add ATmega2560 support to the bootloader source code we would be very grateful and I will then add Arduino IDE support for that board.
- A variant file for the board or microcontroller must exist. This is the pins_arduino.h file found in the variants folder.
- You must already have successfully used avr_boot, whether with your own build for the target microcontroller or another microcontroller. This is to ensure that you can provide effective testing.
- You must be willing to thoroughly test my work and be a communicative, active participant in the process. If I owned this hardware then avr_boot would already support it so I'm relying on you for testing.
- The target microcontroller must support a 4096 byte(2048 word) boot section. Microcontrollers such as ATmega168 don't support the size of the avr_boot bootloader. See the **Boot Size Configuration** table of the datasheet for your microcontroller.
- As the name suggests, this bootloader is for AVR architecture only.

Please submit an [issue](https://github.com/zevero/avr_boot/issues/new) with your request.


## Acknowledgments
- [David A. Mellis](https://github.com/damellis) - avr_developers variant
- [Steve Marple](https://github.com/stevemarple) - Calunium PCB and Stripboard variants
- [Mighty 1284P](https://github.com/JChristensen/mighty-1284p) - Standard, Bobuino, and Sleeping Beauty variants
- [MCUdude](https://github.com/MCUdude) - [MegaCore](https://github.com/MCUdude/MegaCore) variant for ATmega64/A, 128/A
- [Phillip Stevens](https://github.com/feilipu) - Goldilocks v1.1 variant
- [WickedDevice](https://github.com/WickedDevice) - WildFire v2/v3 variants
- [Adafruit](https://github.com/adafruit) - adafruit32u4, bluefruitmicro, circuitplay32u4, feather32u4, flora variants
- [SparkFun](https://github.com/sparkfun) - promicro variant
- [Others listed in the main documentation](https://github.com/zevero/avr_boot#thanks-to)
