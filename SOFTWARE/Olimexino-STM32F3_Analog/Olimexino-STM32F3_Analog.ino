#define SERIAL  Serial

int Time, PrevTime=0;

void setup()
{
  SERIAL.begin (115200);
  SERIAL.println ("Welcome!");
}

void loop()
{
  Time = millis ();
  if (Time >= PrevTime + 1000)
  {
    PrevTime = Time;
    SERIAL.print("\f");
    SERIAL.print("PC0 (D15/A0) = "); SERIAL.println (analogRead(A0));
    SERIAL.print("PC1 (D16/A1) = "); SERIAL.println (analogRead(A1));
    SERIAL.print("PC2 (D17/A2) = "); SERIAL.println (analogRead(A2));
    SERIAL.print("PC3 (D18/A3) = "); SERIAL.println (analogRead(A3));
    SERIAL.print("PC4 (D19/A4) = "); SERIAL.println (analogRead(A4));
    SERIAL.print("PC5 (D20/A5) = "); SERIAL.println (analogRead(A5));
  }
}
