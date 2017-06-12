 
 /* Based on LightSwitch demo from Audeme:
 *
 /****************************************************************************
 * This is an example for the use of Audeme's MOVI(tm) Voice Control Shield *
 * ----> http://www.audeme.com/MOVI/                                        *
 * This code is inspired and maintained by Audeme but open to change        *
 * and organic development on GITHUB:                                       *
 * ----> https://github.com/audeme/MOVIArduinoAPI                           *
 * Written by Gerald Friedland for Audeme LLC.                              *
 * Contact: fractor@audeme.com                                              *
 * BSD license, all text above must be included in any redistribution.      *
 ****************************************************************************
 *
 * 
 * IMPORTANT: Always use external power supply with MOVI. 
 * 
 
 */
#include "MOVIShield.h"     // Include MOVI library, needs to be *before* the next #include

#ifdef ARDUINO_ARCH_AVR 
#include <SoftwareSerial.h> // This is nice and flexible but only supported on AVR architecture, other boards need to use Serial1 
#endif

// Get a MOVI object
// True enables serial monitor interface
// rx and tx can be passed as parameters for alternate communication pins on
// AVR architecture. 
// By default, MOVI uses Arduino pins 10 and 11 for serial communication
// between the MOVI shield 
// and the Arduino board
MOVI recognizer(true);

// Pin usage

// As mentioned above, MOVI uses Arduino pins 10 and 11 for serial communication
const int MegaMotorEnable = 12;
const int MegaMotorPWMLeft = 6; // PWMA from pin D6 – Timer0 PWM0A
const int MegaMotorPWMRight = 5; // PWMB from pin D5 – Timer0 PWM0B 


void setup()  
{
  pinMode(MegaMotorEnable, OUTPUT);
  pinMode(MegaMotorPWMLeft, OUTPUT);
  pinMode(MegaMotorPWMRight, OUTPUT);
  
  recognizer.init();      // Initialize MOVI (waits for it to boot)

  //*
  // Note: training can only be performed in setup(). 
  // The training functions are "lazy" and only do something if there are changes. 
  // They can be commented out to save memory and startup time once training has been performed.
  recognizer.callSign("Arduino"); // Train callsign Arduino (may take 20 seconds)
  recognizer.addSentence("Go forward"); // Add sentence 1
  recognizer.addSentence("Turn right"); // Add sentence 2
  recognizer.addSentence("Turn left");  // Add sentence 3
  recognizer.addSentence("Stop");       // Add sentence 4
  recognizer.train();                           // Train (may take 20seconds) 
  //*/

  //  recognizer.setThreshold(5);			// uncomment and set to a higher value (valid range 2-95) if you have a problems due to a noisy environment.
}

void loop() // run over and over
{
  signed int res=recognizer.poll(); // Get result from MOVI, 0 denotes nothing happened, negative values denote events (see docs)
  if (res==1) {                     // Go forward
    digitalWrite(MegaMotorEnable, HIGH);
    digitalWrite(MegaMotorPWMLeft, HIGH);
    digitalWrite(MegaMotorPWMRight, HIGH);
    recognizer.say("Going forward"); // Speak a sentence
  } 
  if (res==2) {                    // Turn right 
    digitalWrite(MegaMotorEnable, HIGH);
    digitalWrite(MegaMotorPWMLeft, HIGH);
    digitalWrite(MegaMotorPWMRight, LOW);
    recognizer.say("Turning right"); // Speak a sentence
  }
  if (res==3) {                    // Turn left 
    digitalWrite(MegaMotorEnable, HIGH);
    digitalWrite(MegaMotorPWMLeft, LOW);
    digitalWrite(MegaMotorPWMRight, HIGH);
    recognizer.say("Turning left"); // Speak a sentence
  }
  if (res==4) {                    // Stop 
    digitalWrite(MegaMotorEnable, LOW);
    recognizer.say("Stopping"); // Speak a sentence
  }
}
