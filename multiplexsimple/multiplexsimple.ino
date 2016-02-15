int clockPin = 9;
int  latchPin = 10;
int dataPin = 11;

//looping variables
byte i;
byte j;

const int numReadings = 128;

int readings[numReadings];      // the readings from the analog input
int index = 0;                  // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

void setup() {
  //set pins as output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A5, INPUT);
  
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0; 
}

int previousAverage = 0;
int maxFalloffUnits = 10;
int potValue = 0;

void loop() {
  
  //sendPercentValue(10);
  
  //return;

  // subtract the last reading:
  total= total - readings[index];         
  // read from the sensor:  
  readings[index] = abs(analogRead(A1)+0); 
 
  
  // add the reading to the total:
  total= total + readings[index];       
  // advance to the next position in the array:  
  index = index + 1;                    

  // if we're at the end of the array...
  if (index >= numReadings)              
    // ...wrap around to the beginning: 
    index = 0;                           

  // calculate the average:
  average = total / numReadings;

  if (average < previousAverage && previousAverage - average >  maxFalloffUnits ){
    average = previousAverage - 1;
    //delay(1);
  }
  
  if (average > previousAverage && average - previousAverage >  maxFalloffUnits*4 ){
    average = previousAverage + 10;
    //delay(1);
  }
  
  previousAverage = average;  
  
  potValue = analogRead(A5);
  
  if (average > potValue) {
    average = potValue;
    }
    
    if (average < -potValue) {
      average = -potValue;
      }
  
  sendPercentValue(map(average, -potValue, potValue, 0, 100));
  
}

//storage for led states, 4 bytes
byte ledData[] = {0,1,2,4,8,16,32,64,128};

void sendPercentValue(double percent){
  
  if (percent > 99){
    percent = 99;
  }
  
  if (percent < 1){
    percent = 1;  
  }
  
  byte value =  (9 *percent) /100 ;
  
  digitalWrite(latchPin, LOW);
  
  for (j=0;j<8;j++){
    digitalWrite(clockPin,LOW);
    digitalWrite(dataPin,((ledData[value]>>j)));
    digitalWrite(clockPin,HIGH);
  }
  
  digitalWrite(latchPin, HIGH);
}

