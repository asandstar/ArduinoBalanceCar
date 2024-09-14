#include <Servo.h>
Servo myservo;
int ang;
int lu;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  
}

void loop() {
  // put your main code here, to run repeatedly:
lu = analogRead(A1);
  if (lu>=180){
    ang =180;
  }else if(lu<=0)
  {
    ang = 0;
    }else{
    ang = lu;
  };
  myservo.write(ang);
  delay(15);}
