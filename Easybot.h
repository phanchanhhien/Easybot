/*
Class for Stembot platform 
an open source STEM robotics for kids
Things Changing Technology.

Stembot V1.0 
   Base: 2 wheel DC motor 
   Consol: RJ45 Analog mux interface base on CD4051 8 channels 
   Sensor:  2 Side IR Line detector sensors via analog input
            1 center IR dots detector sensor via analog input
            Ultra Sonic Range finder sensor SR-04 for detect Monster (expansion) include Micro Servo SG90
   Actuator: Mouth by Servo SG90 
   Interface: Run Button, Upload Button, RGB LED indicator, Speaker 			 

*/
#ifndef Easybot_H_
#define Easybot_H_

#include "Arduino.h"
#include "stdint.h"

#include "EasyMotor.h"
#include "EasySonar.h"
#include <Servo.h>

///////////////////////////////////////////////////////////
////define for I/O Pins////////////////////////////////////
#ifndef _Robot_IO										///
#define _EasybotIO										///
#define leftline_pin        0							///
#define rightline_pin       3							///
#define centerline_pin      1	
#define leftline_pin2       
#define rightline_pin2						///
//#define battery_monitor_pin 4     					///
#define SR04_Trig             8							///
#define SR04_Echo             7							///
#define Servo1_pin         10    
#endif  						///
/////////////////Pins for L9110motor					///
/*														///
#define leftMotor1A_pin   3          //_pinB1A			///
#define leftMotor1B_pin   5          //_pinB1B			///
#define rightMotor1A_pin  6          //_pinB1A			///
#define rightMotor1B_pin  9          //_pinB1B#endif	///
*/														///
 #ifndef _Motor_Driver
 #define _L9110_Driver	
 //#define _L298_Driver
 
 #endif 

 #ifdef _L9110_Driver 
#define leftMotor1A_pin   5          //_pinB1A			///
#define leftMotor1B_pin   3          //_pinB1B			///
#define rightMotor1A_pin  11         //_pinB1A			///
#define rightMotor1B_pin  9          //_pinB1B      	///
 #endif													///

 #ifdef _L298_Driver	
#define leftMotor1A_pin   5          //_pinB1A			///
#define leftMotor1B_pin   3          //_pinB1B			///
#define rightMotor1A_pin  11         //_pinB1A			///
#define rightMotor1B_pin  9          //_pinB1B      	///
 #endif 												///	
///////////////////////////////////////////////////////////
////define for action paramet er
#define Right_angle             0
#define Left_angle             180
#define Center_angle           90
#define speed_forward         100  //speed (%)
#define lane_adjust            20  //20% speed adjust for lane control
#define turn_duration_time   1200   //turn for 1200ms           
#define deadband_time         10    //gap time btw reverse direction
#ifndef line_detect
#define line_detect     	 200   //threshold value for line detection
#endif
#define linefollow_adj        80      //adjust volume for speed control (%)


#define LEFT                   1
#define RIGHT                 -1
#define CENTER                 0
#define BLACK                  1
#define WHITE                  0

#define LEFTSENSOR            leftline_pin
#define RIGHTSENSOR           rightline_pin
#define CENTERSENSOR          centerline_pin
#ifndef LINE_COLOR
#define LINE_COLOR          BLACK

#endif
/////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////
class Easybot {//: public L9110motor  { 
public: 

	Easybot(): LeftMotor(leftMotor1A_pin,leftMotor1B_pin), RightMotor(rightMotor1A_pin,rightMotor1B_pin), Distance(SR04_Trig,SR04_Echo), Headservo() {

	}  //initializer list for objects use within this Class
    
    void begin();                            
    void moveforward(int speed);          // move forward function, Hàm chạy thẳng 
    void moveforward(int Leftspeed,int rightspeed);  // move forward with manual adjust Left, Right Wheel Speed || Hàm chạy thẳng với tham số bánh trái và phải tùy chỉnh
    void moveback(int speed);
    void moveright(int speed);            // move to the right  || Hàm chạy xiêng về bên phải
    void moveleft(int speed);             // move to the left   || Hàm chạy xiêng về bên trái
 	void stop();						// stop the robot       || Hàm dừng robot
	void turnright(int speed);           // turn to the right   || Quay robot sang phải
	void turnleft(int speed);            //turn robot to the left || Quay robot sang trái
	int readline(int color);             //Read all line sensors, return positon with customized threshold by #define threshold_detect value, default is 400, return: (1:Left,0:Center,-1:left,2:crossline)
	int readlineSensor(int channel);     ///Read line sensor with customized channel, return raw value
	bool leftSensor();                           //Read left  line sensor, return raw ADC value
	bool rightSensor();                          //Read Right line sensor, return raw ADC value
	bool centerSensor();							//Read Center line Sensor, return raw ADC value
    int readSonar();            ///read the distance || Đọc khoảng cách 
    void lookright();   ///nhìn sang phải
    void lookleft();     //nhìn sang trái
    void lookfront();    //nhìn phía trước
  float systemvoltage();
  
  
private:
  EasyMotor LeftMotor;
  EasyMotor RightMotor;
  EasySonar Distance;
  Servo     Headservo;
  int _movespeed; 
  int _turnspeed;
  int _vitri;
  int Llineval;
  int Rlineval;
  int Lstatus;
  int Rstatus;
  int lanepos; 
  int line_value;
  int _adj;

};


//extern Stembot pacman;
#endif 