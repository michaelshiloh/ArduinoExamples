// Buzz CoffeeBot by Judy Castro

const int leftMotor = 4;
const int rightMotor = 6;
const int rocket = 9;
const int buzzer = 12;
const int lightSensor = A0;
   
long beepInterval = 30000;
long previousMillis = -beepInterval;   

void setup()
{
  pinMode(leftMotor,OUTPUT);
  pinMode(rightMotor,OUTPUT);
  pinMode(rocket,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  analogWrite(rocket,  random(255));
  
  
  Serial.println(analogRead(lightSensor));
  if(analogRead(lightSensor) > 600)
  {
    digitalWrite(leftMotor, HIGH);
    digitalWrite(rightMotor, HIGH);
  }
  else
  {
    digitalWrite(leftMotor, HIGH);
    digitalWrite(rightMotor, LOW);
  }
  
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > beepInterval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   
    digitalWrite( buzzer, HIGH);
    delay(200);  
    digitalWrite( buzzer, LOW);
    delay(200);   
    digitalWrite( buzzer, HIGH);
    delay(200);  
    digitalWrite( buzzer, LOW);  
  }
}

