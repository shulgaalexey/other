#include <iostream>

class myclass {
	int a;
public:
	myclass(int a) : a{a} {};
	operator int() const { return a; }
};

int main(void) {
	myclass obj{42};
	int n = obj;
	std::cout << n << std::endl;
	std::cout << obj << std::endl;
	return 0;
}
