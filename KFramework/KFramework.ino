#include <OutputMultiplex.h>
#include <SensorPir.h>

SensorPir pir(A0, 10, 2000);
OutputMultiplex vuMeter(6,7,8, 8);

void setup(){
  pinMode(13, OUTPUT);
  vuMeter.setup();
  pir.setup();
  digitalWrite(13, HIGH);

}
  
void loop(){
  pir.loop();
  digitalWrite(13, pir.getState());    
  
  for (int i=0.0; i<100.0; i+=1.0){
    vuMeter.setPercentValue(i);
    delay(5);  
  }
  
}
