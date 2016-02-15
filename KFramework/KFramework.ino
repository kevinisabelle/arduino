#include <CommsDmx.h>
#include <OutputMultiplex.h>
#include <SensorPir.h>

SensorPir pir(A0, 10, 2000);
OutputMultiplex vuMeter(9,10,11, 8);
CommsDmx dmx;

void setup(){
  vuMeter.setup();
  pir.setup();
  dmx.setup(3,512);
}
  
void loop(){
  
  pir.loop();
 
  dmx.write(3, 40);  
  dmx.write(4, pir.getState()*255);
  
  for (int i=0.0; i<64.0; i+=2.0){
    vuMeter.setPattern(i);
    delay(5);  
  }  
  for (int i=64.0; i>0.0; i-=1.0){
    vuMeter.setPattern(i);
    delay(5);  
  }  
  vuMeter.setPattern(B01100110);
  delay(50);  
  vuMeter.setPattern(B10000001);  
  delay(50);
    
}
