/*
 * Echoes on UART (returns next ASCII symbol).
 * Serial  (USB)
 * Serial1 - TX (D5) , RX (D9)
 * Serial2 - TX (D1) , RX (D0)
 * Serial3 - TX (D29), RX (D30) - EXT GPIO 7/8; UEXT 3/4
 */


void setup()
{
  Serial .begin (115200); Serial .println ("This is USB Serial!");
  Serial1.begin (115200); Serial1.println ("This is Serial1 (TX D5; RX D9)!");
  Serial2.begin (115200); Serial2.println ("This is Serial2 (TX D1; RX D0)!");
  Serial3.begin (115200); Serial3.println ("This is Serial3 (TX D29; RX D30) - EXT GPIO 7/8; UEXT 3/4");
}

void loop()
{
  if (Serial .available() > 0) Serial .print ((char)(Serial .read()+1));
  if (Serial1.available() > 0) Serial1.print ((char)(Serial1.read()+1));
  if (Serial2.available() > 0) Serial2.print ((char)(Serial2.read()+1));
  if (Serial3.available() > 0) Serial3.print ((char)(Serial3.read()+1));
}
