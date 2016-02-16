/*
  SensorPiezo.h - Code for mangaging a Piezo sensor
*/
#ifndef SensorPiezo_h
#define SensorPiezo_h

#include "Arduino.h"

class SensorPiezo
{
  public:
    SensorPiezo(int pin);
    void setup();
    void loop();
    int getAmplitude();
};

#endif