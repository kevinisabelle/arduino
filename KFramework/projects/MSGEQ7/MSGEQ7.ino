/*-----( Import needed libraries )-----*/
#include <Wire.h>  // Comes with Arduino IDE
// Get the LCD I2C Library here: 
// www.4tronix.co.uk/arduino/sketches/LiquidCrystal_V1.2.1.zip
// Move any other LCD libraries to another folder or delete them
// See Library "Docs" folder for possible commands etc.
#include <LiquidCrystal_I2C.h>

/*-----( Declare Constants )-----*/
/*-----( Declare objects )-----*/
// set the LCD address to 0x27 for a 16 chars 2 line display
// Set the pins on the I2C chip used for LCD connections:
//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address






// The LCD is conected to pins 13,12,11,10,9,8

LiquidCrystal lcd(12, 11, 7, 6, 3, 2);

byte vumetro[8][8];

float vumetros[16];

// The analog pin 0 is used to read value.
int valor_analogico = 0; 
// The 6 & 7 pins are used for control the integrated.
int strobe = 4; 
int reset = 5; 
int valores_frecuencias[7]; 

void setup() {
  // Built the characters for bars.
  for (int j=0; j<=7; j++)  
  {
    for (int i=0; i<=7; i++)
    {
      if (i<=j)
      { vumetro[j][7-i] = B01110;}
//      { vumetro[j][7-i] = B01010;}  Uncomment this lines for getting other variants for bars.
//      { vumetro[j][7-i] = B11111;}      
      else
      { vumetro[j][7-i] = 0;}
    }
  }  
  for (int i=0; i<=7;i++)
  {
    lcd.createChar(i, vumetro[i]);
  }

  lcd.begin(16, 2);      
  for (int j=0; j<=7;j++)
  {
    lcd.setCursor(j, 0);
    lcd.write(j);
    lcd.setCursor(j, 1);
    lcd.write(7);    
    
  pinMode(valor_analogico, INPUT);
  pinMode(strobe, OUTPUT);
  pinMode(reset, OUTPUT);
  analogReference(DEFAULT);

  digitalWrite(reset, LOW);
  digitalWrite(strobe, HIGH);
    
  }  
 
}

void loop() {
  
  digitalWrite(reset, HIGH);
  digitalWrite(reset, LOW);

  // The read of integrated is done by multiplexing.
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(strobe, LOW);
    delayMicroseconds(5); 
    valores_frecuencias[i] = analogRead(valor_analogico);
    digitalWrite(strobe, HIGH);
  }

// It's necesary to interpolate for calculating 16 bars having only 7 values read.
for (int k=0; k<=15; k++)
  {
  switch (k) 
  {
    case 0:
      vumetros[k]= valores_frecuencias[0]/64;
      break;
    
    case 1:
      vumetros[k]= (valores_frecuencias[0]/64 + valores_frecuencias[1]/64)/2;
      break;

    case 2:
      vumetros[k]= valores_frecuencias[1]/64;
      break;
   
    case 3:
      vumetros[k]= (valores_frecuencias[1]/64 + valores_frecuencias[2]/64)/2;
      break;
 
    case 4:
      vumetros[k]= valores_frecuencias[2]/64;
      break;
    
    case 5:
      vumetros[k]= (valores_frecuencias[1]/64 + valores_frecuencias[2]/64 + valores_frecuencias[3]/64)/3;
      break;
        
    case 6:
      vumetros[k]= (valores_frecuencias[2]/64 + valores_frecuencias[3]/64 + valores_frecuencias[4]/64)/3;
      break;

    case 7:
      vumetros[k]= random(2)+valores_frecuencias[3]/64;
      break;
      

    case 8:
      vumetros[k]= random(2)+valores_frecuencias[3]/64;
      break;

    case 9:
      vumetros[k]= (valores_frecuencias[2]/64 + valores_frecuencias[3]/64 + valores_frecuencias[4]/64)/3;
      break;

    case 10:
      vumetros[k]= (valores_frecuencias[3]/64 + valores_frecuencias[4]/64 + valores_frecuencias[5]/64)/3;
      break;

    case 11:
      vumetros[k]= valores_frecuencias[4]/64;
      break;

    case 12:
      vumetros[k]= (valores_frecuencias[4]/64 + valores_frecuencias[5]/64)/2;
      break;

    case 13:
      vumetros[k]= valores_frecuencias[5]/64;
      break;

    case 14:
      vumetros[k]= (valores_frecuencias[5]/64 + valores_frecuencias[6]/64)/2;
      break;

    case 15:
      vumetros[k]= valores_frecuencias[6]/64;
      break;
  }

  Dibuja_vumetro(k, vumetros[k]);
  delay(2);
  }
  
}

void Dibuja_vumetro(int posicion, int altura)
{
  if (altura>7)
  {
    lcd.setCursor(posicion, 1);
    lcd.write(7);
    lcd.setCursor(posicion, 0);
    lcd.write(altura-8);    
  }
  else
  {
    lcd.setCursor(posicion, 1);
    lcd.write(altura);
    lcd.setCursor(posicion, 0);
    lcd.write(32);    
  }
}
