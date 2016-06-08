#include <OutputMultiplex.h>

OutputMultiplex vuMeter1 = OutputMultiplex(8, 6, 7, 8);
OutputMultiplex vuMeter2 = OutputMultiplex(12, 10, 11, 8);

void setup() {
  vuMeter1.setup();
  vuMeter2.setup();
  pinMode(A2, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A0, INPUT);
}

int valueL = 0;
int valueR = 0;

int valueLLast = 0;
int valueRLast = 0;

void loop() {

  int potValuePercent = map(analogRead(A5), 1024, 0, 10, 1600);
  int speed = map(analogRead(A5), 1024, 0, 5, 1);
  
  valueL = map(analogRead(A2), 0, 90, 0, potValuePercent)-(potValuePercent*8/10);
  valueR = map(analogRead(A4), 0, 90, 0, potValuePercent)-(potValuePercent*8/10);

  //if (valueL > -1) {

    if ((valueLLast - valueL) > speed) {
      valueL = valueLLast - speed;
    }

    vuMeter1.setPercentValue(valueL/10);
    valueLLast = valueL;

  //}

 // if (valueR > -1) {

    if ((valueRLast - valueR) > speed) {
      valueR = valueRLast - speed;
    }

    vuMeter2.setPercentValue(valueR/10);
    valueRLast = valueR;
 // }
 // delay(1);

}
