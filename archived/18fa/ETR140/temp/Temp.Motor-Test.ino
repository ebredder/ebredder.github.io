int tmp = A0;
int motorPin = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(motorPin, OUTPUT); 
  Serial.begin(9600);    
  
}

// the loop routine runs over and over again forever:
void loop() {
  int reading = analogRead(tmp);

  float voltage = reading * 3.3;
  voltage /= 1024.0;
  Serial.print(voltage); Serial.println(" V");

  float tmpC = voltage * 100;
  Serial.print(tmpC); Serial.println(" C");

  if (tmpC >= 30){
    analogWrite(motorPin, 200);   // turn the LED on (HIGH is the voltage level)
    delay(1000);               // wait for a second
  }
  else {
  digitalWrite(motorPin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
}
