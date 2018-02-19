#ifndef __TRUCK_H_INCLUDED__
#define __TRUCK_H_INCLUDED__

#include <iostream>
#include "vehicle.h"

class Engine;
class Transmission;

class Truck : public Vehicle {
	Engine *engine;
	Transmission *transmission;
public:
	Truck(Engine *engine, Transmission *transmission) :
		Vehicle(engine, transmission) {}
	virtual ~Truck() {}
	virtual void honk() const {
		std::cout << "Faaa\n";
	}
};

#endif /*__TRUCK_H_INCLUDED__*/
