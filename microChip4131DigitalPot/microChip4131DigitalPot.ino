/*
   sketch to fade down and up an LED attached to a MicroChip 4131 digital potentiometer

   Based on the tutorial at
   http://www.learningaboutelectronics.com/Articles/MCP4131-digital-potentiometer-circuit.php

   Datasheet for the digital potentiometer is at
   http://ww1.microchip.com/downloads/en/DeviceDoc/22060b.pdf
*/


#include <SPI.h>

byte address = 0x00;
int CS = 10;

void setup()
{
  pinMode (CS, OUTPUT);
  SPI.begin();
  Serial.begin(9600);
}

void loop()
{
    fadeUp(7, 17, 200);
    delay(1000);
    fadeDown(17, 7, 200);
    delay(1000);
  //digitalPotWrite(map(analogRead(A0), 0, 1023, 0, 128));
}

void fadeUp(int minValue, int maxValue, int pause)
{
  for (int i = minValue; i <= maxValue; i++)
  {
    digitalPotWrite(i);
    delay(pause);
  }
}

void fadeDown(int maxValue, int minValue, int pause)
{
  for (int i = maxValue; i >= minValue; i--)
  {
    digitalPotWrite(i);
    delay(pause);
  }
}

int digitalPotWrite(int value)
{
  Serial.println(value);
  digitalWrite(CS, LOW);
  SPI.transfer(address);
  SPI.transfer(value);
  digitalWrite(CS, HIGH);
}
