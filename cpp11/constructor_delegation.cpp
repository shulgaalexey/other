#include <iostream>

class myclass {
	int a;
	int b;
public:
	myclass() : myclass(0, 0) {
		std::cout << "default ctor: " << this << std::endl;
	}
	myclass(int a) : myclass(a, 0) {
		std::cout << "one param ctor: " << this << std::endl;
	}
	myclass(int a, int b) : a{a}, b{b} {
		std::cout << "two param ctor: " << this << std::endl;
	}
	~myclass() {
		std::cout << "~~~~dtor: " << this << std::endl;
	}

	int geta() const {
		std::cout << "geta: " << a << ": " << this << std::endl;
		return a;
	}

	int getb() const {
		std::cout << "getb: " << b << ": " << this << std::endl;
		return b;
	}
};

int main(void) {
	std::cout << "main ====>\n";
	//myclass obj0(); this is not a constructor. this is a func prototype decl
	myclass obj0;
	obj0.geta();
	obj0.getb();
	std::cout << "-------------\n";
	myclass obj1(13);
	std::cout << "-------------\n";
	myclass obj2(42, 123);
	std::cout << "<==== main\n";
	return 0;
}
