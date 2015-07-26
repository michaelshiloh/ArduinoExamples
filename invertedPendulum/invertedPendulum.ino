
const int enable = 6;
const int control1 = A1;
const int control2 = A2;
const int potPin = A5;

 int potMin = 0;
 int potMax = 970;
 int setPoint;
const int minSpeed = 70;
const int scalingFactor = setPoint;

void setup() {
  // put your setup code here, to run once:

  pinMode( enable, OUTPUT);
  pinMode( control1, OUTPUT);
  pinMode( control2, OUTPUT);

  setPoint = analogRead(potPin);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  int potValue = analogRead(potPin);

  if (potValue < potMin ) {
    //potMin = potValue;
  }

  if (potValue > potMax ) {
    //potMax = potValue;
  }
  
  int error = setPoint - potValue;
 

//  if (potValue > 400 && potValue < 600) {
//    Serial.println("Off");
//    motorOff();
//  }

  if (error < 0) {
    int speed = map (abs(error), 0, potMax, minSpeed, 256);
    Serial.print(potValue);
    Serial.print("\t");
    Serial.print(error);
    Serial.print("\t");
    Serial.print(speed);
    Serial.print("\t");
    Serial.println("Left");
    motorLeft(speed);
  }

  if (error > 0) {
    int speed = map (abs(error), potMin, 0, minSpeed, 256);
    Serial.print(potValue);
    Serial.print("\t");
    Serial.print(error);
    Serial.print("\t");
    Serial.print(speed);
    Serial.print("\t");
    Serial.println("Right");
    motorRight(speed);
  }

}

void motorOff() {
  digitalWrite( enable, LOW);
  digitalWrite( control1, LOW);
  digitalWrite( control2, LOW);
}

void motorLeft(int speed) {
  analogWrite( enable, speed);
  digitalWrite( control1, LOW);
  digitalWrite( control2, HIGH);
}
void motorRight(int speed) {
  analogWrite( enable, speed);
  digitalWrite( control1, HIGH);
  digitalWrite( control2, LOW);
}


