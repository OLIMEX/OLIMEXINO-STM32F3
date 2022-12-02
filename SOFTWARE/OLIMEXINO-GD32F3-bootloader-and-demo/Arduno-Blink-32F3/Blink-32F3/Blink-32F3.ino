/*
  Blink

  This demo is edited for Olimex OLIMEXINO-STM32F3 and OLIMEXINO-GD32F3.
  
  Turns one LED on for one second while the other LED is off, 
  then turns first LED off for one second while turning on the other LED, repeatedly.

  OLIMEXINO-STM32F3 (OLIMEXINO-GD32F3) has two LEDs, one placed on PA1, the other on PA5 (seen in the schematic)

  OLIMEXINO-STM32F3 (OLIMEXINO-GD32F3) might need to be put in bootloader mode before uploading examples:

  This is done by pressing and holding button SW1, then pressing and releasing button SW2, 
  then releasing button SW1.
  
  Remember to restart the board with SW1 after upload is done to leave serial bootloader mode.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// the setup function runs once when you the board is reset or when you power the board
void setup() {
  
  // initialize PA5(LED1) and PA1(LED2) as outputs.
  pinMode(PA5, OUTPUT);
  pinMode(PA1, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {
 
  digitalWrite(PA5, HIGH); // turn LED1 on (HIGH is the voltage level)
  digitalWrite(PA1, LOW);  // turn LED2 off by making the voltage LOW
  delay(1000);             // wait for a second
  digitalWrite(PA5, LOW);  // turn LED1 off by making the voltage LOW
  digitalWrite(PA1, HIGH); // turn LED2 on (HIGH is the voltage level) 
  delay(1000);             // wait for a second

}
