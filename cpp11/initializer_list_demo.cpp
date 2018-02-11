#include <iostream>

class myclass {
	const int &a;
public:
	//myclass() : a{0} {}
	myclass(int a) : a{a} {
		std::cout << "ctor: " << this << std::endl;
		std::cout << "&a: " << &a << std::endl;
	}
	~myclass() {
		std::cout << "dtor: " << a << std::endl;
	}
};


class base {
	int a;
public:
	base() {
		std::cout << "base default ctor: " << this << std::endl;
	}
	base(int a) : a{a} {
		std::cout << "base param ctor: " << this << " " << a << std::endl;
	}
	base(const base &src) {
		std::cout << "base copy ctor: " << this << std::endl;
		a = src.a;
	}
	virtual ~base() {
		std::cout << "base dtor: " << this << std::endl;
	}
	base &operator=(const base &src) {
		std::cout << "base operator=: " << this << " " << (&src) << std::endl;
		a = src.a;
		return *this;
	}
};

class child {
	base obj;
	int b;
public:
	child() {
		std::cout << "child default ctor: " << this << std::endl;
	}
	child(int a, int b) : obj{a}, b{b} {
		std::cout << "child param ctor: " << this << std::endl;
	}
	child(int b, const base &obj) : obj{obj}, b{b} {
		std::cout << "child obj param ctor: " << this << std::endl;
	}
	virtual ~child() {
		std::cout << "child dtor: " << this << std::endl;
	}
};


int main(void) {
	//myclass myobj2 = {11};
	//myclass myobj(13);

	base b(7);
	child c(42, b);

	std::cout << "End of main\n";
	return 0;
}
