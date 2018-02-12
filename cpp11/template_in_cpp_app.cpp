#include "template_in_cpp.h"
#include <iostream>

int main(void) {
	myclass<int> obj;

	obj.set_value(42);
	std::cout << obj.get_value() << std::endl;

	return 0;
}
