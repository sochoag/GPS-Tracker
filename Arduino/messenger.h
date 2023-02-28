#ifndef MESSENGER_H
#define MESSENGER_H

#include <ArduinoJson.h>
#include "variables.h"

void sendData(){
  if(millis()-lastSend>500){
    lastSend = millis();  
    // Serial.println(latitud);
    DynamicJsonDocument doc(200);
    doc["value"] = analogLecture;
    doc["lat"] = latitud;
    doc["lon"] = longitud;
    doc["ele"] = altura;
    String toReturn = "";
    serializeJson(doc,Serial);
    Serial.println();
  }
}

#endif