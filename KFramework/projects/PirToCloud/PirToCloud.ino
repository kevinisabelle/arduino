#include <SensorPir.h>

SensorPir pir(10, 1000, 3000);


int pirValue = 0;
int previousPirValue = -1;
bool armed = false;

// 0 = Starting (Yellow)
// 1 = Calibrating pir (Yellow and blue)
// 2 = Started / Idle (blue)
// 3 = Movement detected (blue and yellow)
// 4 = Connecting to internet (blue and green)
int state = 0;

void setup() {
  pir.setup();
}

void loop() {
  
  pir.loop();
  
  if (armed){
    
    pirValue = pir.getState();
  
    if (pirValue != previousValue){
      
      // Send the sensor value change
      sendStateToWeb();
      previousValue = pirValue;
      
    }
  }
  
  displayState();
  
}

void displayState(){
  
  // Light armed state LED (Red)
  
  // Show state to other LED (Yellow, Blue, Green)
  
}

void toggleArmedMode(){
  
}

void sendStateToWeb(){
  
  
}
