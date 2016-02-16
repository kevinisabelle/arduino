#include "Arduino.h"
#include "SensorDistance.h"

private int SensorDistance::_pin;

SensorDistance::SensorDistance(int pin)
{
	_pin = pin;
}

void SensorDistance::setup()
{
	pinMode(_pin, INPUT);
	 
}

void SensorDistance::loop()
{
	
}

int SensorDistance::getDistance(){
	return 1;
}

