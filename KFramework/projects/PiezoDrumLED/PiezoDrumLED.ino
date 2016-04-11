#include <Adafruit_NeoPixel.h>
 
#define PIN       6
#define N_LEDS    30
#define L1        5
#define L2        7
#define BTN1      A3
#define BTN2      A4
#define BTN3      A5

#define SENSOR1   A1
#define SENSOR2   A2

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
 
int param_colorIndex = 0;
int param_mode = 0;
int param_slope = 0;
int param_showPeaks = 0;

int value1 = 0;
int value2 = 0;

void setup() {
  
  pinMode(A0, INPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);
  pinMode(BTN3, INPUT);
  pinMode(SENSOR1, INPUT);
  
  strip.begin();
}

void loop() {
  
  bool btn1 = !analogRead(BTN1);
  bool btn2 = !analogRead(BTN2);
  bool btn3 = !analogRead(BTN3);
  
  digitalWrite(L1, true);
  delay(1000);
  digitalWrite(L2, true);
  delay(1000);
  digitalWrite(L1, false);
  delay(1000);
  digitalWrite(L2, false);
  delay(1000);
  //digitalWrite(L2, btn3);
  
  //value = analogRead(A0);
  value = 0;
  //strip.setPixelColor(value/4, strip.Color(0, 255, 0)); // Draw new pixel
      //strip.setPixelColor(i-4, 0); // Erase pixel a few steps back
   //  strip.show();
   for (int i=0; i<1053; i++){
  
  setLevel(strip.Color(i/16, 254-(i/4), i/16), i);
  //delay(2);
  }
  
  //chase(strip.Color(map(value, 0, 255, 0, 1053), 0, 0)); // Red
  //chase(strip.Color(0, 255, 0)); // Green
  //chase(strip.Color(0, 0, 255)); // Blue
}
 
static void setLevel(uint32_t c, int value) {
  

  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
      strip.setPixelColor(i  , strip.Color(0, 0, 0)); // Draw new pixel
      //strip.setPixelColor(i-4, 0); // Erase pixel a few steps back
      
      
  }
  
 
  
  int maxLed = map(value,-1, 1053,  0, strip.numPixels()+2);
  
  for(uint16_t i=0; i<maxLed; i++) {
    
      strip.setPixelColor(i  , c); // Draw new pixel
      //strip.setPixelColor(i-4, 0); // Erase pixel a few steps back
      
      
  }
  
  strip.show();
  
  //delay(10);
 
}
