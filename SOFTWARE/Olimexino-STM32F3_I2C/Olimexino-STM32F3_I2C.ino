/*
 * Simple I2C demo using MOD-BME280 module
 * This demo is based on Adafruit library example that prints 
 * the output values of the measurements every second.
 * Requires "Adafruit BME280" library
 */

#define SERIAL  Serial

int Time, PrevTime=0;

#include <Wire.h>
#include "Adafruit_BME280.h"  // To install it go to Sketch --> Include Library --> Manage libraries --> Search for "Adafruit BME280"
#include <Adafruit_Sensor.h>  // To install it download from here: https://github.com/adafruit/Adafruit_Sensor then Sketch --> Include Library --> Add .zip library
Adafruit_BME280 bme; // I2C
#define SEALEVELPRESSURE_HPA (1013.25)  // required for MOD-BME280

void printValues()
{
  SERIAL.print ("\f");

  SERIAL.print("Temperature = ");
  SERIAL.print(bme.readTemperature());
  SERIAL.println(" *C");

  SERIAL.print("Pressure = ");
  SERIAL.print(bme.readPressure() / 100.0F);
  SERIAL.println(" hPa");

  SERIAL.print("Approx. Altitude = ");
  SERIAL.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  SERIAL.println(" m");

  SERIAL.print("Humidity = ");
  SERIAL.print(bme.readHumidity());
  SERIAL.println(" %");
}

void setup()
{
  SERIAL.begin (115200);
  SERIAL.println ("Welcome!");

  Wire.begin ();
  bme.begin(0x77);
}

void loop()
{
  Time = millis ();
  if (Time >= PrevTime + 1000)
  {
    PrevTime = Time;
    printValues (); // MOD-BME280
  }
}
