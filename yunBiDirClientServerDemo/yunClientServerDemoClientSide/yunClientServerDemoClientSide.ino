#include <Bridge.h>
#include <YunClient.h>

const int SERVER_PORT = 6666;
const byte SERVER_ADDR[] = { 192, 168, 1, 129 };

YunClient toServer;
long OpenWRTBaud = 250000; // Baud rate for communicating with Linux side

void setup() {
 
  Serial.begin(57600);
  Serial.println("waiting for serial port");
  while(!Serial)
    ;
  
  Serial.println("Yun bidirectional client/server demonstration, CLIENT side");
  
  Serial.print("Starting bridge ...");
  Bridge.begin();
  Serial.println("done");
  
  Serial1.begin(OpenWRTBaud); // open serial connection to Linino
  
  printMyIPAddress();
}

void loop() {
  int retval;
  
  //while (! (retval = toServer.connect("192.168.1.129", SERVER_PORT) ) )
  while (! (retval = toServer.connect(SERVER_ADDR, SERVER_PORT) ) )
  {
    Serial.print ("Failed to connect to server at ");
    Serial.print(SERVER_ADDR[0]);
    Serial.print('.');
    Serial.print(SERVER_ADDR[1]);
    Serial.print('.');
    Serial.print(SERVER_ADDR[2]);
    Serial.print('.');
    Serial.println(SERVER_ADDR[3]);
    delay(1000);
  }
  
  Serial.println ("Connected! Blink server's LED 20 times");
  
  for (int i = 0; i < 20; i++)
  {
    toServer.write(1);
    printFromServer();
    delay(500);
    toServer.write(2);
    printFromServer();
    delay(500);
  }
  
  Serial.println ("Done blinking. Tell server to disconnect");
  toServer.write('x');
  
  Serial.println ("Wait for server to disconnect, and print any message from server");
  while (toServer.connected() )
  {printFromServer();
    delay(10);
  }
  
  Serial.println ("Server disconnected, shutting down our end");
  toServer.stop();
  
  Serial.println ("Wait before repeating");
  delay(5000);
}

void printMyIPAddress()
{
   Process getMyIPAddr;  // initialize a new process
   
   Serial.print ("My IP address: ");
   getMyIPAddr.runShellCommand("ifconfig eth1 | grep addr | grep -v HWaddr | cut -c21-35");  // command you want to run
   while (getMyIPAddr.available() > 0)
   {      
     char c = getMyIPAddr.read();
     Serial.print(c);
   }
}

void printFromServer()
{
  while (toServer.available() > 0) {      
    char c = toServer.read();
    Serial.write(c);
  }
}
