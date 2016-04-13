#include <Adafruit_NeoPixel.h>
 
#define STRIP1       6
#define STRIP2       7
#define STRIP3       8
#define STRIP4       9
#define STRIP5       10

#define N_LEDS    30
#define L1        4
#define L2        5

#define SENSOR1   A1
#define SENSOR2   A2
#define SENSOR3   A3
#define SENSOR4   A4
#define SENSOR5   A5

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(N_LEDS, STRIP1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(N_LEDS, STRIP2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(N_LEDS, STRIP3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(N_LEDS, STRIP4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip5 = Adafruit_NeoPixel(N_LEDS, STRIP5, NEO_GRB + NEO_KHZ800);

int param_colorIndex = 0;
int param_mode = 0;
int param_slope = 0;
int param_showPeaks = 0;

int value1 = 0;
int value2 = 0;
int value3 = 0;
int value4 = 0;
int value5 = 0;

void setup() {
  
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  
  pinMode(SENSOR1, INPUT);
  pinMode(SENSOR2, INPUT);
  pinMode(SENSOR3, INPUT);
  pinMode(SENSOR4, INPUT);
  pinMode(SENSOR5, INPUT);
  
  strip1.begin();
  strip2.begin();
  strip3.begin();
  strip4.begin();
  strip5.begin();
    
  digitalWrite(L1, true);
}

void loop() {
  
  //getSensorsValue();
  
  int sensor1 = analogRead(SENSOR1);
  
  if (sensor1 < 80){
      sensor1 = 0;
  } else {
    sensor1 = 1053 ;
  }
  
  if (value1 - sensor1 > 5){
    value1 -= 5;  
  } else {
    value1 = sensor1;  
  }
  
  setLevel(strip1.Color(map(value1, 0, 1053, 0, 255), 0, 255 - map(value1, 0, 1053, 0, 255)), value1, strip1);
  
}
 
static void setLevel(uint32_t c, int value, Adafruit_NeoPixel strip) {

  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
      strip.setPixelColor(i  , strip.Color(0, 0, 0)); // Draw new pixel
  }
  
  int maxLed = map(value,-1, 1053,  0, strip.numPixels()+2);
  
  for(uint16_t i=0; i<maxLed; i++) {  
      strip.setPixelColor(i  , c); // Draw new pixel
  }
  
  strip.show();
  
}
