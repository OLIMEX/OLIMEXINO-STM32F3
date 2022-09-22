#include "LEDs_Button.h"
#include "gd32f303e_eval.h"
#include "systick.h"

// LED1
void LED1_Init()
{
  gd_eval_led_init (LED1);
}

void LED1_On()
{
  gd_eval_led_on (LED1);
}

void LED1_Off()
{
  gd_eval_led_off (LED1);
}

void LED1_Toggle()
{
  gd_eval_led_toggle (LED1);
}

// LED2
void LED2_Init()
{
  gd_eval_led_init (LED2);
}

void LED2_On()
{
  gd_eval_led_on (LED2);
}

void LED2_Off()
{
  gd_eval_led_off (LED2);
}

void LED2_Toggle()
{
  gd_eval_led_toggle (LED2);
}

// Button
void Button_Init()
{
  gd_eval_key_init(BUTTON, KEY_MODE_GPIO);
}

int Button_Pressed()
{
  return gd_eval_key_state_get (BUTTON);
}

int Button_Released()
{
  return !gd_eval_key_state_get (BUTTON);
}

void LEDs_Button_Init ()
{
  LED1_Init ();
  LED2_Init ();
  Button_Init ();
}

void StartUp_Blink ()
{
  LEDs_Button_Init ();
  LED1_On ();
  LED2_Off();
  for (int i=10; i; i--)
  {
    LED1_Toggle ();
    LED2_Toggle ();
    delay_1ms (50);
  }
}
