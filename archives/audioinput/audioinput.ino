int clockPin = 8;
int  latchPin = 9;
int dataPin = 10;

//looping variables
byte i;
byte j;

const int numReadings = 100;

int readings[numReadings];      // the readings from the analog input
int index = 0;                  // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

void setup() {
  //set pins as output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(A0, INPUT);
  
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0; 
}

int previousAverage = 0;
int maxFalloffUnits = 1;

void loop() {
  

  // subtract the last reading:
  total= total - readings[index];         
  // read from the sensor:  
  readings[index] = analogRead(A0); 
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

  if (average < previousAverage && previousAverage - average){
    average = previousAverage - maxFalloffUnits;
    //delay(20);
  }
  
  previousAverage = average;  
  
  //int linearized = (int)((log((float)average) / log(10)) * 255);
  
  sendPercentValue(map(average, 30, 60, -20, 110));
  
}

//storage for led states, 4 bytes
byte ledData[] = {0,1,2,4,8,16,32,64,128};

void sendPercentValue(double percent){
  
  if (percent > 100){
    percent = 100;
  }
  
  if (percent < 0){
    percent = 0;  
  }
  
  byte value = 9 * (percent/100);
  
  digitalWrite(latchPin, LOW);
  
  for (j=0;j<8;j++){
    digitalWrite(clockPin,LOW);
    digitalWrite(dataPin,((ledData[value]>>j)));
    digitalWrite(clockPin,HIGH);
  }
  
  digitalWrite(latchPin, HIGH);
}

