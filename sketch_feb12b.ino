/*** LCD includes ***/
#include <LiquidCrystal.h>
 
/*** LCD parameters ***/
LiquidCrystal lcd(12,11,5,4,3,2);
 
/*** LCD setup ***/
void LCD_setup(){
  lcd.begin(16,2);

}
 
/*** LCD functions ***/
void LCD_print(String  text, String text2){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(text);
  lcd.setCursor(0,2);
  lcd.print(text2);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  LCD_setup();
  LCD_print("Starting PIR", "");
  PIR_setup();
  
  LCD_print("SENSOR ACTIVE", "");
  
  for(int i = 0; i < 50; i++){
    digitalWrite(13,i % 2 == 0 ? LOW : HIGH);
    delay(i * 2);
  }   
  
  
  
}

long unsigned int PIR_lowIn;  

void loop() {
  // put your main code here, to run repeatedly:
  PIR_updateState();
  digitalWrite(13, digitalRead(A0));
  delay(50);
  LCD_print(String(PIR_getMoveTime()), String(PIR_lowIn));
  
}

/*** PIR Parameters ***/
int PIR_Pin = A0;    //the digital pin connected to the PIR sensor's output
int PIR_calibrationTime = 10; //Calibration time (PIR) // seconds   
long unsigned int PIR_pause = 15000; //milliseconds the sensor has to be low before we assume all motion has stopped 
 
/*** PIR functions ***/
//the time when the sensor outputs a low impulse (PIR)
 
boolean PIR_lockLow = true;
boolean PIR_takeLowTime;  
 
void PIR_setup(){
  pinMode(PIR_Pin, INPUT);
  digitalWrite(PIR_Pin, LOW);
  for(int i = 0; i < PIR_calibrationTime; i++){
    delay(1000);
  }    
  delay(50);
}
 
void PIR_updateState(){
   if(digitalRead(PIR_Pin) == HIGH){
     
     PIR_lowIn = 0;
     
     if(PIR_lockLow){  
       //makes sure we wait for a transition to LOW before any further output is made:
       PIR_lockLow = false; 
       delay(50);
     }  
     PIR_takeLowTime = true;
   }
   
   if(digitalRead(PIR_Pin) == LOW){       
     if(PIR_takeLowTime){
       PIR_lowIn = millis();          //save the time of the transition from high to LOW
       PIR_takeLowTime = false;       //make sure this is only done at the start of a LOW phase
     }
     //if the sensor is low for more than the given pause, 
     //we assume that no more motion is going to happen
     if(!PIR_lockLow && (millis() - PIR_lowIn) > PIR_pause){  
       //makes sure this block of code is only executed again after 
       //a new motion sequence has been detected
       PIR_lockLow = true;                        
     }
   }
}

long PIR_getMoveTime(){
  return PIR_lowIn == 0 ? 0 : millis() - PIR_lowIn;
}
