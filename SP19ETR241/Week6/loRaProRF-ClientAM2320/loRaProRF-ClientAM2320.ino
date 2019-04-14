#include <SPI.h>
#include <Wire.h>
#include "wiring_private.h" // pinPeripheral() function

//Radio Head Library:
#include <RH_RF95.h> 

//Adafruit Sensor Libraries
#include "Adafruit_Sensor.h"
#include "Adafruit_AM2320.h"

//Convert float variables
#include "dtostrf.h"

//Redefine SDA(D4) and SCL(D3) Pins for i2c
TwoWire myWire(&sercom2, 4, 3);

// We need to provide the RFM95 module's chip select and interrupt pins to the
// rf95 instance below. On the SparkFun ProRF those pins are 12 and 6 respectively.
RH_RF95 rf95(12, 6);

//AM2320 instance
Adafruit_AM2320 am2320 = Adafruit_AM2320();

int LED = 13; //Status LED is on pin 13

// The broadcast frequency is set to 921.2, but the SADM21 ProRf operates
// anywhere in the range of 902-928MHz in the Americas.
float frequency = 921.2; //Broadcast frequency

//Converting the float variables for the RF9X to handle
String datastring="";
char databuf[10];
uint8_t dataoutgoing[10];

void setup()
{
  pinMode(LED, OUTPUT);
  
  myWire.begin();
  pinPeripheral(4, PIO_SERCOM_ALT); //SDA
  pinPeripheral(3, PIO_SERCOM_ALT); //SCL

  SerialUSB.begin(9600);
  // It may be difficult to read serial messages on startup. The following line
  // will wait for serial to be ready before continuing. Comment out if not needed.
  while(!SerialUSB); 
  delay(100);
  SerialUSB.println("RFM Client!"); 

  //Initialize the Radio.
  if (rf95.init() == false){
    SerialUSB.println("Radio Init Failed - Freezing");
    while (1);
  }
  else{
    //An LED inidicator to let us know radio initialization has completed. 
    SerialUSB.println("Transmitter up!"); 
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
    
    Serial.println("Adafruit AM2320 Basic Test");
    am2320.begin();
  }

  // Set frequency
  rf95.setFrequency(frequency);

   // Transmitter power can range from 14-20dbm.
   rf95.setTxPower(14, true);
}

void loop()
{
  float c = am2320.readTemperature();
  float f = c * 9.0 / 5.0 + 32;
  float h = am2320.readHumidity();
  
  SerialUSB.print("Temp C: "); SerialUSB.println(c);
  SerialUSB.print("Temp F: "); SerialUSB.println(f);
  SerialUSB.print("Hum: "); SerialUSB.println(h);

  SerialUSB.println("Sending message");

  //Send a message to the other radio
  uint8_t toSend[] = "Temperature C";
  rf95.send(toSend, sizeof(toSend));
  rf95.waitPacketSent();

  datastring += dtostrf(c, 4, 2, databuf);
  strcpy((char *)dataoutgoing,databuf);
  Serial.println(databuf);
  rf95.send(dataoutgoing, sizeof(dataoutgoing));
  rf95.waitPacketSent();
  delay(400);

  uint8_t toSend1[] = "Temperature F";
  rf95.send(toSend1, sizeof(toSend1));
  rf95.waitPacketSent();

  datastring += dtostrf(f, 4, 2, databuf);
  strcpy((char *)dataoutgoing,databuf);
  Serial.println(databuf);
  rf95.send(dataoutgoing, sizeof(dataoutgoing));
  rf95.waitPacketSent();
  delay(400);

  uint8_t toSend2[] = "Humidity";
  rf95.send(toSend2, sizeof(toSend2));
  rf95.waitPacketSent();

  datastring += dtostrf(h, 4, 2, databuf);
  strcpy((char *)dataoutgoing,databuf);
  Serial.println(databuf);
  rf95.send(dataoutgoing, sizeof(dataoutgoing));
  rf95.waitPacketSent();
  delay(400);

  delay(500);
}
