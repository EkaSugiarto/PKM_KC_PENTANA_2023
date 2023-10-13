#include "LoRAnya.h"
#include <SoftwareSerial.h>
#include "Giroskopnya.h"
#include "Compasnya.h"
#include "GPS.h"

void setup() {
  Serial.begin(9600);
  GPSS();
  LoRAS();
  GiroskopnyaS();
  COMPASS();
}

void loop() {
  GPSL();
}