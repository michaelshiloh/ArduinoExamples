/* Control a 555 oscillator attached to a Microchip 4131 digital potentiometer
 * Based on http://www.learningaboutelectronics.com/Articles/MCP4131-digital-potentiometer-circuit.php
 *
 * Change log 
 * 10/10/16 - Initial file -  Michael Shiloh
 * 
 */

int values[] = {10,20,30,90,50,128, 100, 80};
int numValues = 8;


#include <SPI.h>

byte address = 0x00;
int CS = 10;

void setup()
{
  pinMode (CS, OUTPUT);
  SPI.begin();
}

void loop()
{

  for (int i = 0; i <= numValues; i++) {
    digitalPotWrite(values[i]);
    delay(1000);
  }


  
//  for (int i = 0; i <= 128; i++)
//  {
//    digitalPotWrite(i);
//    delay(10);
//  }
//  delay(500);
//  for (int i = 128; i >= 0; i--)
//  {
//    digitalPotWrite(i);
//    delay(10);
//  }
}

int digitalPotWrite(int value)
{
  digitalWrite(CS, LOW);
  SPI.transfer(address);
  SPI.transfer(value);
  digitalWrite(CS, HIGH);
}

