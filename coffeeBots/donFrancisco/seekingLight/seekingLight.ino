/*
This program makes Don Francisco seek light 
*/

// motors
const int rightMotor = 6;
const int leftMotor = 5;

// LEDs
const int rightLED = 8;
const int leftLED = 9;

// sensors
const int rightSensor = A1;
const int leftSensor = A0;

void setup()
{
	// Set the mode of the digital pins to outputs to drive the motors
	// (the analog inputs are automatically inputs and so don’t need to be set)
	pinMode( rightMotor, OUTPUT ); // motor
	pinMode( leftMotor , OUTPUT ); // motor
	pinMode( rightLED , OUTPUT ); // LED
	pinMode( leftLED, OUTPUT ); // LED
	Serial.begin(9600);
}

void loop()
{

  // Compare the two light sensors
  if ( analogRead( rightSensor ) > analogRead( leftSensor )  ) // If right light sensor has more light than the other ...
  {
    digitalWrite( rightMotor, LOW ); // turn right motor off ...
    digitalWrite( leftMotor, HIGH ); // and left motor on to turn right
    digitalWrite( rightLED, HIGH ); // indicate turning right
    digitalWrite( leftLED, LOW );
  }
  
  else if ( analogRead( rightSensor ) < analogRead( leftSensor )  ) // If the other
  {
    digitalWrite( leftMotor, LOW ); // turn left motor off ...
    digitalWrite( rightMotor, HIGH ); // and right motor on to turn left
    digitalWrite( rightLED, LOW ); // indicate turning left
    digitalWrite( leftLED, HIGH );
  }

else if ( analogRead( rightSensor ) == analogRead( rightSensor )  ) // If they read the same value
	{
		digitalWrite( rightMotor, HIGH ); // turn both on 
		digitalWrite( leftMotor, HIGH ); // and go forward
		digitalWrite( rightLED, HIGH ); // turn on both LEDs
		digitalWrite( leftLED, HIGH );
	}

}
