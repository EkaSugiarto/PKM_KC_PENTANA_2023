#include <SPI.h>
#include <LoRa.h>

#define SCK 5
#define MISO 19
#define MOSI 27
#define SS 18
#define RST 14
#define DIO0 26

#define BAND 923E6

void LoRAS();
void LoRAL();

String longitude, latitude;
float Roll, Pitch, Yaw, derajat;
String uid;

void LoRAS() {
  SPI.begin(SCK, MISO, MOSI, SS);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(BAND)) {
    Serial.println("Starting LoRa failed!");
    while (1)
      ;
  }
}

void LoRAL() {
  LoRa.beginPacket();
  LoRa.print("*" + latitude + ";" + longitude + ";" + String(Yaw) + ";" + String(Pitch) + ";" + String(Roll)
             + ";" + String(derajat) + "\n");
  LoRa.endPacket();
}