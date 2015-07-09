int clockPin = 8;
int  latchPin = 9;
int dataPin = 10;

//looping variables
byte i;
byte j;

void setup() {
  //set pins as output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  
  for (i=0;i<100;i++){  
    sendPercentValue(i);      
    delay(1);
  }  
  
  for (i=100;i>0;i--){  
    sendPercentValue(i);      
    delay(5);
  }  
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

