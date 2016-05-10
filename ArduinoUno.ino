//Team STORK - v1.0u

#include <Wire.h>
int CH1,CH2;
byte bt[4];
void setup() {
  Wire.begin(8); 
  Serial.begin(115200);
  Wire.onRequest(req);

}

void loop() {
  
 CH1 = pulseIn(2,HIGH,25000);
 CH2 = pulseIn(3,HIGH,25000);
 

}

void req()
{
  int x,y;
  if((CH1>=950)&&(CH1<=2050))
  {
    x=CH1;
  }
  else
  {
    x=1500;
  }

   if((CH2>=950)&&(CH2<=2050))
  {
    y=CH2;
  }
  else
  {
    y=1500;
  }

  
  bt[0]=highByte(x);
  bt[1]=lowByte(x);
  bt[2]=highByte(y);
  bt[3]=lowByte(y);
 
  Wire.write(bt,4);
  
}

