#include <TinyGPS++.h>

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial GPSSerial(34, 12);

unsigned long lastDisplayTime = 0;

void GPSS();
void GPSL();

void GPSS() {
  GPSSerial.begin(9600);
}

int i;

void GPSL() {
  while (GPSSerial.available() > 0) {
    gps.encode(GPSSerial.read());
    if (millis() - lastDisplayTime >= 5000) {
      latitude = String(gps.location.lat(), 6);
      longitude = String(gps.location.lng(), 6);
      GiroskopnyaL();
      COMPASL();

      lastDisplayTime = millis();

      LoRAL();
      Serial.println("*" + latitude + ";" + longitude + ";" + String(Yaw) + ";" + String(Pitch) + ";" + String(Roll)
             + ";" + String(derajat) + "\n");
    }
  }
}