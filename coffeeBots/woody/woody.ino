/*
 * Woody CoffeeBot by Judy Castro
 */

// Motors are on digital pins 4 and 6
const int leftMotor = 4;
const int rightMotor = 6;

void setup()
{
  pinMode(leftMotor,OUTPUT);
  pinMode(rightMotor,OUTPUT);
  Serial.begin(9600);
}
int state;
void loop()
{
  // Light sensors are on analog pins 0 and 2
  if(analogRead(0) > analogRead(2))
  {
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, HIGH);
  }
  else if(analogRead(0) < analogRead(2))
  {
    digitalWrite(leftMotor, HIGH);
    digitalWrite(rightMotor, LOW);
  }
  else
  /* if light is equal, do a figure 8 in place */
  {
    digitalWrite(leftMotor, HIGH);
    digitalWrite(rightMotor, LOW);
    delay(3000);
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, HIGH);
    delay(3000);
  }
}
