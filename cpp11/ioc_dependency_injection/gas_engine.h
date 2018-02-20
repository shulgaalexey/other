#ifndef __GAS_ENGINE_H_INCLUDED__
#define __GAS_ENGINE_H_INCLUDED__

#include <iostream>
#include "engine.h"

class GasEngine : public Engine {
public:
	GasEngine() {
		std::cout << "ctor GasEngine\n";
	}
	virtual ~GasEngine() {
		std::cout << "dtor GasEngine\n";
	}
	virtual bool start() {
		std::cout << "GasEngine started\n";
	}
	virtual bool stop() {
		std::cout << "GasEngine stopped\n";
	}
};

#endif /*__GAS_ENGINE_H_INCLUDED__*/
