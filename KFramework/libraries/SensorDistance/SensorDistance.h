/*
  SensorDistance.h - Code for mangaging a distance sensor
*/
#ifndef SensorDistance_h
#define SensorDistance_h

#include "Arduino.h"

class SensorDistance
{
  public:
    SensorDistance(int pin);
    void setup();
    void loop();
    int getDistance();
};

#endif