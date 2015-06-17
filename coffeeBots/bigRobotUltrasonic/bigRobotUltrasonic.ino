#include "Ultrasonic.h"

Ultrasonic leftUltrasonic(11,12); // (trigger pin, echo pin)
Ultrasonic rightUltrasonic(10,9); // (trigger pin, echo pin)


void setup() {
Serial.begin(9600);
Serial.print("testing...");  

pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
  
}

void loop()
{ 
  int leftRange = leftUltrasonic.Ranging(CM);
  int rightRange = rightUltrasonic.Ranging(CM);
  
  Serial.print("Left ");
  Serial.print(leftRange);
  Serial.print(" cm");
  
  Serial.print("\tRight ");
  Serial.print(rightRange);
  Serial.print(" cm");
  
  if (leftRange > rightRange)
  {
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    Serial.print("\tturning left");
  }
  else
  {
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    Serial.print("\tturning right");
  }
  
  Serial.println();
    
  delay(100);
}




