#ifndef GPS_H
#define GPS_H

// +------------+-----+
// |    Conexiones    |
// +------------+-----+
// | Arduino    | GPS |
// | 3          | RX  |
// | 4          | TX  |
// | 3.3v       | VCC |
// | GND        | GND |
// +------------+-----+

// Bibliotecas
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include "variables.h"

// Creacion de instacia TinyGPS
TinyGPSPlus gps;

// Puerto serial mediante sotfware
SoftwareSerial gpsSerial(4,3); //RX, TX 

// Inicializacion de gps

void gpsInit(){
  gpsSerial.begin(9600);
}

void gpsLoop(){
  while(gpsSerial.available() > 0){
    if(gps.encode(gpsSerial.read())){
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

