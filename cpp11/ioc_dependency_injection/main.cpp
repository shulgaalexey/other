#include <iostream>
#include "vehicle.h"
#include <exception>
#include "application_context.h"

int main(void) {

	// Test 1: OK, constructing a car
	try {
		std::cout << "TEST1====================\n";
		ApplicationContext ac("toyota.cfg");
		Vehicle *car = dynamic_cast<Vehicle *>(ac.get_bean("Car"));
		if (!car) {
			std::cout << "BAD ERROR: Can not create car bean\n";
			return 1;
		}

		car->honk();

	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	// Test 2: OK, constructing a truck
	try {
		std::cout << "TEST2====================\n";
		ApplicationContext ac("volvo.cfg");
		Vehicle *car = dynamic_cast<Vehicle *>(ac.get_bean("Truck"));
		if (!car) {
			std::cout << "BAD ERROR: Can not create car bean\n";
			return 1;
		}

		car->honk();

	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	// Test 3: ERROR, incorrect config file provided
	try {
		std::cout << "TEST3====================\n";
		ApplicationContext ac("badname.cfg");
		Vehicle *car = dynamic_cast<Vehicle *>(ac.get_bean("Truck"));
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	// Test 4: ERROR, incorrect bean class requested
	try {
		std::cout << "TEST4====================\n";
		ApplicationContext ac("toyota.cfg");
		Vehicle *car = dynamic_cast<Vehicle *>(ac.get_bean("Truck"));
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	std::cout << "Test done\n";

	return 0;
}
