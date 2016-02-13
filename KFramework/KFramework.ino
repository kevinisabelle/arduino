#include <SensorPir.h>

SensorPir pir(A0, 10, 5000);

void setup(){
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  pir.setup();
  digitalWrite(13, LOW);
}
  
void loop(){
  pir.loop();
  digitalWrite(13, pir.getState());    
}
