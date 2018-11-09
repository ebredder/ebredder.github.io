#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor dcMotor = AFMS.getMotor(1);

int sensorPin = A0; 

void setup()
{
  Serial.begin(9600);  
  AFMS.begin();
  myMotor->run(RELEASE);
    /*
    while (!Serial) {
      delay(100);
    }
    */
}
 
void loop()                     
{
 //getting the voltage reading from the temperature sensor
 int reading = analogRead(sensorPin);  
 
 // converting that reading to voltage, for 3.3v arduino use 3.3
 float voltage = reading * 5.0;
 voltage /= 1024.0; 
 
 // print out the voltage
 Serial.print(voltage); Serial.println(" volts");
 
 // now print out the temperature
 float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                               //to degrees ((voltage - 500mV) times 100)
 Serial.print(temperatureC); Serial.println(" degrees C");
 
 // now convert to Fahrenheit
 float temperatureF = (temperatureC * 9.0  myMotor->run(RELEASE);/ 5.0) + 32.0;
 Serial.print(temperatureF); Serial.println(" degrees F");
 
 delay(1000);                                     //waiting a second

 if (temperatureF >= 75){
  dcMotor->setSpeed(255);
  dcMotor->run(FORWARD);
 }
 else {
  dcMotor->setSpeed(150);
  dcmotor->run(FORWARD);
 }
}
