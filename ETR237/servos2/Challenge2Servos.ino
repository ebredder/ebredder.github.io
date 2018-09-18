#include <Servo.h>

int led = 13;
int potPin1 = A0;
int potPin2 = A1;
int pb1 = 2;
int pb2 = 3;
int servoPin1 = 9;
int servoPin2 = 10;

Servo rudder;
Servo servo2;

pb1Val = 0;
pb2Val = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pb1, INPUT);
  pinMode(pb2, INPUT);
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
}

void loop() {
  int reading1 = analogRead(potPin1);
  int angle1 = reading1 / 6;
  pb1Val = digitalRead(pb1);
  if (pb1Val == HIGH) {
    angle1 = 90;
  }
  servo1.write(angle1);
  }
  int reading2 = analogRead(potPin2);
  int angle2 = reading2 / 6;
  pb2Val = digitalRead(pb2);
  if (pb2Val == HIGH) {
    angle2 = 30;
    digitalWrite(ledPin, HIGH);
  }

  servo2.write(angle2);
}
