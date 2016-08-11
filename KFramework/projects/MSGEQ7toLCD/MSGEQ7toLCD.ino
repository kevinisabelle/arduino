#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // Set the LCD I2C address
int analogPin = A0; // read from multiplexer using analog input 0
int strobePin = 2; // strobe is attached to digital pin 2
int resetPin = 3; // reset is attached to digital pin 3
int spectrumValue[7]; // to hold a2d values

int lightPins[] = {12, 11, 10, 5, 6, 8, 9};

void setup() {

  for (int i = 0; i < 7; i++) {
    //pinMode(lightPins[i], OUTPUT);
    analogWrite(lightPins[i], 1023);
    delay(200);
    analogWrite(lightPins[i], 0);
  }



  lcd.begin(16, 2);



  for (int i = 0; i < 3; i++) {
    lcd.backlight();
    delay(50);
    lcd.noBacklight();
    delay(100);
  }
  lcd.backlight();

  setupMSGEQ7();

  writeLCD("Kevin Isabelle", "Electronics");
  delay(500);

  writeLCD("Kevin Isabelle", "Stereo Castle");
  delay(500);

  lcd.clear();
}

long counter = 0;

void loop() {
  {

    loopMSGEQ7();
    
    if (millis() % 10 == 0){
      printValueToLCD();
    }

    
    outputValuesToLights();

    //delay(25);

  }

}

void outputValuesToLights() {

  for (int i = 0; i < 7; i++) {
    //pinMode(lightPins[i], OUTPUT);
    
    if (true){
      analogWrite(lightPins[i], spectrumValue[i] > 350 ? 255 : 0);
    } else {
    
    analogWrite(lightPins[i], map(spectrumValue[i], 0, 1023, 0, 255));
    }

  }
}

void printValueToLCD() {

  String finalString = "";
  String finalString2 = "";

  for (int i = 0; i < 4; i++) {

    char buf[5] = "    ";
    itoa(map(spectrumValue[i], 0, 1023, 0, 10), buf, 10);

    finalString += buf;
    finalString += "  ";
  }

  for (int i = 4; i < 7; i++) {

    char buf[5] = "    ";
    itoa(map(spectrumValue[i], 0, 1023, 0, 10), buf, 10);

    finalString2 += buf;
    finalString2 += "  ";
  }

  char buffinal[16] = "               ";
  finalString.toCharArray(buffinal, 16);

  char buffinal2[16] = "               ";
  finalString2.toCharArray(buffinal2, 16);

  writeLCD(buffinal, buffinal2);

}

void writeLCD(char* string1, char* string2) {
  lcd.setCursor(0, 0); //Start at character 4 on line 0
  lcd.print(string1);
  lcd.setCursor(0, 1);
  lcd.print(string2); // Print text on second line  
}

void setupMSGEQ7() {

  pinMode(analogPin, INPUT);
  pinMode(strobePin, OUTPUT);
  pinMode(resetPin, OUTPUT);
  analogReference(DEFAULT);

  digitalWrite(resetPin, LOW);
  digitalWrite(strobePin, HIGH);

}

void loopMSGEQ7() {

  digitalWrite(resetPin, HIGH);
  digitalWrite(resetPin, LOW);

  digitalWrite(strobePin, HIGH);

  delayMicroseconds(72);

  for (int i = 0; i < 7; i++) {
    digitalWrite(strobePin, LOW);
    delayMicroseconds(36); // to allow the output to settle
    spectrumValue[i] = analogRead(analogPin);

    if (spectrumValue[i] < 80) {
      spectrumValue[i] = 0;
    }

    digitalWrite(strobePin, HIGH);
    delayMicroseconds(30);
  }

}

