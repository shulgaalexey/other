#ifndef __VEHICLE_H_INCLUDED__
#define __VEHICLE_H_INCLUDED__

class Engine;
class Transmission;

class Vehicle {
	Engine *engine;
	Transmission *transmission;
public:
	Vehicle(Engine *engine, Transmission *transmission);
	virtual ~Vehicle();
	virtual void honk() const = 0;
};

#endif /*__VEHICLE_H_INCLUDED__*/
