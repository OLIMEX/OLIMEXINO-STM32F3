/*
Demo sketch for Olimexino-STM32F3 that combines
1) The UEXT example for MOD-LCD3310
2) The default SD example "CardInfo" (written by Limor Fried and modified by Tom Igoe)

The circuit:
 SD card attached to SPI bus as follows:
 ** MOSI - pin 34 on Olimexino-STM32F3
 ** MISO - pin 33 on Olimexino-STM32F3
 ** CLK  - pin 32 on Olimexino-STM32F3
 ** CS   - pin 25 on Olimexino-STM32F3
IMOPRTANT NOTE: In order to work SD card SPI_2 should be defined in SPI library

 MOD-LCD3310 should be attached to the UEXT.

On the Serial monitor should be printed status of the SD card
and on the dispay should be displayed the following text:
+---------------+
|*** OLIMEX *** |
|   OLIMEXINO   |
|   STM32F3 +   |
|  MOD-LCD3310  |
|   using SPI   |
|   interface   |
+---------------+
*/

// +++ MOD-LCD3310 +++
#include "lcd3310_SPI.h"
void MOD_LCD3310 ()
{
  LCDInit();
  LCDContrast(0x70);
  LCDStr(0, (unsigned char *)"*** OLIMEX ***", 1);
  LCDStr(1, (unsigned char *)"   OLIMEXINO  ", 0);
  LCDStr(2, (unsigned char *)"   STM32F3 +  ", 1);
  LCDStr(3, (unsigned char *)"  MOD-LCD3310 ", 0);
  LCDStr(4, (unsigned char *)"   using SPI  ", 1);
  LCDStr(5, (unsigned char *)"   interface  ", 0);
}
// --- MOD-LCD3310 ---

// include the SD library:
#include <SPI.h>
#include <SD.h>


// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;

// change this to match your SD shield or module;
// Arduino Ethernet shield: pin 4
// Adafruit SD shields and modules: pin 10
// Sparkfun SD shield: pin 8
// MKRZero SD: SDCARD_SS_PIN
const int chipSelect = 25;

void setup()
{
  MOD_LCD3310 ();
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial); // wait for serial port to connect. Needed for native USB port only

  Serial.print("\nInitializing SD card...");

  // we'll use the initialization code from the utility libraries
  // since we're just testing if the card is working!
  if (!card.init(SPI_HALF_SPEED, chipSelect))
  {
    Serial.println("initialization failed. Things to check:");
    Serial.println("* is a card inserted?");
    Serial.println("* is your wiring correct?");
    Serial.println("* did you change the chipSelect pin to match your shield or module?");
    while (1);
  }
  else
  {
    Serial.println("Wiring is correct and a card is present.");
  }

  // print the type of card
  Serial.println();
  Serial.print("Card type:         ");
  switch (card.type())
  {
    case SD_CARD_TYPE_SD1:
      Serial.println("SD1");
      break;
    case SD_CARD_TYPE_SD2:
      Serial.println("SD2");
      break;
    case SD_CARD_TYPE_SDHC:
      Serial.println("SDHC");
      break;
    default:
      Serial.println("Unknown");
  }

  // Now we will try to open the 'volume'/'partition' - it should be FAT16 or FAT32
  if (!volume.init(card))
  {
    Serial.println("Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
    while (1);
  }

  Serial.print("Clusters:          ");
  Serial.println(volume.clusterCount());
  Serial.print("Blocks x Cluster:  ");
  Serial.println(volume.blocksPerCluster());

  Serial.print("Total Blocks:      ");
  Serial.println(volume.blocksPerCluster() * volume.clusterCount());
  Serial.println();

  // print the type and size of the first FAT-type volume
  uint32_t volumesize;
  Serial.print("Volume type is:    FAT");
  Serial.println(volume.fatType(), DEC);

  volumesize = volume.blocksPerCluster();    // clusters are collections of blocks
  volumesize *= volume.clusterCount();       // we'll have a lot of clusters
  volumesize /= 2;                           // SD card blocks are always 512 bytes (2 blocks are 1KB)
  Serial.print("Volume size (Kb):  ");
  Serial.println(volumesize);
  Serial.print("Volume size (Mb):  ");
  volumesize /= 1024;
  Serial.println(volumesize);
  Serial.print("Volume size (Gb):  ");
  Serial.println((float)volumesize / 1024.0);

  Serial.println("\nFiles found on the card (name, date and size in bytes): ");
  root.openRoot(volume);

  // list all files in the card with date and size
  root.ls(LS_R | LS_DATE | LS_SIZE);
}

void loop(void)
{
}
