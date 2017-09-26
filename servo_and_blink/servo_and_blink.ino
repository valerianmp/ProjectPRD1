#include <Servo.h>

Servo sv;  //initialize the servo
int stpos = 120;
int v = 10;
int i = 0;
void setup() {
  sv.attach(3);
  pinMode(8,OUTPUT);
}
void svcw(){ //move servo clockwise
  //since we are dealing with continuous servo,
  //we can't just use servo.write to determine it's angle
  //so, we can use the pulse width modulation to
  //determines how the servo will turn according to the pulse' timing
  sv.writeMicroseconds(1300);
  //parallax continuous servo use the 1.3ms pulse width to determine CW rotation
  //In this case, it's the max speed which makes the servo rotates at 50-60 RPM
  delay(500);
}
void svccw(){ //move servo counter clockwise
  sv.writeMicroseconds(1700);
  //for the CCW rotation
  //this servo use 1.7ms pulse width on maximum rotational speed
  delay(500);
}
void loop() {
  //this is just to make the LED blink with a bit of fade effect
    for(i = 1; i<= 255; i++){  //fade in
    analogWrite(8,i);
    delay(10);
  }
  svcw();
  delay(5000);
  svccw();
  delay(300);
  for(i = 255; i>= 1; i--){  //fade out
    analogWrite(8,i);
    delay(10);
  }
  delay(2000);
}
