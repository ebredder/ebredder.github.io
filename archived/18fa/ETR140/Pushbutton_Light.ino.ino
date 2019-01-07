int inputButton = 2;
int ledPin = 13;

int inputState = 0;

void setup() {
  pinMode(inputButton, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  inputState = digitalRead(inputButton);

  if (inputButton == HIGH){
    digitalWrite(ledPin, HIGH);
  }
  digitalWrite(ledPin, LOW);
}
