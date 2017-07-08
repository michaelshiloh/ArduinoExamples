/*
compare the two light sensors and move the robot towards the light
*/
 
// 
int motor1 = 6; // motor, not led
int motor2 = 5;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(motor1, OUTPUT);     
  pinMode(motor2, OUTPUT);     
  
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  /*
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(motor2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  
  
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(motor2, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
  */
  
  int lightSensor1 = analogRead(A0);
  int lightSensor2 = analogRead(A1);
  
  if(lightSensor1 > lightSensor2){
    digitalWrite(motor1, HIGH);
  }
  else if (lightSensor1 < lightSensor2){
    digitalWrite(motor1, LOW);
  }
  
  Serial.println(analogRead(A1));
}
