int greenLED = 3;
int redLED = 4;
int motorPin = 6;
int brake = 2;
int potPin = A0;

int brakeVal = 0;

void setup(){
	pinMode(greenLED, OUTPUT);
	pinMode(redLED, OUTPUT);
	pinMode(motorPin, OUTPUT);
	pinMode(brake, INPUT);

void  loop(){
	brakeVal = digitalRead(brake);
	if (brakeVal == HIGH){
		digitalWrite(motorPin, LOW);
		digitalWrite(redLED, HIGH);
		digitalWrite(greenLED, LOW);
	}
	
	int potRead = analogRead(potPin);
	int speedVal = potRead / 4;	
	
	analogWrite(motorPin, speedVal);
	digitalWrite(greenLED, HIGH);
	digitalWrite(redLED, LOW);
}