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

// Creacion de instacia TinyGPS
TinyGPSPlus gps;

// Puerto serial mediante sotfware
SoftwareSerial gpsSerial(4,3); //RX, TX 
char dato = ' ';

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  gpsSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
while(gpsSerial.available() > 0){
  dato = gpsSerial.read();
  Serial.print(dato);
  }
}
