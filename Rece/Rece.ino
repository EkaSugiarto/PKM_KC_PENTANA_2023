#include <WiFi.h>
#include "NTPnya.h"

String RSSII;

void FirebaseS();
void FirebaseL();

#define WIFI_SSID "WLANN"
#define WIFI_PASSWORD "00000000"

#include "LoRAnya.h"
#include "Firebasenya.h"

void setup() {
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  NTPS();
  delay(1000);

  LoRAS();
  FirebaseS();
}

void loop() {
  NTPL();
  LoRAL();
}