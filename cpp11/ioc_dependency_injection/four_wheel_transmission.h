#ifndef __FOUR_WHEEL_TRANSMISSION_H_INCLUDED__
#define __FOUR_WHEEL_TRANSMISSION_H_INCLUDED__

#include "transmission.h"
#include <iostream>

class FourWheelTransmission : public Transmission {
public:
	FourWheelTransmission() {
		std::cout << "ctor FourWheelTransmission\n";
	}
	virtual ~FourWheelTransmission() {
		std::cout << "dtor FourWheelTransmission\n";
	}
	virtual int get_wheels_count() { return 4; }
};

#endif /*__FOUR_WHEEL_TRANSMISSION_H_INCLUDED__*/
