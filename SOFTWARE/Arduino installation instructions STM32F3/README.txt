The OLIMEXINO-STM32F3 board is natively supported in newest releases of the STM32's Arduino IDE package.

The latest releases of STM32 Arduino package requires Arduino IDE 2.x.x!

In Arduino IDE 2.x.x:

1. Add the URL to STM32 support from File --> Preferences:

In "Additional Boards Manager URLs" append to the list the link below:

https://github.com/stm32duino/BoardManagerFiles/raw/main/package_stmicroelectronics_index.json

2. Install the STM32 board support form Tools --> Board --> Boards Manager...

Filter from the search box for package "STM32" --> and find "STM32 MCU based boards" and select "Install"

3. Select the OLIMEXINO-STM32 board. Navigate to Tools -> Board -> STM32 MCU based boards -> "Generic STM32F3 series" and then from Tools -> Board Select Part -> OLIMEXINO-STM32F3

4. Select it and double check the board options at the board selection tab, mainly the upload method. I use the DFU upload mode to upload via USB. This requires setting the board 
in DFU upload mode by pressing and holding button SW1, pressing and releasing SW2, then releasing SW1. Refer to the picture "board-selection-OLIMEXINO-STM32F3.jpg". Remember to put 
the board in DFU upload mode via the buttons else it won't upload.

5. Open of the examples to test. I test with Olimexino-STM32F3_GPIO. Compile and upload. Green LED should blink, pressing SW1 should turn on yellow LED.
