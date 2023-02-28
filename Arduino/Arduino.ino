#include "variables.h"
#include "messenger.h"
#include "AnalogicRead.h"
#include "GPS.h"

void setup() {
  Serial.begin(9600);
  aReadInit();
  gpsInit();
  lastSend = millis();
}

void loop() {
  aReadLoop();
  gpsLoop();
}
