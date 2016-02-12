

int VU_clockPin = 6;
int  VU_latchPin = 8;
int VU_dataPin = 7;
   
void VU_setup(){
    pinMode(VU_latchPin, OUTPUT);
  pinMode(VU_clockPin, OUTPUT);
  pinMode(VU_dataPin, OUTPUT);
  VU_sendPercentValue(0);
  }

void setup() {
  //set pins as output
VU_setup();

}


void loop() {

  
  
  for (double i = 0.0; i<100.0; i+=10.0){
    VU_sendPercentValue(i);
    delay(100);
    
    Serial.println(i);
  }
  
}

//storage for led states, 4 bytes
byte VU_ledData[] = {0,1,2,4,8,16,32,64,128};

void VU_sendPercentValue(double percent){
  
  if (percent > 100){
    percent = 100;
  }
  
  if (percent < 0){
    percent = 0;  
  }
  
  byte value = 9 * (percent/100);
  
  digitalWrite(VU_latchPin, LOW);
  
  for (int j=0;j<8;j++){
    digitalWrite(VU_clockPin,LOW);
    digitalWrite(VU_dataPin,((VU_ledData[value]>>j)));
    digitalWrite(VU_clockPin,HIGH);
  }
  
  digitalWrite(VU_latchPin, HIGH);
}

