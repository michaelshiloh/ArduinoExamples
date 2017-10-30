/*
	Arduino code
*/
int zero = 0;
int one = 0;
int two = 0;

unsigned long previousMillis = 0;
long interval;

void setup(void)
{
  Serial.begin(9600);
  interval = random(10, 400);
}

void loop()
{
  if (Serial.available() > 0)
  {
    int inChar = Serial.read();
    if (inChar == '\n')
    {
      zero = Serial.parseInt();
      one = Serial.parseInt();
      two = Serial.parseInt();
    }
  }

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval)
  {
    Serial.print(zero);
    Serial.print(" ");
    Serial.print(one);
    Serial.print(" ");
    Serial.println(two);

    previousMillis = currentMillis;

    interval = random(10, 400);

  }
}


/*
   Processing code
*/

/*
 import processing.serial.*;
PFont font;

Serial myPort;                       // The serial port

String zero = "";
String one = "";
String two = "";

int index = 0;

String inString;  // Input string from serial port
String[] input = new String[32];
int lf = 10;      // ASCII linefeed


void setup() 
{
  size(600, 300);  // Stage size
  printArray(Serial.list());
  String portName = Serial.list()[32];
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil(lf);
}

void draw() 
{
  background(0);

  String send = index + " " + index + " " + index + '\n';
  myPort.write(send);

  if (inString != null) 
  {
    input = splitTokens(inString);

    if (input.length != 3) {
      println("wrong length " + input.length);
      return;
    }  
    zero = input[0];
    one = input[1];
    two = input[2];

    println("Return= " + zero + " " + one + " " + two);
    index++;
  }
}

void serialEvent(Serial myPort) 
{
  inString  = (myPort.readString());
}

int checksum(String inputString) {
  byte res = 0;
  for (int i=0; i<inputString.length(); i++) {
    res ^= byte(inputString.charAt(i));
  }
  return(res);
}

*/
