#include "Arduino.h"
#include "Easybot.h"
//#include "Ultrasonic.h"
//#include "L9110motor.h"
//#include <Servo.h>


//extern int  movespeed;
//extern int  turnspeed;  
//Stembot pacman;
//class L9110motor; 
/*Stembot::Stembot()
{
 // L9110motor LeftMotor(leftMotor1A_pin,leftMotor1B_pin);
 // L9110motor RightMotor(rightMotor1A_pin,rightMotor1B_pin);

//	LeftMotor = new L9110motor(leftMotor1A_pin,leftMotor1B_pin);
//	RightMotor = new L9110motor(rightMotor1A_pin,rightMotor1B_pin);
}*/

void Easybot::begin(){
	Headservo.attach(Servo1_pin);
	Headservo.write(Center_angle); //set to center 
    //Serial.begin(9600);

}

///////////////////////////////////////
void Easybot::moveforward(int speed){
 _movespeed = speed*255/100; 
 LeftMotor.run(_movespeed);
 RightMotor.run(_movespeed);
}
////
void Easybot::moveback(int speed){
 _movespeed = speed*255/100; 
 LeftMotor.run(-_movespeed);
 RightMotor.run(-_movespeed);	
}
////////////////////////////////////////////
 void Easybot::moveforward(int leftspeed,int rightspeed)
 {
 	LeftMotor.run(leftspeed);
 	RightMotor.run(rightspeed);
 }

 void Easybot::moveright(int speed)
 {
int rspeed;
rspeed = speed*255/100; 	
moveforward(rspeed,0);

 }
 ///
 void Easybot::moveleft(int speed)
 {
int rspeed;
rspeed = speed*255/100; 	
moveforward(0,rspeed);
 }
 
//////////////////////////////
void Easybot::stop()
{
	LeftMotor.stop();
    RightMotor.stop();
}
///////////////////////////////



void Easybot::turnright(int speed){
_turnspeed = speed*255/100;
//LeftMotor.stop();
//RightMotor.stop();
//delay(deadband_time);
LeftMotor.run(_turnspeed);
RightMotor.run(-_turnspeed);
//delay(turn_duration_time);
//LeftMotor.stop();
//RightMotor.stop();
//delay(deadband_time);
}
/////////////////////
void Easybot::turnleft(int speed){
_turnspeed = speed*255/100;
//LeftMotor.stop();
//RightMotor.stop();
//delay(deadband_time);
	 LeftMotor.run(-_turnspeed);
	 RightMotor.run(_turnspeed);
//delay(turn_duration_time);
//LeftMotor.stop();
//RightMotor.stop();
//delay(deadband_time);
}

//////////////////////////////////
int Easybot::readline(int color){
	Llineval = analogRead(leftline_pin);
    Rlineval = analogRead(rightline_pin);

if (Llineval < line_detect) Lstatus = 1;
else Lstatus = 0; 
if (Rlineval < line_detect) Rstatus = 1;
else Rstatus = 0; 
if (Lstatus==1 && Rstatus==0) lanepos = 1;  //direction to left, need adjust to the right 
else if (Lstatus == 0 && Rstatus==1) lanepos = -1; //direction to the right, need adjust to the left
else if (Lstatus ==0 && Rstatus ==0) lanepos = 0; // inside the lane, no need to adjust
else lanepos = 2; //going to cross line; 
return lanepos; 
}
//////////////////////////////////
int Easybot::readlineSensor(int channel)
{
 line_value = analogRead(channel);
 return line_value;
}
///////////////////////////////////////////////////////
bool Easybot::leftSensor(){
bool color;	
int value;
value = analogRead(leftline_pin);
color  =  LINE_COLOR; 
   if (color == BLACK) 
    {
     if (value>line_detect) return 1;
     else return 0;
    }
   else 
   {
      if (value<line_detect) return 1;
      else return 0;
   }
}
////////////////////////////////////////////////////////
bool Easybot::rightSensor(){
bool color;
int value;		
 value = analogRead(rightline_pin);
 color  =  LINE_COLOR; 
   if (color == BLACK) 
    {
     if (value>line_detect) return 1;
     else return 0;
    }
   else 
   {
      if (value<line_detect) return 1;
      else return 0;
   }

}
///////////////////////////////////////////////////
bool Easybot::centerSensor(){
bool color;
int value;		
 value = analogRead(centerline_pin);
 color  =  LINE_COLOR; 
   if (color == BLACK) 
    {
     if (value>line_detect) return 1;
     else return 0;
    }
   else 
   {
      if (value<line_detect) return 1;
      else return 0;
   }
}

///////////////////////////////////
int Easybot::readSonar(){
return (Distance.Ranging(CM));
    }
 //////////////////////////////////
void Easybot::lookright()
{
Headservo.write(Right_angle);
//return (Distance.ranging(CM));

}

//////
void Easybot::lookleft()
{
Headservo.write(Left_angle);
//return (Distance.ranging(CM));

}
///
void Easybot::lookfront()
{
Headservo.write(Center_angle);
//return (Distance.ranging(CM));

}

