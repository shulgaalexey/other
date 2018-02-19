#include "vehicle.h"
#include "engine.h"
#include "transmission.h"

Vehicle::Vehicle(Engine *engine, Transmission *transmission) :
	engine{engine},
	transmission{transmission} {
}

Vehicle::~Vehicle() {
	if (engine)
		delete engine;
	if (transmission)
		delete transmission;
	engine = nullptr;
	transmission = nullptr;
}

