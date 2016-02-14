#include "Arduino.h"
#include "OutputMultiplex.h"

OutputMultiplex::OutputMultiplex(int pin1, int pin2, int pin3, int nbLeds)
{
	VU_clockPin = pin1;
	VU_dataPin = pin2;
	VU_latchPin = pin3;
	//VU_ledData = (long unsigned int*)malloc(sizeof(long unsigned int) * nbLeds);
	//VU_values = (long unsigned int*)malloc(sizeof(long unsigned int) * nbLeds);
	
	//for (int i = 0; i<nbLeds; i++){
	//	VU_ledData[i] = 1l<<i;
	//	VU_values[i] = 0;		
	//}
	//VU_ledData = ;
}

void OutputMultiplex::setPercentValue(float percent){
	
	if (percent > 100){ percent = 100; } 
	if (percent < 0){ percent = 0; }  
	
	int value = 9.0 * (percent/100.0);  
	digitalWrite(VU_latchPin, LOW);  
	
	for (int j=0;j<8;j++){
		digitalWrite(VU_clockPin,LOW);
		digitalWrite(VU_dataPin,((VU_ledData[value]>>j)));
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


	
void OutputMultiplex::setLedsValues(int &values){
	
	
}

void OutputMultiplex::setLedValue(int led, int value){
		
}

