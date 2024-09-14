#include <Servo.h>
Servo myservo1,myservo2;
int ang1,ang2;
int lu1,lu2;
int i;
// 两舵机连续转动
void cont()
{  for (i = 0; i < 180; i++){
    myservo1.write(i);
    myservo2.write(i);
    delay(10);
  }
  for (i = 180; i > 0; i--){
    myservo1.write(i);
    myservo2.write(i);
    delay(10);
  }
  }

//两舵机用两个电位计控制转动角度
void lu1()
{
  lu1 = analogRead(A1);
  if (lu1>=180){
    ang1 =180;
  }else if(lu1<=0)
  {
    ang1 = 0;
    }else{
    ang1 = lu1;
  };
  myservo.write(ang1);
  delay(15);
}
void lu2()
{
  lu2 = analogRead(A1);
  if (lu2>=180){
    ang2 =180;
  }else if(lu2<=0)
  {
    ang2 = 0;
    }else{
    ang2 = lu2;
  };
  myservo.write(ang2);
  delay(15);
}

void setup() {
  // put your setup code here, to run once:
  myservo1.attach(5);
  myservo2.attach(6);
}

void loop() {
  // put your main code here, to run repeatedly:
  cont();
  lu1();
  lu2();
}
