void setup() {
  // put your setup code here, to run once:
  for(int i = 8; i<=12; i++){
    pinMode(i, OUTPUT); //set every pin from 8 - 12 to be an output pin
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  for(i = 8; i <= 12; i++){   //for each led
    for(int j = 0; j<= 255; j+=3){  //fade in
      analogWrite(i,j);
      delay(1);
    }
    delay(50);
    for(int j = 255; j>=0; j-=3){ //and then fade out so we can move to the next led
      analogWrite(i,j);
      delay(1);
    }
    delay(50);
  }
  delay(300);   //delay to smooth out the movement
}
