#ifndef __ENGINE_H_INCLUDED__
#define __ENGINE_H_INCLUDED__


class Engine {
public:
	virtual ~Engine() {};
	virtual bool start() = 0;
	virtual bool stop() = 0;
};

#endif /*__ENGINE_H_INCLUDED__*/
