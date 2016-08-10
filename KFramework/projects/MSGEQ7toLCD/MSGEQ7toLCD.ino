#include <Wire.h>  // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>

/*-----( Declare Constants )-----*/
/*-----( Declare objects )-----*/
// set the LCD address to 0x27 for a 16 chars 2 line display
// Set the pins on the I2C chip used for LCD connections:
//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 2, 1, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

 

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  

  lcd.begin(16,2);   // initialize the lcd for 16 chars 2 lines, turn on backlight

// ------- Quick 3 blinks of backlight  -------------
  for(int i = 0; i< 3; i++)
  {
    lcd.backlight();
    delay(100);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight(); // finish with backlight on  
  
  setupMSGEQ7();
  
  writeLCD("Ready", "ok");
  delay(1000);  


  /*lcd.clear();
  lcd.setCursor(0,0); //Start at character 0 on line 0
  lcd.print("Use Serial Mon");
  lcd.setCursor(0,1);
  lcd.print("Type to display");*/ 


}

void writeLCD(char* string1, char* string2){
  lcd.setCursor(0,0); //Start at character 4 on line 0
  lcd.print(string1);
  //delay(1000);
  lcd.setCursor(0,1);
  lcd.print(string2); // Print text on second line  
}


int analogPin = A0; // read from multiplexer using analog input 0
int strobePin = 2; // strobe is attached to digital pin 2
int resetPin = 3; // reset is attached to digital pin 3
int spectrumValue[7]; // to hold a2d values


void setupMSGEQ7(){
  Serial.begin(9600);
 pinMode(analogPin, INPUT);
 pinMode(strobePin, OUTPUT);
 pinMode(resetPin, OUTPUT);
 analogReference(DEFAULT);

 digitalWrite(resetPin, LOW);
 digitalWrite(strobePin, HIGH);

 Serial.println("MSGEQ7 test by J Skoba");
  }

void loopMSGEQ7()
{
 digitalWrite(resetPin, HIGH);
 //delayMicroseconds(1);
 digitalWrite(resetPin, LOW);
 
 digitalWrite(strobePin, HIGH);

  delayMicroseconds(80); 

 for (int i = 0; i < 7; i++)
 {
 digitalWrite(strobePin, LOW);
 delayMicroseconds(30); // to allow the output to settle
 spectrumValue[i] = analogRead(analogPin);
 
 digitalWrite(strobePin, HIGH);
 delayMicroseconds(30);
}

delayMicroseconds(1000);
 // comment out/remove the serial stuff to go faster
 // - its just here for show
 /*if (spectrumValue[i] < 10)
 {
 Serial.print(" ");
 Serial.print(spectrumValue[i]);
 }
 else if (spectrumValue[i] < 100 )
 {
 Serial.print(" ");
 Serial.print(spectrumValue[i]);
 }
 else
 {
 Serial.print(" ");
 Serial.print(spectrumValue[i]);
 }

 digitalWrite(strobePin, HIGH);
 }
 Serial.println();*/
}

void loop()   
{
  {
    
    loopMSGEQ7();
    
    //char buf[4]; // "-2147483648\0"
    //char buf2[4];
    //writeLCD(itoa(1022, buf, 10), itoa(spectrumValue[3], buf2, 10));
    
  }
  
}

void updateMSGEQ7Registers(){
  
  }

