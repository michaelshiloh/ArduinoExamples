/*
This program makes your robot either seek light or avoid light, depending on how it is wired up.
Try this program first, and then start modifying it to give your robot the personality you desire.
Shine a flashlight, or hold your hand over a light sensor, to change the behavior.
Other examples and suggestions are on our website.An LED is connected to pin 9; whenever the sensors measure unequal brightness this LED is turned on
*/
void setup()
{
// Set the mode of the digital pins to outputs to drive the motors
// (the analog inputs are automatically inputs and so don’t need to be set)
pinMode( 3, OUTPUT ); // motor
pinMode( 5, OUTPUT ); // motor
pinMode( 9, OUTPUT ); // LED
}

void loop()
{
// Compare the two light sensors
if ( analogRead( 0 ) > analogRead( 2 )  ) // If one light sensor has more light than the other ...
{
digitalWrite( 3, LOW ); // turn this motor off ...
digitalWrite( 5, HIGH ); // and this motor on to turn in one direction
digitalWrite( 9, LOW ); // turn off the LED
}

if ( analogRead( 0 ) < analogRead( 2 )  ) // If the other
{
digitalWrite( 3, HIGH ); // turn this motor on
digitalWrite( 5, LOW ); // and this motor off to turn in the other direction
digitalWrite( 9, LOW ); // turn off the LED
}

if ( analogRead( 0 ) == analogRead( 2 )  ) // If they read the same value
{
digitalWrite( 3, HIGH ); // turn this motor on
digitalWrite( 5, HIGH ); // and this motor off to turn in the other direction
digitalWrite( 9, HIGH ); // turn on the LED
}
}
