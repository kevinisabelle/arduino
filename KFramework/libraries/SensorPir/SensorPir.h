/*
  SensorPir.h - Code for mangaging a PIR sensor
*/
#ifndef SensorPir_h
#define SensorPir_h

#include "Arduino.h"

class SensorPir
{
  public:
    SensorPir(int pin, long unsigned int calibrationTime, long unsigned int tolerance);
    void setup();
    void loop();
    int getState();
	long unsigned int getTimeLastDetection();
  private:
    int _pin;
	int _calibTime;
	long unsigned int _tolerance;
	long unsigned int _lowIn;   
	boolean _lockLow = true;
	boolean _takeLowTime; 
	
	
};

#endif