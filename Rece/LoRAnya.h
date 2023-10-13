#include <SPI.h>
#include <LoRa.h>

#define SCK 5
#define MISO 19
#define MOSI 27
#define SS 18
#define RST 23
#define DIO0 26

#define BAND 923E6

void LoRAS();
void LoRAL();

String LoRAdata;

#include "Parsingnya.h"

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
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.println("Received packet ");

    while (LoRa.available()) {
      LoRAdata = LoRa.readString();

      int rssi = LoRa.packetRssi();
      Serial.println("RSII = " + String(rssi));
      RSSII = String(rssi);
      ParsingL();
    }
  }
}