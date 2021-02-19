#include <PID_v1.h>
#include <stdint.h>
#include <Servo.h>



double Setpointx=300, Inputx, Outputx;
double Setpointy=225, Inputy, Outputy;
double Kpx = 0.138;
double Kix = 0.0245;
double Kdx = 0.036;


int start1=80,start2=90;

double Kpy = 0.138;                                                       
double Kiy = 0.0245;
Fdouble Kdy = 0.036;

PID PIDX(&Inputx, &Outputx, &Setpointx, Kpx, Kix, Kdx, DIRECT); 
PID PIDY(&Inputy, &Outputy, &Setpointy, Kpy, Kiy, Kdy, REVERSE);
Servo servo1,servo2;

int angle = 0;
void setValues()
{
  servo1.write(start1);
  servo2.write(start2);
}


void setup()
{
  Serial.begin(9600);
  Serial.setTimeout(10);
  servo1.attach(9);
  servo2.attach(6);
  setValues();
  
  PIDX.SetMode(AUTOMATIC);
  PIDX.SetOutputLimits(-90,90);
  PIDY.SetMode(AUTOMATIC);
  PIDY.SetOutputLimits(-80,80);
  PIDX.SetSampleTime(10);
  PIDY.SetSampleTime(10);
  delay(100);
}
int x,y;
String inString,String1,String2;
int i;
String sx="",sy="";
void loop()
{

 while(Serial.available()>0)
 {
  
  inString=Serial.readString();
  String recieved=inString;
   int i;
    for (i = 0; recieved[i] != ','; i++)
      sx += recieved[i];
    i++;
    for (; recieved[i]!='.';i++)
    sy+=recieved[i];
    
    x=sx.toInt();
    y=sy.toInt();
  
    //Serial.println(x);
    //Serial.println(y);
    sx="";
    sy="";
  if(x!=-1&&y!=-1)
  {
  Inputx=x;
  Inputy=y;
  PIDX.Compute();
  PIDY.Compute();
  servo1.write(start1+Outputy);
  servo2.write(start2+Outputx);
  }   
  else
 {
  servo1.write(start1);
  servo2.write(start2);
 }
  }


 }  
 



