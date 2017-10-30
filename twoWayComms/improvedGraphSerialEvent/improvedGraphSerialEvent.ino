/*
Replacement serialEvent() for that in the built-in example

	Communications -> Graph 

which does more thorough error checking and discards invalid data
It seems to capture most (all?) of the reasons for the float() conversion
to return NaN

Original code written 
Created 20 Apr 2005 by Tom Igoe
Updated 24 Nov 2015 by Tom Igoe

Change log for this replacement:

	October 30, 2017 - Michael Shiloh - check for non-numeric and invalid data

This example code is in the public domain.

*/


void serialEvent (Serial myPort) {
  // get the ASCII string:
  String inString = myPort.readStringUntil('\n');

  print(inString);

  // trim off any whitespace
  inString = trim(inString);

  // Discard null strings
  if (inString == null) {
    println("discarding null string after trimming");
    return;
  }

  // Discard strings that have fewer than 1 character
  if (inString.length() < 1) {
    println("discarding strings shorter than 1");
    return;
  }

  // Discard strings that have any non-numeric characters
  for (int i=0; i < inString.length(); i++) {
    if ( (inString.charAt(i) < '0') || (inString.charAt(i) > '9') ) {
      println("discarding non-numeric character");
      return;
    }
  }

  // convert the string to a float
  float temp = float(inString); 

  // Values from Arduino analogRead() can only be
  // between 0 and 1023
  if ( (temp > 1023) || (temp < 0) ) {
    println("discarding unreasonable value = " + temp);
    return;
  }

  // map to the screen height
  inByte = map(temp, 0, 1023, 0, height);
}

