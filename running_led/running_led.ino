void setup() {
  // put your setup code here, to run once:
  for(int i = 8; i<=12; i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  for(i = 8; i <= 12; i++){
    for(int j = 0; j<= 255; j+=3){
      analogWrite(i,j);
      delay(1);
    }
    delay(50);
    for(int j = 255; j>=0; j-=3){
      analogWrite(i,j);
      delay(1);
    }
    delay(50);
  }
  delay(800);
}
