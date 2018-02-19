#include <iostream>
#include "vehicle.h"
#include "application_context.h"

int main(void) {
	ApplicationContext ac("toyota.cfg");

	Vehicle *car = static_cast<Vehicle *>(ac.get_bean("car"));
	if (!car) {
		std::cout << "BAD ERROR: Can not create car bean\n";
		return 1;
	}

	car->honk();

	delete car;

	return 0;
}
