#ifndef __CAR_H_INCLUDED__
#define __CAR_H_INCLUDED__

#include <iostream>
#include "vehicle.h"

class Engine;
class Transmission;

class Car : public Vehicle {
	Engine *engine;
	Transmission *transmission;
public:
	Car(Engine *engine, Transmission *transmission) :
		Vehicle(engine, transmission) {}
	virtual ~Car() {
	virtual void honk() const {
		std::cout << "beep\n";
	}
};

#endif /*__CAR_H_INCLUDED__*/
