/* bar graph
 * --------------
 *
 * 10/10/2016 - Michael Shiloh - initial creation
 * 
 */

int pinArray[] = {3, 4, 5, 6, 7};
int count = 0;
int timer = 60;
const int sensorPin = A0;
int minValue = 1023;
int maxValue = 0;

void setup(){
  for (count=0;count<5;count++) {
    pinMode(pinArray[count], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  
  if (sensorValue < minValue) {
    minValue = sensorValue;
  }
  
   if (sensorValue > maxValue) {
    maxValue = sensorValue;
  }
  
  int levelValue = map( sensorValue, minValue, maxValue, 0, 6);

  Serial.print(sensorValue);
  Serial.print('\t');
  Serial.print(levelValue);
  Serial.println();

  for (count=0;count<5;count++) {
    digitalWrite(pinArray[count], LOW);
  }

  if (levelValue > 1) {
   digitalWrite(pinArray[0], HIGH);
  } 
  if (levelValue > 2) {
   digitalWrite(pinArray[1], HIGH);
  } 
  if (levelValue > 3) {
   digitalWrite(pinArray[2], HIGH);
  } 
  if (levelValue > 4) {
   digitalWrite(pinArray[3], HIGH);
  }
  if (levelValue > 5) {
   digitalWrite(pinArray[4], HIGH);
  }
}

