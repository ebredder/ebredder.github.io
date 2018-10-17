/*
Adafruit Arduino - Lesson 15. Bi-directional Motor
*/

int enablePin = 11;
int in1Pin = 10;
int in2Pin = 9;
int switchPin = 7;
int potPin = 0;
int hallEffect = 2;

unsigned long sampleTime = 1000;

void setup()
{
  pinMode(hallEffect, INPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
  Serial.print("Motor Speed");
}

void loop()
{

  int speed = analogRead(potPin) / 4;
  boolean reverse = digitalRead(switchPin);
  setMotor(speed, reverse);
  int rpm=readRPM();
  Serial.println(rpm);
}

void setMotor(int speed, boolean reverse)
{
  analogWrite(enablePin, speed);
  digitalWrite(in1Pin, ! reverse);
  digitalWrite(in2Pin, reverse);
}

int readRPM()
{
  int countMagnet=0;
  unsigned long currentTime=0;
  unsigned long startTime=millis();
  boolean flagMag=LOW;

while(currentTime<=sampleTime)
{
  if(digitalRead(hallEffect)==HIGH)
  {
    flagMag=HIGH;
  }
  if(digitalRead(hallEffect)==LOW && flagMag==HIGH)
  {
    countMagnet++;
    flagMag=LOW;
  }
  currentTime=millis()-startTime;
}
int RPMcount=(60000./float(sampleTime))*countMagnet;
return RPMcount;
}

