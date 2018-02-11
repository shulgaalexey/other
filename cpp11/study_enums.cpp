#include <iostream>

enum class colors {
	RED,
		GREEN,
		BLUE
};

int myfunc(colors c) {
	switch (c) {
		case colors::RED:
			std::cout << "RED\n";
			break;
		case colors::GREEN:
			std::cout << "GREEN\n";
			break;
		case colors::BLUE:
			std::cout << "BLUE\n";
			break;
		default:
			std::cout << "UNKNOWN\n";
			break;
	}
	return 42;
}

int main(void) {
	myfunc(colors::GREEN);

	int tmp = static_cast<int>(colors::GREEN);
	std::cout << tmp << std::endl;

	return 0;
}
