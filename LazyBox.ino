#include <Servo.h>

//servo
int servoPin = 3; 
Servo Servo1; 

//hc-06
char blueToothVal;           //nyimpen value dari sensor bluetooth
char lastValue;              //nyimpen value sebelumnya
 
void setup()
{
 Serial.begin(9600); 
 Servo1.attach(servoPin); 
}
 
void loop(){
  if(Serial.available()){	//baca data dari bluetooth, kalo ada
    blueToothVal=Serial.read();
  }
  if (blueToothVal=='n'){
  	Servo1.write(90);
   if (lastValue!='n') Serial.println(F("TUTUP")); //dia ngunci
    lastValue=blueToothVal;
  }
  else if (blueToothVal=='f')
  {
  	if (lastValue!='f') Serial.println(F("BUKA")); //buka kunci
    lastValue=blueToothVal;
  }
  delay(1000);
}