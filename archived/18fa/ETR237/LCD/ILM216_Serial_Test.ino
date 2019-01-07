#include <SoftwareSerial.h>

#define rxPin 255       
#define txPin 13         
#define inverted 1     

const char clearScreen[ ] = {12,0};
const char message[ ] = "Hello World!" ;

SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin, inverted);

void setup()  {
  digitalWrite(txPin, LOW);
  pinMode(txPin, OUTPUT);
  mySerial.begin(2400);
  mySerial.print(clearScreen);
  mySerial.print(message);  
}

void loop() {
//...
}
