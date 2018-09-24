int motor = 13;

void setup() {                
  pinMode(motor, OUTPUT);     
}

void loop() {
  digitalWrite(motor, HIGH);   
  delay(3000);
  digitalWrite(motor, LOW);
  delay(1500);               
}
