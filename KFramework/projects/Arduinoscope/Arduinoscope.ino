#define ANALOG_IN 0

void setup() {
  Serial.begin(115200); 
  pinMode(10, OUTPUT);
  //Serial.begin(115200); 
}

bool ledState = false;
float counter = 0.0f;
float maxCount = 1023.0f;

void loop() {
  int val = analogRead(ANALOG_IN);                                              
  Serial.write( 0xffff );                                                         
  Serial.write( (val >> 8) & 0xff );                                            
  Serial.write( val & 0xff );
  
  /*counter+=0.01f;
  
  analogWrite(10, (int)counter); 
  
  if (counter >= maxCount){
    ledState = !ledState;
    
    counter = 0;
  }*/
  
}
