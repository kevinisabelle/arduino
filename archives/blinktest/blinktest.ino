int led = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  
  for (int y = 0; y<30; y=y+1){
  
  for (int i = 0; i<100; i=i+5){
  delay(y);
  analogWrite(led, i);    // turn the LED off by making the voltage LOW
  }
  }
}
