#include <SPI.h>
#include <LoRa.h>
int sensorpin = A0; // Set the input pin for the sensor
int sensorvalue;

void setup()
{

  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");
  if (!LoRa.begin(434E6)) // Set the frequency according to the lora module
  {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}
void loop() {
  (LoRa.available()) ;

  if ((char)LoRa.read() == "2")
  {
    sensorvalue = analogRead(A0); // read the sensor data
    Serial.println("sending value's");
    Serial.println(sensorvalue);
    LoRa.beginPacket();              // LoRa packets begins
    //LoRa.println("photoresistor");   // The data that has to be transmitted.This gets printed at the reciever side.
    LoRa.print(sensorvalue); // The sensor value is sent to the receiver through LoRa module
    LoRa.endPacket();               // LoRa packet ends
    delay(500);
  }

}
