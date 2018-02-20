#ifndef __TRANSMISSION_H_INCLUDED__
#define __TRANSMISSION_H_INCLUDED__

#include "base_class.h"

class Transmission : public BaseClass {
public:
	virtual ~Transmission() {};
	virtual int get_wheels_count() = 0;
};

#endif /*__TRANSMISSION_H_INCLUDED__*/
