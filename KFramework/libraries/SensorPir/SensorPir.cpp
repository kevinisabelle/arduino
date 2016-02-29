#include "Arduino.h"
#include "SensorPir.h"

SensorPir::SensorPir(int pin, long unsigned int calibrationTime, long unsigned int tolerance) {
  pinMode(pin, INPUT);
  _pin = pin;
  _calibTime = calibrationTime;
  _tolerance = tolerance;
}

void SensorPir::setup() {
  pinMode(_pin, INPUT);
  digitalWrite(_pin, LOW);

  for (int i = 0; i < _calibTime; i++) {
    delay(1000);
  }

  delay(50);
}

void SensorPir::loop() {

  if (digitalRead(_pin) == HIGH) {

    if (_lockLow) {
      //makes sure we wait for a transition to LOW before any further output is made:
      _lockLow = false;
      delay(50);
    }
    _takeLowTime = true;
  }

  if (digitalRead(_pin) == LOW) {
    if (_takeLowTime) {
      _lowIn = millis(); //save the time of the transition from high to LOW
      _takeLowTime = false; //make sure this is only done at the start of a LOW phase
    }
    //if the sensor is low for more than the given pause, 
    //we assume that no more motion is going to happen
    if (!_lockLow && millis() - _lowIn > _tolerance) {
      //makes sure this block of code is only executed again after 
      //a new motion sequence has been detected
      _lockLow = true;
    }
  }
}

int SensorPir::getState() {
  return (int) _lockLow;
}

long unsigned int SensorPir::getTimeLastDetection() {
  return millis() - _lowIn;
}

