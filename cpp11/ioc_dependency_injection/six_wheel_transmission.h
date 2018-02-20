#ifndef __SIX_WHEEL_TRANSMISSION_H_INCLUDED__
#define __SIX_WHEEL_TRANSMISSION_H_INCLUDED__

#include "transmission.h"
#include <iostream>

class SixWheelTransmission : public Transmission {
public:
	SixWheelTransmission() {
		std::cout << "ctor SixWheelTransmission\n";
	}
	virtual ~SixWheelTransmission() {
		std::cout << "dtor SixWheelTransmission\n";
	}
	virtual int get_wheels_count() { return 6; }
};

#endif /*__SIX_WHEEL_TRANSMISSION_H_INCLUDED__*/
