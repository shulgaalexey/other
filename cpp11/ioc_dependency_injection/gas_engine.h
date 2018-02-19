#ifndef __GAS_ENGINE_H_INCLUDED__
#define __GAS_ENGINE_H_INCLUDED__

#include <iostream>
#include "engine.h"

class GasEngine : public Engine {
public:
	virtual ~GasEngine() {};
	virtual bool start() {
		std::cout << "GasEngine started\n";
	}
	virtual bool stop() {
		std::cout << "GasEngine stopped\n";
	}
};

#endif /*__GAS_ENGINE_H_INCLUDED__*/
