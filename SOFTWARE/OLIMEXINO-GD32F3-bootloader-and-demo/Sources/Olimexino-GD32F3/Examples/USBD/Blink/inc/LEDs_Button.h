#ifndef	_LEDS_BUTTON_H
#define	_LEDS_BUTTON_H

// LED1
void LED1_Init();
void LED1_On();
void LED1_Off();
void LED1_Toggle();

// LED2
void LED2_Init();
void LED2_On();
void LED2_Off();
void LED2_Toggle();

// Button
void Button_Init();
int Button_Pressed();
int Button_Released();

void LEDs_Button_Init ();
void StartUp_Blink ();

#endif
