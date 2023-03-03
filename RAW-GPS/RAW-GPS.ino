// +------------+-----+
// |    Conexiones    |
// +------------+-----+
// | Arduino    | GPS |
// | 18         | RX  |
// | 19         | TX  |
// | 3.3v       | VCC |
// | GND        | GND |
// +------------+-----+

// Bibliotecas
#include <TinyGPS++.h>
// #include <SoftwareSerial.h>

// Creacion de instacia TinyGPS
TinyGPSPlus gps;

// Puerto serial mediante sotfware
// SoftwareSerial Serial1(4,3); //RX, TX 
char dato = ' ';

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial1.available() > 0){
  dato = Serial1.read();
  Serial.print(dato);
  }
}
