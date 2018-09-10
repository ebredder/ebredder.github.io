#include <Servo.h> 

int servoPin = 9; // servo pin on microcontroller
int potPin = A0; // potentiometer pin 
int inPin = 2; 
int val = 0;

Servo servo;  // servo variable name
 
int angle = 0;   // servo position in degrees 
 
void setup() 
{ 
  servo.attach(servoPin); // tell the microcontroller which pin the servo is on
  pinMode(ledPin, OUTPUT);  // tell micro -> LED is an output
  pinMode(inPin, INPUT);    // pushbutton = input
} 
 
void loop() 
{ 
  val = digitalRead(inPin); 
  if (val == HIGH) {
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
    int reading = analogRead(potPin); // ADC, 10 bit value read from potentiometer
    int angle = reading/6; // dividing value to get something close to 180 degrees
    servo.write(angle); //write to specific angle!
} 
