#include "Arduino.h"
#include "SensorPiezo.h"

private int SensorPiezo::_pin;

SensorPiezo::SensorPiezo(int pin)
{
	_pin = pin;
}

void SensorPiezo::setup()
{
	pinMode(_pin, INPUT);
	 
}

void SensorPiezo::loop()
{
	
}

int SensorPiezo::getAmplitude(){
	return 1;
}

