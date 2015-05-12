
void setup() {
  // initialize the digital pin as an output.
 
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);  
  pinMode(12, OUTPUT); 
  pinMode(8, OUTPUT); 
}

// the loop routine runs over and over again forever:
void loop() {
 
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  delay(300);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  delay(300);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delay(300);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  
  int lightLevel = analogRead(A0);
  
  if(lightLevel < 500)
  {
    tone(8,440,300);
    delay(300);
  }
}

