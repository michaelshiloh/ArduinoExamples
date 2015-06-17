/*
This program is for testin carmen 
*/

// motors
const int rightMotor = 6;
const int leftMotor = 5;

// sensors
const int rightSensor = A1;
const int leftSensor = A0;

void setup()
{
  
  
  // Set the mode of the digital pins to outputs to drive the motors
  // (the analog inputs are automatically inputs and so don’t need to be set)
  pinMode( rightMotor, OUTPUT ); // motor
  pinMode( leftMotor , OUTPUT ); // motor
  Serial.begin(9600);

  // test right side
  digitalWrite(rightMotor, HIGH);
  
  // test left side
  digitalWrite(leftMotor, HIGH);
}

void loop()
{
  Serial.print(analogRead(rightSensor));
  Serial.print('\t');
  Serial.print(analogRead(leftSensor));
  Serial.println();
  delay(10);
 
}
