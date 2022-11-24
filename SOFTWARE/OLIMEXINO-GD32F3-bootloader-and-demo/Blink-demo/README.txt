Blink demo binary for OLIMEXINO-GD32F3

The demo sets the two LEDs alternatively blinking and you can pause the blinking by pressing
the SW1 button.

The demo was made with IAR EW for ARM. 

You can download the binary to your board via the microUSB connector and USB cable. 
You need to install the DFU USB drivers and your OLIMEXINO-GD32F3 needs to have USB bootloader 
software programmed (it can be found in the "Bootloader" folder).

The drivers can be downloded from GD32's web site:

https://gd32mcu.com/en/download/0?kw=GD32F3

Expand "Tool & Software" and download "GD32 Dfu Drivers". In the same place you can also find 
"GD32 All in One Programmer" so make sure to download and install that one too.

After installing the drivers start "GD32 All in One Programmer" (if you haven't already).

Load the binary. Click connect. Start Address at 0x80008000. Be careful if you use the wrong 
address you can overwrite the USB bootloader!!!

Connect the board to the micro USB cable, then set the board in USB DFU mode - this is done 
by resetting the board with button SW2 and quickly pressing SW1 (while the two LEDs are blinking 
very quickly). You have approximately 2 seconds between reset and pressing SW1 before the 
board would proceed with the user code exection. If you miss the window to press the button, 
simply reset again. When successfully set in USB DFU mode it should be listed as "GD32 Device 
in DFU mode" in your operating system.

Click download.

Refer to the picture "2-USB-gd32-allinoneprogrammer.png".

