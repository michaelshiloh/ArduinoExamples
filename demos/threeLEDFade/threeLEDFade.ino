/* example for microsoft build conference */


// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  
  digitalWrite(10, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(11, LOW);   // turn the LED on (HIGH is the voltage level)
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(9, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(10);
  }
  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(9, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(10);
  }
  
  digitalWrite(9, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(11, LOW);   // turn the LED on (HIGH is the voltage level)
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(10, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(10);
  }
  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(10, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(10);
  }
  
  digitalWrite(9, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(10, LOW);   // turn the LED on (HIGH is the voltage level)
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(11, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(10);
  }
  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(11, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(10);
  }
  
  digitalWrite(9, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(11, LOW);   // turn the LED on (HIGH is the voltage level)
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(10, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(10);
  }
  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(10, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(10);
  }
  
        
}
