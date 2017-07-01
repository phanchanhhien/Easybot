#ifndef EasyMotor_H_
#define EasyMotor_H_

#include "stdint.h"
#include "Arduino.h"
///@brief Class for DC Motor Module
#define deadband 200
class EasyMotor
{
	public:
		  
	   	EasyMotor(uint8_t PinA,uint8_t PinB);
	    void run(int speed);
	    void stop();
	private:
		uint8_t _PinA;
		uint8_t _PinB;
};
#endif