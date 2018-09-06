#include <Servo.h> 

int servoPin = 9; // servo pin on microcontroller
 
Servo servo;  // servo variable name
 
int angle = 0;   // servo position in degrees 
 
void setup() 
{ 
  servo.attach(servoPin); // tell the microcontroller which pin the servo is on
} 
 
 
void loop() 
{ 
  // scan from 0 to 180 degrees
  for(angle = 0; angle < 180; angle++)  
  {                                  
    servo.write(angle); // PWM write based on the library              
    delay(15);                   
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 0; angle--)    
  {                                
    servo.write(angle);           
    delay(15);       
  } 
} 
