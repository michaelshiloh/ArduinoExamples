int leds[] = {4,6,10,11,12};

void setup() {
  // initialize the digital pin as an output.
 
  for(int i = 0;i<5;i++)
  {
    pinMode(leds[i], OUTPUT); 
  }
}

// the loop routine runs over and over again forever:
void loop() {
  
  for(int i = 1;i<5;i++)
  {
    digitalWrite(leds[i], HIGH);
    delay(300);
    digitalWrite(leds[i], LOW);
  }
  
  for(int i = 4;i>1;i--)
  {
    digitalWrite(leds[i], HIGH);
    delay(300);
    digitalWrite(leds[i], LOW);
  }
}

