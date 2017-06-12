const int LEFT_IN_1 = 13;
const int LEFT_IN_2 = 12;
const int LEFT_ENABLE = 3;

const int RIGHT_IN_1 = 11;
const int RIGHT_IN_2 = 10;
const int RIGHT_ENABLE = 5;

const int FORWARD_ = 0;
const int REVERSE_ = 1;
const int STOP_ = 2;

void setup() {
  pinMode(LEFT_IN_1, OUTPUT);
  pinMode(LEFT_IN_2, OUTPUT);
  pinMode(LEFT_ENABLE, OUTPUT);

  pinMode(RIGHT_IN_1, OUTPUT);
  pinMode(RIGHT_IN_2, OUTPUT);
  pinMode(RIGHT_ENABLE, OUTPUT);
}

void loop() {
  leftForward();
  controlRight(FORWARD_);
  delay (5000);
  controlRight(REVERSE_);
  delay (1000);
  controlRight(FORWARD_);
  leftReverse();
  delay (5000);
  controlRight(STOP_);
  delay (1000);
}

void leftForward() {
  digitalWrite(LEFT_IN_1, HIGH);
  digitalWrite(LEFT_IN_2, LOW);
  digitalWrite(LEFT_ENABLE, HIGH);
}
void leftReverse() {
  digitalWrite(LEFT_IN_1, LOW);
  digitalWrite(LEFT_IN_2, HIGH);
  digitalWrite(LEFT_ENABLE, HIGH);
}

void controlRight(int dir) {
  if (dir == FORWARD_ ) {
    digitalWrite(RIGHT_IN_1, HIGH);
    digitalWrite(RIGHT_IN_2, LOW);
    digitalWrite(RIGHT_ENABLE, HIGH);
  } else if (dir == REVERSE_ ){
    digitalWrite(RIGHT_IN_1, LOW);
    digitalWrite(RIGHT_IN_2, HIGH);
    digitalWrite(RIGHT_ENABLE, HIGH);
  } else {
    digitalWrite(RIGHT_ENABLE, LOW);
  }
  
}


