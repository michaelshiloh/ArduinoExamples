/*
 * Code for Veh-1X, the one wheeled experimental vehicle
 * 
 * Behavior:
 * When there is light, the motor goes on and the LED goes off
 * When there is darkness, the motor goes off and the LED goes on
 * 
 */


const int LDRPIN = A0;  // the Light Dependent Resistor
const int LEDPIN = 2;  // the LED
const int MOTORPIN = 3; // the motor
int threshold = 700;    // The threshold for determining whether
                        // it is light or dark 


void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(MOTORPIN, OUTPUT);
}

void loop() {
  int lightLevel = analogRead (LDRPIN); // read the light level

  if ( lightLevel >= threshold ) {   // Light level is above the threshold so ...
    digitalWrite(MOTORPIN, HIGH);    // motor goes on
    digitalWrite(LEDPIN, LOW);       // LED goes off
  } else {                           // Otherwise ...
    digitalWrite(MOTORPIN, LOW);    // motor goes off
    digitalWrite(LEDPIN, HIGH);       // LED goes on
  }
}
