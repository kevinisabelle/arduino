// Download and install LedControl Library
// http://playground.arduino.cc/uploads/Main/LedControl.zip
// http://playground.arduino.cc/Main/LedControl
#include <LedControl.h> 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,11,10,1);

/* we always wait a bit between updates of the display */
unsigned long delaytime = 100;
int inByte = 0; 
char buf[32];

int xPin = A1;
int yPin = A0;
int buttonPin = 7;

int xPosition = 0;
int yPosition = 0;
int buttonState = 0;

void setup() {
  
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  //activate pull-up resistor on the push-button pin
  pinMode(buttonPin, INPUT_PULLUP); 
  
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
  lc.setScanLimit(0, 7);
  //Serial.begin(9600);
  //establishContact();
  
  
  
}

  
void loop() {

  //Serial.println("BUFF");
  //GetString( buf, sizeof(buf) );
  //Serial.println( buf );
  
  //countDown();
  
  xPosition = map(analogRead(xPin), 0, 1000, 0, 7);
  yPosition = map(analogRead(yPin), 0, 1000, 0, 7);
  buttonState = digitalRead(buttonPin);
  
  setPosition(xPosition, yPosition, buttonState);
  
 
  
  
}

void setPosition(int x, int y, int buttonState) {
   
   for (int i=0; i<8; i++){
    for (int j=0; j<8; j++){
      lc.setLed(0, i, j, x == i && y == j ? buttonState == 1 : buttonState == 0);
      //delay(i % 2 == 0 ? 75 : 15 );
    }
  }

}
