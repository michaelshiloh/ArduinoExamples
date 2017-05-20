#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>

int lastShortBeeped = 0;
int lastLongBeeped = 0;
const int beepPin = 11;

void setup() {

  pinMode(beepPin, OUTPUT);

  Serial.begin(9600);

  Serial.println("DS1307RTC Read Test");
  Serial.println("-------------------");
}

void loop() {
  tmElements_t tm;

  if (RTC.read(tm)) {
    Serial.print("Ok, Time = ");
    print2digits(tm.Hour);
    Serial.write(':');
    print2digits(tm.Minute);
    Serial.write(':');
    print2digits(tm.Second);
    Serial.print(", Date (D/M/Y) = ");
    Serial.print(tm.Day);
    Serial.write('/');
    Serial.print(tm.Month);
    Serial.write('/');
    Serial.print(tmYearToCalendar(tm.Year));
    Serial.println();
  } else {
    if (RTC.chipPresent()) {
      Serial.println("The DS1307 is stopped.  Please run the SetTime");
      Serial.println("example to initialize the time and begin running.");
      Serial.println();
    } else {
      Serial.println("DS1307 read error!  Please check the circuitry.");
      Serial.println();
    }
    delay(9000);
  }

  if (tm.Second != lastShortBeeped) {
    shortBeep();
    lastShortBeeped = tm.Second;
  }

  if (tm.Second >= (lastLongBeeped + 10)) {
    longBeep();
    lastLongBeeped = tm.Second;
  }
}

void shortBeep() {
  digitalWrite(beepPin, HIGH);
  delay(10);
  digitalWrite(beepPin, LOW);
}
void longBeep() {
  digitalWrite(beepPin, HIGH);
  delay(100);
  digitalWrite(beepPin, LOW);
}

void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
  }
  Serial.print(number);
}
