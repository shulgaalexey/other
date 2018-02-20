#include "vehicle.h"
#include "engine.h"
#include "transmission.h"

Vehicle::Vehicle(Engine *engine, Transmission *transmission) :
	engine{engine},
	transmission{transmission} {
}

Vehicle::~Vehicle() {
	// This is managed by the IoC Container
	//if (engine)
	//	delete engine;
	//if (transmission)
	//	delete transmission;
	engine = nullptr;
	transmission = nullptr;
}

