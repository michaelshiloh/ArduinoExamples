
const int enable = 6;
const int control1 = A1;
const int control2 = A2;
const int potPin = A5;

 int potMin;
 int potMax;
 int setPoint;
const int minSpeed = 200;
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
  
  Serial.print(potValue);
  Serial.print("\t");

  if (potValue < potMin ) {
    potMin = potValue;
  }

  if (potValue > potMax ) {
    potMax = potValue;
  }
  
  int error = setPoint - potValue;

  Serial.print(potMin);
  Serial.print("\t");
  Serial.print(potMax);
  Serial.print("\t");
  Serial.print(error);
  Serial.print("\t");
 
  if (error < 0) {
    int speed = map (abs(error), 0, potMax - setPoint, minSpeed, 256);
    Serial.print(speed);
    Serial.print("\t");
    Serial.println("Left");
    motorLeft(speed);
  }

  if (error > 0) {
    int speed = map (abs(error), 0, setPoint - potMin, minSpeed, 256);
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


