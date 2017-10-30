 /*
 Example 36.2 - SPI bus device demo using a Microchip MCP4921 DAC [http://bit.ly/j3TSak]
 http://tronixstuff.com/tutorials > chapter 36 | CC by-sa-nc | John Boxall

 Modified 12/16/16 Michael Shiloh
 Created functions to fade and write
 added circuit connections


  Connections:
  Arduino pin 10 to DAC pin 2
  Arduino pin 11 to DAC pin 4
  Arduino pin 13 to DAC pin 3
  DAC pin 5 (LDAC/) tied to ground. This might be the cause of the jump.
 */
 
#include "SPI.h" // necessary library
//int del=20; // used for various delays
//word outputValue = 0; // a word is a 16-bit number
void setup()
{
  //set pin(s) to input and output
  pinMode(10, OUTPUT);
  SPI.begin(); // wake up the SPI bus.
  SPI.setBitOrder(MSBFIRST);
  Serial.begin(9600);
}
 
void loop()
{
 // high values are dim; low values are bright
  fadeDown(2775,2600, 20);
  delay(2000); 
  fadeUp(2600, 2775, 20);
  delay(2000);
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
    digitalWrite(10, LOW);
    data = highByte(outputValue);
    data = 0b00001111 & data;
    data = 0b00110000 | data;
    SPI.transfer(data);
    data = lowByte(outputValue);
    SPI.transfer(data);
    digitalWrite(10, HIGH);
}

