#include <OutputMultiplex.h>
//#include <SensorPir.h>

//SensorPir pir(A0, 10, 2000);
OutputMultiplex vuMeter(9,10,11, 8);

void setup(){
  vuMeter.setup();
  //pir.setup();
}
  
void loop(){
  //pir.loop();
  
  for (int i=0.0; i<256.0; i+=2.0){
    vuMeter.setPattern(i);
    delay(20);  
  }
  
  for (int i=128.0; i>0.0; i-=1.0){
    vuMeter.setPattern(i);
    delay(50);  
  }
  
  vuMeter.setPattern(B01100110);
  delay(500);
  
  vuMeter.setPattern(B10000001);
  
  delay(500);
}
