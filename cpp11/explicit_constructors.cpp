#include <iostream>

class myclass {
	int a;
public:
	myclass() : myclass(0) {
		std::cout << "default ctor\n";
	};

	/*
	 * kwyword "explicit" doesn't allow to use this ctor implicitly
	 */
	/*explicit*/ myclass(int a) : a{a} {
		std::cout << "param ctor\n";
	}
	int get() const { return a; }
};

//void func(int a) {
//	std::cout << "func with int\n";
//}

void func(myclass obj) {
	std::cout << "func with obj\n";
}

int main(void) {
	myclass obj1{42}; // explicit
	myclass obj2 = 13; // implici

	func(obj1); // explicit
	func(777); // implicit
	func(myclass{9}); // explicit

	return 0;
}
