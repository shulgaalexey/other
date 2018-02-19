#ifndef __DIESEL_ENGINE_H_INCLUDED__
#define __DIESEL_ENGINE_H_INCLUDED__

#include <iostream>
#include "engine.h"

class DieselEngine : public Engine {
public:
	virtual ~DieselEngine() {};
	virtual bool start() {
		std::cout << "DieselEngine started\n";
	}
	virtual bool stop() {
		std::cout << "DieselEngine stopped\n";
	}
};

#endif /*__DIESEL_ENGINE_H_INCLUDED__*/
