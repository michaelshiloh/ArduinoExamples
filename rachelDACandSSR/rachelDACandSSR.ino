/*


  Created 12/16/16 Michael Shiloh
  Rachel's project Fall 2016 Interface
  Based on
  Example 36.2 - SPI bus device demo using a Microchip MCP4921 DAC [http://bit.ly/j3TSak]
  http://tronixstuff.com/tutorials > chapter 36 | CC by-sa-nc | John Boxall


  Connections:
  Arduino pin 10 to DAC pin 2
  Arduino pin 11 to DAC pin 4
  Arduino pin 13 to DAC pin 3
  DAC pin 5 (LDAC/) tied to ground. This might be the cause of the jump.

  Arduino pin 2 to SSR
  Arduino pin 4 to Button

  Code:
  Wait for button press
  Turn on SSR
  Take 4 seconds to fade up
  Stay at full brightness for 1 second
  Take 4 seconds to fade down
*/

#include "SPI.h" // necessary library

const int buttonPin = 4;
const int SSRPin = 2;
const int DAC_CS = 10; // DAC Chip Select (active low)

const int fadeValueOff = 2850; // high values are dim; low values are bright
const int fadeValueMaxBrightness = 2600;

void setup()
{
  //DAC CS pin
  pinMode(DAC_CS, OUTPUT);
  SPI.begin(); // wake up the SPI bus.
  SPI.setBitOrder(MSBFIRST);

  // other pins
  pinMode (buttonPin, INPUT);
  pinMode (SSRPin, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  Serial.println("waiting for button");
  // wait for button, which is active low
  while (digitalRead(buttonPin) == 0) {
    // do nothing, wait for the button to be pressed
    delay(1);
  }
  // Finally the button is pressed!
  Serial.println("button pressed");

  // Calculate the pause at each step for a 4 second fade up
  // high values are dim; low values are bright
  int pause = int(4000.0 / (fadeValueOff - fadeValueMaxBrightness));
  Serial.print("pause is ");
  Serial.println(pause);

  // cycle takes 9 seconds; repeat 7 times for 1 minute (7 * 9 = 63)

  for (int i = 9; i > 0; i--)
  {
    // Turn on valve and fade light up
    digitalWrite(SSRPin, HIGH);
    // high values are dim; low values are bright
    fadeDown(fadeValueOff, fadeValueMaxBrightness, pause);

    // hold breath
    delay(1000);

    // Turn off valve and fade light down
    digitalWrite(SSRPin, LOW);
    fadeUp(fadeValueMaxBrightness, fadeValueOff, pause);
  }
}

void fadeUp(word minValue, word maxValue, int pause)
{
  for (word i = minValue; i <= maxValue; i++)
  {
    mcp4921DACWrite(i);
    delay(pause);
  }
}

void fadeDown(word maxValue, word minValue, int pause)
{
  for (word i = maxValue; i >= minValue; i--)
  {
    mcp4921DACWrite(i);
    delay(pause);
  }
}

void mcp4921DACWrite(word outputValue) {
  byte data = 0; // and a byte is an 8-bit number

  Serial.println(outputValue);
  digitalWrite(DAC_CS, LOW);
  data = highByte(outputValue);
  data = 0b00001111 & data;
  data = 0b00110000 | data;
  SPI.transfer(data);
  data = lowByte(outputValue);
  SPI.transfer(data);
  digitalWrite(DAC_CS, HIGH);
}

