#ifndef __ENGINE_H_INCLUDED__
#define __ENGINE_H_INCLUDED__

#include "base_class.h"

class Engine : public BaseClass {
public:
	virtual ~Engine() {};
	virtual bool start() = 0;
	virtual bool stop() = 0;
};

#endif /*__ENGINE_H_INCLUDED__*/
