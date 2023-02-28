#ifndef A_READ_H
#define A_READ_H

#include "variables.h"

byte analogPin = A0;

void aReadInit(){
  pinMode(analogPin, INPUT);
}

void aReadLoop(){
  analogLecture = analogRead(analogPin);
}

#endif