#ifndef __VEHICLE_H_INCLUDED__
#define __VEHICLE_H_INCLUDED__

#include "base_class.h"

class Engine;
class Transmission;

class Vehicle : public BaseClass {
	Engine *engine;
	Transmission *transmission;
public:
	Vehicle(Engine *engine, Transmission *transmission);
	virtual ~Vehicle();
	virtual void honk() const = 0;
};

#endif /*__VEHICLE_H_INCLUDED__*/
