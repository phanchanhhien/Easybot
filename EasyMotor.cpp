#include "EasyMotor.h"



EasyMotor::EasyMotor(uint8_t PinA,uint8_t PinB)
{  
    _PinA = PinA;
    _PinB = PinB;
    pinMode(_PinA,OUTPUT);
    pinMode(_PinB,OUTPUT);
}
void EasyMotor::run(int speed)
{
    speed = speed > 255 ? 255 : speed;   // if speed > 255 -> speed = 255
    speed = speed < -255 ? -255 : speed; // if speed < -255 -> speed = 255
    // constrain(speed,-255,255);
    if(speed >= 0) {
        digitalWrite(_PinB,LOW);
        analogWrite(_PinA,speed);
      
    } else {
        digitalWrite(_PinA,LOW);
        analogWrite(_PinB,-speed);

    }
}
void EasyMotor::stop()
{
    digitalWrite(_PinB,LOW);
    digitalWrite(_PinA,LOW);
   // delay(deadband);
}