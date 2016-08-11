avr_boot SD Bootloader for Arduino
==========

This bootloader loads a file from the SD card on startup. This documentation is specific to Arduino IDE boards installation. The main documentation is located [here](https://github.com/zevero/avr_boot).


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

#### Manual Installation
- Download the avr_boot files here: https://zevero.github.io/avr_boot/avr_boot_manualinstall_1.1.0.zip
- Extract the .zip file.
- Move the **avr_boot** folder into the **hardware** folder in your sketchbook folder.
- If the Arduino IDE is running then restart it.

<a id="menus"></a>
## Using the Board Menu Entries
After installing avr_boot several new boards are added to the **avr_boot** section of the **Tools** > **Board** menu. When any of these boards are selected additional menus will appear under the **Tools** menu.

Whenever you change a setting in these menus you need to **[Burn Bootloader](#burn)** to reconfigure your board.

#### BOD Menu
BOD stands for Brown-out Detection. This feature is intended to avoid improper operation caused by insufficient supply voltage. If the supply voltage drops below the BOD value then the microcontroller is reset.

#### Model Menu
Displays a list of board models for your **Board** menu selection.

#### SD CS Pin Menu
The SD CS pin may be connected to different Arduino pins depending on which shield you are using.
- Ethernet Shield: 4
- Arduino Ethernet: 4
- Seeed SD card shield: 4
- Sparkfun MicroSD Shield: 8
- Adafruit Data Logger Shield: 10

#### Clock Menu
- **16MHz External Low Power** - This is usually the best setting to use for commercially produced boards that run at 16MHz as it will decrease power usage compared to the **16MHz Full Swing** setting.
- **16MHz External Full Swing** - This setting can be used for breadboard or homemade 16MHz boards where the **16MHz Low Power** setting causes unreliability due to electrical interference.
- **20MHz External** - If your board has a 20MHz crystal this is the one for you.
- **8MHz External Low Power** - For boards with an external 8MHz crystal.
- **8MHz External Full Swing** - For boards with an external 8MHz crystal where the **8MHz Low Power** setting causes unreliability due to electrical interference.
- **8MHz Internal** - For boards without an external 16MHz crystal or to reduce power consumption.

#### Pinout Menu(ATmega1284P only)
Included pinout variants:
- [avr_developers](https://github.com/JChristensen/mighty-1284p/blob/v1.6.3/avr/variants/avr_developers/pins_arduino.h)
- [Calunium PCB](https://github.com/zevero/avr_boot/blob/gh-pages/avr/variants/calunium-pcb/pins_arduino.h)
- [Calunium Stripboard](https://github.com/zevero/avr_boot/blob/gh-pages/avr/variants/calunium-stripboard/pins_arduino.h)

Supported with installation of **[Mighty 1284P](https://github.com/JChristensen/mighty-1284p/tree/v1.6.3)**:
- [Standard](https://github.com/JChristensen/mighty-1284p/blob/v1.6.3/avr/variants/standard/pins_arduino.h)
- [Bobuino](https://github.com/JChristensen/mighty-1284p/blob/v1.6.3/avr/variants/bobuino/pins_arduino.h)
- [Sleeping Beauty](https://github.com/JChristensen/mighty-1284p/blob/v1.6.3/avr/variants/sleepingbeauty/pins_arduino.h)


<a id="burn"></a>
## Burning the Bootloader
To burn the bootloader, you will need an ISP(in-system programmer). After you have connected the Arduino board and the programmer to your computer navigate to the **Tools** > **Board** menu and select the correct board. Then go to **Tools** > **Programmer** and select the programmer you are using. In case you are using **Arduino as ISP**, make sure that the selected port in the **Tools** > **Serial Port** menu refers to the **Arduino as ISP** board and not the board that you want to burn the bootloader on. Now, just launch the **Tools** > **Burn Bootloader** command and wait until the operation completes. You will no longer be able to upload sketches to your board using USB once the avr_boot bootloader is installed. To go back to normal uploading repeat the bootloader burning process with a non-avr_boot board selected.


<a id="upload"></a>
## Uploading Your Sketch
See the **Compile and put your sketch on SD Card** instructions **[here](https://github.com/zevero/avr_boot)**.


<a id="acknowledgements"></a>
## Acknowledgements
- [David A. Mellis](https://github.com/damellis) - avr_developers variant for ATmega1284P
- [Steve Marple](https://github.com/stevemarple) - Calunium PCB and Stripboard variants for ATmega1284P
- [Mighty 1284P](https://github.com/JChristensen/mighty-1284p) - ATmega1284P support
- [Others listed in the main documentation](https://github.com/zevero/avr_boot)
