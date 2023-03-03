#ifndef GPS_H
#define GPS_H

// +------------+-----+
// |    Conexiones    |
// +------------+-----+
// | Arduino    | GPS |
// | 18/TX1     | RX  |
// | 19/RX1     | TX  |
// | 3.3v       | VCC |
// | GND        | GND |
// +------------+-----+

// Bibliotecas
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include "variables.h"

// Creacion de instacia TinyGPS
TinyGPSPlus gps;

// Inicializacion de gps

void gpsInit(){
  Serial1.begin(9600);
}

void gpsLoop(){
  while(Serial1.available() > 0){
    if(gps.encode(Serial1.read())){
      if(gps.location.isValid()){
        latitud = gps.location.lat();
        longitud = gps.location.lng();
        altura = gps.altitude.meters();
        sendData();
      }
    }
  }
}


#endif

