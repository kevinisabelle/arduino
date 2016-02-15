/*
  OutputMultiplex.h - Code for mangaging a MAX74HC chip with leds as a VU meter.
*/
#ifndef OutputMultiplex_h
#define OutputMultiplex_h

#include "Arduino.h"

class OutputMultiplex
{
  public:
    OutputMultiplex(int pin1, int pin2, int pin3, int nbLeds);
	void setup();
	void setPercentValue(float percent);
	void setPattern(unsigned long pattern);
	void setLedValue(int led, int value);
  private:
	// Orange, 1ere pin du chip
	int VU_clockPin;
	// Blanc, 2e pin du chip
	int VU_dataPin;
	// Vert, 3e pin du chip
	int  VU_latchPin;
	//storage for led data
	long unsigned int VU_ledData[9] = {0,1,2,4,8,16,32,64,128};
	//storage for led values
	long unsigned int VU_values[];
	//nb of leds used
	int _nbLeds;
	
};

#endif