#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // Set the LCD I2C address
int analogPin = A0; // read from multiplexer using analog input 0
int strobePin = 2; // strobe is attached to digital pin 2
int resetPin = 3; // reset is attached to digital pin 3
int spectrumValue[7]; // to hold a2d values

void setup() {

  lcd.begin(16, 2); 

  for (int i = 0; i < 3; i++) {
    lcd.backlight();
    delay(100);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight();

  setupMSGEQ7();

  writeLCD("Kevin Isabelle", "Electronics");
  delay(200);

  lcd.clear();
}

void loop() {
  {

    loopMSGEQ7();

    printValueToLCD();

    delay(25);

  }

}

void printValueToLCD() {

  String finalString = "";
  String finalString2 = "";

  for (int i = 0; i < 4; i++) {

    char buf[5] = "    ";
    char buf2[5] = "    ";
    itoa(spectrumValue[i], buf, 10);
    itoa(spectrumValue[i], buf2, 10);

    finalString += buf;
    finalString += "  ";
  }
  
  for (int i = 4; i < 7; i++) {

    char buf[5] = "    ";
    char buf2[5] = "    ";
    itoa(spectrumValue[i], buf, 10);
    itoa(spectrumValue[i], buf2, 10);

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
    spectrumValue[i] = map(analogRead(analogPin), 0, 1023, 0, 10);
    digitalWrite(strobePin, HIGH);
    delayMicroseconds(30);
  }

}

