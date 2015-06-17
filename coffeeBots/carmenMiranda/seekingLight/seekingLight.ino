/*
This program makes Carmen Miranda seek light 
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
}

void loop()
{
  
  Serial.print(analogRead(rightSensor));
  Serial.print('\t');
  Serial.print(analogRead(leftSensor));
  Serial.println();

  // Compare the two light sensors
  if ( analogRead( rightSensor ) > analogRead( leftSensor )  ) // If right light sensor has more light than the other ...
  {
    digitalWrite( rightMotor, LOW ); // turn right motor off ...
    digitalWrite( leftMotor, HIGH ); // and left motor on to turn right
  }
  
  else if ( analogRead( rightSensor ) < analogRead( leftSensor )  ) // If the other
  {
    digitalWrite( leftMotor, LOW ); // turn left motor off ...
    digitalWrite( rightMotor, HIGH ); // and right motor on to turn left
  }

  else if ( analogRead( rightSensor ) == analogRead( rightSensor )  ) // If they read the same value
  {
    digitalWrite( rightMotor, HIGH ); // turn both on 
    digitalWrite( leftMotor, HIGH ); // and go forward
  }
  
  delay (10);

}
