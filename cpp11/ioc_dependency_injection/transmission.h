#ifndef __TRANSMISSION_H_INCLUDED__
#define __TRANSMISSION_H_INCLUDED__


class Transmission {
public:
	virtual ~Transmission() {};
	virtual int get_wheels_count() = 0;
};

#endif /*__TRANSMISSION_H_INCLUDED__*/
