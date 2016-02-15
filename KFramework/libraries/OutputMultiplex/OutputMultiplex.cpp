#include "Arduino.h"
#include "OutputMultiplex.h"

OutputMultiplex::OutputMultiplex(int pin1, int pin2, int pin3, int nbLeds)
{
	VU_clockPin = pin1;
	VU_dataPin = pin3;
	VU_latchPin = pin2;
	_nbLeds = nbLeds;
}

void OutputMultiplex::setPercentValue(float percent){
	
	if (percent > 100){ percent = 100; } 
	if (percent < 0){ percent = 0; }  
	
	byte value =  (9 *percent) /100 ;
	digitalWrite(VU_latchPin, LOW);  
	
	for (int j=0;j<_nbLeds;j++){
		digitalWrite(VU_clockPin,LOW);
		digitalWrite(VU_dataPin,((VU_ledData[value]>>j)));
		digitalWrite(VU_clockPin,HIGH);
	}  
	
	digitalWrite(VU_latchPin, HIGH);
}

void OutputMultiplex::setPattern(unsigned long pattern){
	
	digitalWrite(VU_latchPin, LOW);  
	
	for (int j=0;j<_nbLeds;j++){
		digitalWrite(VU_clockPin,LOW);
		digitalWrite(VU_dataPin,((pattern>>j & 1)));
		digitalWrite(VU_clockPin,HIGH);
	}  
	
	digitalWrite(VU_latchPin, HIGH);
}


void OutputMultiplex::setup()
{
	pinMode(VU_clockPin, OUTPUT);
	pinMode(VU_dataPin, OUTPUT);
	pinMode(VU_latchPin, OUTPUT);
	this->setPercentValue(0); 
}

void OutputMultiplex::setLedValue(int led, int value){
		
	digitalWrite(VU_latchPin, LOW);  	
	
	digitalWrite(VU_clockPin,LOW);
	digitalWrite(VU_dataPin,((value>>led & 1)));
	digitalWrite(VU_clockPin,HIGH);
	 
	digitalWrite(VU_latchPin, HIGH);
}

