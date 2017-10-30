/*
 * How to read 4 switches,
 * treat each switch as a binary bit,
 * make a number out of those bits,
 * and take different actions depending on that number
 */




void setup() {
  Serial.begin(9600);

   byte bits[] = {0, 1, 0, 1};
   byte value = 
              ((bits[0]?1:0) << 3) |
              ((bits[1]?1:0) << 2) |
              ((bits[2]?1:0) << 1) |
              ((bits[3]?1:0) << 0) ;

  Serial.print(bits[0]);
  Serial.print(bits[1]);
  Serial.print(bits[2]);
  Serial.println(bits[3]);

 Serial.print((bits[0]?1:0) << 0);
 Serial.print((bits[1]?1:0) << 1);
 Serial.print((bits[2]?1:0) << 2);
 Serial.println((bits[3]?1:0) << 3);

  
  Serial.println(value);

  // four switches have 16 possible values: zero through 15
  
  if (value == 0)
  {
    // do stuff
  } else if (value == 1)
  {
    // do other stuff
  } else if (value == 2)

  // ....
   
  } else if (value == 15) 
  {
    // do other stuff
  } else



}

void loop() {

}
