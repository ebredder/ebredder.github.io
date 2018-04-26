#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11
int ledpin = 7;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Temperature and Humidty Roxxxxxxxx");
  
  dht.begin();
  pinMode(OUTPUT, ledpin);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Humidty: ");
  Serial.print(h);
  Serial.print("Temperature: ");
  Serial.print(t);

  if (t > 20) {
    digitalWrite(ledpin, HIGH);
  }
  else {
    digitalWrite(ledpin, LOW);
  }
  
  delay(2000);
}
