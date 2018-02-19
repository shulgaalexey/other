#ifndef __SIX_WHEEL_TRANSMISSION_H_INCLUDED__
#define __SIX_WHEEL_TRANSMISSION_H_INCLUDED__

#include "transmission.h"

class SixWheelTransmission {
public:
	virtual ~SixWheelTransmission() {};
	virtual int get_wheels_count() { return 6; }
};

#endif /*__SIX_WHEEL_TRANSMISSION_H_INCLUDED__*/
