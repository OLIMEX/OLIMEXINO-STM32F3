USB bootloader binary for OLIMEXINO-GD32F3

You can download it to your board via USB-serial adapter attached 
to UEXT pins #2, #5, #6 and "GD32 All in One Programmer".

Alternatively you can use JTAG/SWD programmer using the 0.05" step
10-pin connector.

The drivers can be downloded from GD32's web site:

https://gd32mcu.com/en/download/0?kw=GD32F3

Expand "Tool & Software" you can find "GD32 All in One Programmer" 
make sure to download and install it.

Start Address at 0x80000000.

Refer to the "1-serial-gd32-allinoneprogrammer.png" picture.

If using the serial bootloader to download the USB bootloader,
remember to enter UART bootloader mode: press and hold button SW1,
press and release reset button SW2, release button SW1.

Instructions on how to use the newly downloaded USB DFU bootloder
can be found here:

https://github.com/OLIMEX/OLIMEXINO-STM32F3/blob/master/SOFTWARE/OLIMEXINO-GD32F3-bootloader-and-demo/Blink-demo/README.txt
