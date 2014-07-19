#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>

const int SERVER_PORT = 6666;

YunServer server(SERVER_PORT);
YunClient fromClient;
 
long OpenWRTBaud = 250000; // Baud rate for communicating with Linux side

void setup() {
  
  Serial.begin(57600);
  Serial.println("waiting for serial port");
  while(!Serial)
    ;
    
  Serial.println("Yun bidirectional client/server demonstration, SERVER side");
  
  Serial.print("Starting bridge ...");
  Bridge.begin();
  Serial.println("done");
  
  Serial1.begin(OpenWRTBaud); // open serial connection to Linino
  
  pinMode (13, OUTPUT);
  
  server.noListenOnLocalhost();

  Serial.print("Starting server ...");
  server.begin();
  Serial.println("done");
  
  printMyIPAddress();
}

void loop() {
  fromClient = server.accept();
  //Serial.print("Waiting for connection from client ");
  
  if(fromClient.connected()) {
    Serial.println("\nClient connected");
    
    while(fromClient.connected()) {
      if(fromClient.available()) {
        int received = fromClient.read();
        
        switch (received) {
           case 1: {
             Serial.print("One ");
             fromClient.print("One ");
             digitalWrite(13, HIGH);
             break;
           }
           case 2: {
             Serial.print("Two ");
             fromClient.print("Two ");
             digitalWrite(13, LOW);
             break;
           } 
           case 'x': {
             Serial.print("\nClient requested disconnection\n");
             fromClient.print("\nGoodbye from server\n");
             digitalWrite(13, LOW);
             fromClient.stop();
             break;
           } 
          default: {
             Serial.print("Unexpected message: ");
             Serial.println(received);
             //fromClient.write(received);
             break;
           }  
         }
      }
    }
    fromClient.stop();
  }
  else 
  {
    Serial.print('.');
  }
  delay(1000);
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

void printFromClient()
{
   while (fromClient.available() > 0)
   {      
     char c = fromClient.read();
     Serial.print(c);
   }
}
