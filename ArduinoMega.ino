//Team STORK - v1.0m

#include<Servo.h>
#include <Wire.h>


Servo ALE,ELE;
int setpoint=80;
int kp=2;
int CH1,CH2;
int cha1,cha2;
void setup() {
  ALE.attach(9);
  ELE.attach(10);
  Serial.begin(115200);

}

void loop() {
  int t1,t2,t3,t4,t5,t6,t7,t8;
  int e1,e2,e3,e4,e5,e6,e7,e8;
  int r1,r2,r3,r4,r5,r6,r7,r8;
  int o1,o2,o3,o4,o5,o6,o7,o8;
  int front,left,right,back;
  t1=0;
  t2=0;
  t3=0;
  t4=0;
  t5=0;
  t6=0;
  t7=0;
  t8=0;
  Wire.requestFrom(8, 4);

  while (Wire.available())
   {
    byte c1h,c1l,c2h,c2l;
    word c1,c2;
    c1h = Wire.read(); 
    c1l = Wire.read();
    c2h = Wire.read();
    c2l = Wire.read();
    c1 = word(c1h,c1l);
    c2 = word(c2h,c2l);
    CH1 = int(c1);
    CH2= int(c2);
          
   }
  
  for(int i=0;i<=3;i++)
  {
    r1=analogRead(A0);
    t1=r1+t1;
    delay(2);
  }
  t1=t1/3;
 
  
  for(int i=0;i<=3;i++)
  {
    r2=analogRead(A1);
    t2=r2+t2;
    delay(2);
  }
  t2=t2/3;


  for(int i=0;i<=3;i++)
  {
    r3=analogRead(A2);
    t3=r3+t3;
    delay(2);
  }
  t3=t3/3;


  for(int i=0;i<=3;i++)
  {
    r4=analogRead(A3);
    t4=r4+t4;
    delay(2);
  }
  t4=t4/3;

  for(int i=0;i<=3;i++)
  {
    r5=analogRead(A4);
    t5=r5+t5;
    delay(2);
  }
  t5=t5/3;

    for(int i=0;i<=3;i++)
  {
    r6=analogRead(A5);
    t6=r6+t6;
    delay(2);
  }
  t6=t6/3;

    for(int i=0;i<=3;i++)
  {
    r7=analogRead(A6);
    t7=r7+t7;
    delay(2);
  }
  t7=t7/3;

   for(int i=0;i<=3;i++)
  {
    r8=analogRead(A7);
    t8=r8+t8;
    delay(2);
  }
  t8=t8/3;
  
  t1 = constrain(t1,0,setpoint);
  t2 = constrain(t2,0,setpoint);
  t3 = constrain(t3,0,setpoint);
  t4 = constrain(t4,0,setpoint);
  t5 = constrain(t5,0,setpoint);
  t6 = constrain(t6,0,setpoint);
  t7 = constrain(t7,0,setpoint);
  t8 = constrain(t8,0,setpoint);

  e1 = t1 - setpoint;
  e2 = t2 - setpoint;
  e3 = t3 - setpoint;
  e4 = t4 - setpoint;
  e5 = t5 - setpoint;
  e6 = t6 - setpoint;
  e7 = t7 - setpoint;
  e8 = t8 - setpoint;

  o1=e1*kp;
  o2=e2*kp;
  o3=e3*kp;
  o4=e4*kp;
  o5=e5*kp;
  o6=e6*kp;
  o7=e7*kp;
  o8=e8*kp;

  front = (o1+o2)/2;
  right = (o3+o4)/2;
  back =  (o5+o6)/2;
  left =  (o7+o8)/2;

  cha1 = CH1-right+left;
  cha2 = CH2-front+back;  

  ALE.writeMicroseconds(cha1);
  ELE.writeMicroseconds(cha2);

  if(front!=0)
  {
    Serial.println("Move Backward");
  }
  else if(back!=0)
  {
    Serial.println("Move Forward");
    
  }
  else if(left!=0)
  {
    Serial.println("Move Right");
  }
  else if(right!=0)
  {
    Serial.println("Move Left");
  }
  else
  {
    
  }

  

}
