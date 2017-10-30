import processing.serial.*;

Serial myPort;        // The serial port
int xPos = 1;         // horizontal position of the graph
float inByte = 0;

void setup () {
// set the window size:
size(400, 300);        

// List all the available serial ports
println(Serial.list());
// I know that the first port in the serial list on my mac
// is always my  Arduino, so I open Serial.list()[0].
// Open whatever port is the one you're using.
myPort = new Serial(this, Serial.list()[32], 9600);
// don't generate a serialEvent() unless you get a newline character:
myPort.bufferUntil('\n');
// set inital background:
background(0);
}
void draw () {

// draw the line:
stroke(127, 34, 255);
line(xPos, height, xPos, height - inByte);

// at the edge of the screen, go back to the beginning:
if (xPos >= width) {
xPos = 0;
background(0);
} else {
// increment the horizontal position:
xPos++;
}
}

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
