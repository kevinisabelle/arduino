#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

/////////////////////////////
//VARS
//the time we give the sensor to calibrate (10-60 secs according to the datasheet)
int calibrationTime = 10;        

//the time when the sensor outputs a low impulse
long unsigned int lowIn;         

//the amount of milliseconds the sensor has to be low 
//before we assume all motion has stopped
long unsigned int pause = 5000;  

boolean lockLow = true;
boolean takeLowTime;  

int pirPin = A0;    //the digital pin connected to the PIR sensor's output
int ledPin = 13;


/////////////////////////////
//SETUP
void setup(){
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(pirPin, LOW);
  VU_setup();
  
  lcd.begin(16,2);
  print("Kev Rules!!!", "Starting Arduino");
 delay(3000);
  //give the sensor some time to calibrate
  print("calibrating... ", "Start");
    for(int i = 0; i < calibrationTime; i++){
      print("calibrating... ", String(i));
      delay(1000);
      VU_sendPercentValue((i+1)*10);
      }
    print("SENSOR ACTIVE", "");
    delay(50);
    VU_sendPercentValue(0);
  }

////////////////////////////
//LOOP
void loop(){

     if(digitalRead(pirPin) == HIGH){
       digitalWrite(ledPin, HIGH);   //the led visualizes the sensors output pin state
       if(lockLow){  
         //makes sure we wait for a transition to LOW before any further output is made:
         lockLow = false;            
         Serial.println("---");
         VU_sendPercentValue(0);
         print("motion detected at ", String(millis()/1000));
         Serial.print(millis()/1000);
         Serial.println(" sec"); 
         delay(50);
         }         
         takeLowTime = true;
       }

     if(digitalRead(pirPin) == LOW){       
       digitalWrite(ledPin, LOW);  //the led visualizes the sensors output pin state
        long millisK = millis();

       if(takeLowTime){
        lowIn = millisK;          //save the time of the transition from high to LOW
        takeLowTime = false;       //make sure this is only done at the start of a LOW phase
        }
       //if the sensor is low for more than the given pause, 
       //we assume that no more motion is going to happen
       
       if(!lockLow && millis() - lowIn > pause){  
           //makes sure this block of code is only executed again after 
           //a new motion sequence has been detected
           lockLow = true;                        
           print("motion ended at ", String((millis() - pause)/1000));      //output
           Serial.print((millis() - pause)/1000);
           Serial.println(" sec");
           delay(50);
           }
       }
       
       
       double percentValue = ((double)(millis() - lowIn)) / (double)pause * 100.0;
       percentValue = percentValue > 99 ? 99 : percentValue;
       percentValue = digitalRead(pirPin) == HIGH ? 0 : percentValue;
       
       VU_sendPercentValue(percentValue);
       
  }
  
void print(String  text, String text2){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(text);
  lcd.setCursor(0,2);
  lcd.print(text2);
  }
  
  
  
// Orange, 1ere pin du chip
int VU_clockPin = 6;
// Vert, 3e pin du chip
int  VU_latchPin = 8;
// Blanc, 2e pin du chip
int VU_dataPin = 7;
   
  //storage for led states, 4 bytes
byte VU_ledData[] = {0,1,2,4,8,16,32,64,128};
byte VU_value = 0;
   
void VU_setup(){
  pinMode(VU_latchPin, OUTPUT);
  pinMode(VU_clockPin, OUTPUT);
  pinMode(VU_dataPin, OUTPUT);
  VU_sendPercentValue(0);
}

void VU_sendPercentValue(double percent){  
  if (percent > 100){ percent = 100; } 
  if (percent < 0){ percent = 0; }  
  VU_value = 10.0 * (percent/100.0);  
  digitalWrite(VU_latchPin, LOW);  
  for (int j=0;j<8;j++){
    digitalWrite(VU_clockPin,LOW);
    digitalWrite(VU_dataPin,((VU_ledData[VU_value]>>j)));
    digitalWrite(VU_clockPin,HIGH);
  }  
  digitalWrite(VU_latchPin, HIGH);
}

