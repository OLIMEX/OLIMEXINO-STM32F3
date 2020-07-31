/*
   Toggle LED1 (Green) with interval ~1 sec
   LED2 (Yellow) changes state depending on the state of the button
*/

int Time, PrevTime = 0;

void setup()
{
  pinMode (BUTTON, INPUT);
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);
}

void loop()
{
  Time = millis ();
  if (Time >= PrevTime + 1000)
  {
    PrevTime = Time;
    digitalWrite (LED1, !digitalRead(LED1));
  }
  digitalWrite (LED2, digitalRead(BUTTON));
}
