#ifndef __FOUR_WHEEL_TRANSMISSION_H_INCLUDED__
#define __FOUR_WHEEL_TRANSMISSION_H_INCLUDED__

#include <transmission.h>

class FourWheelTransmission {
public:
	virtual ~FourWheelTransmission() {};
	virtual int get_wheels_count() { return 4; }
};

#endif /*__FOUR_WHEEL_TRANSMISSION_H_INCLUDED__*/
