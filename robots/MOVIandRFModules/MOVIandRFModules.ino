 
 // Based on LightSwitch demo from Audeme:
 
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
#include <VirtualWire.h> // use the VirtualWire library

#ifdef ARDUINO_ARCH_AVR 
#include <SoftwareSerial.h> // This is nice and flexible but only supported on AVR architecture, other boards need to use Serial1 
#endif

// By default, MOVI uses pins D10 and D11 for communication between shield and Arduino
const int transmit_pin = 12;
const int transmit_en_pin = 3;
const int led = 13;


const int stopCommand = 0;
const int leftCommand = 1;
const int rightCommand = 2;
const int forwardCommand = 3;

const int commandByte = 0;
const int speedByte = 1;

MOVI recognizer(true);            // Get a MOVI object, true enables serial monitor interface, rx and tx can be passed as parameters for alternate communication pins on AVR architecture
int vehicleSpeed = 200;
void setup()  
{
  pinMode(led, OUTPUT);    // Make LED port writeable
  digitalWrite(led, HIGH); // Blink LED.   
  delay(1);                   
  digitalWrite(led, LOW);  
  delay(1); 

  recognizer.init();      // Initialize MOVI (waits for it to boot)

  //*
  // Note: training can only be performed in setup(). 
  // The training functions are "lazy" and only do something if there are changes. 
  // They can be commented out to save memory and startup time once training has been performed.
  recognizer.callSign("Arduino"); // Train callsign Arduino (may take 20 seconds)
  recognizer.addSentence("Go forward"); // Add sentence 1
  recognizer.addSentence("Go Left");            // Add sentence 2
  recognizer.addSentence("Go Right");            // Add sentence 3
  recognizer.addSentence("Stop");            // Add sentence 4
  recognizer.train();                           // Train (may take 20seconds) 
  //*/

  //  recognizer.setThreshold(5);			// uncomment and set to a higher value (valid range 2-95) if you have a problems due to a noisy environment.
 
 // Initialise the Virtual Wire stuff
 // vw_set_tx_pin(transmit_pin);
  // vw_setup(2000);       // Bits per sec enabling this causes MOVI to not recognize sentences
  Serial.begin(4800);

}

void loop() // run over and over
{
   const int messageLength = 2;
  char message[messageLength]; // first byte is command, second byte is speed
  signed int res=recognizer.poll(); // Get result from MOVI, 0 denotes nothing happened, negative values denote events (see docs)
  //Serial.println(res);
  if (res==1) {                     // Sentence 1.
    message[commandByte] = forwardCommand;
    recognizer.say("Going forward"); // Speak a sentence
    message[speedByte] = vehicleSpeed;
  
  Serial.print((int) message[commandByte]);
  Serial.print( '\t' );
  Serial.println((byte) message[speedByte]);

//  vw_send((uint8_t *)message, messageLength);
//  vw_wait_tx(); // Wait until the whole message is gone
  } 
  if (res==4) {                    // Sentence 2 
    message[commandByte] = stopCommand;
    
    recognizer.say("Stopping"); // Speak a sentence
    message[speedByte] = vehicleSpeed;
  
  Serial.print((int) message[commandByte]);
  Serial.print( '\t' );
  Serial.println((byte) message[speedByte]);

//  vw_send((uint8_t *)message, messageLength);
//  vw_wait_tx(); // Wait until the whole message is gone
  }
  // Do more ...
}
