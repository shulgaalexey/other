#include <iostream>

class myclass {
public:
	virtual
		~myclass() {
		std::cout << "myclass dtor\n";
	}
	virtual void func() {
		std::cout << "myclass func\n";
	}
};

class childclass : public myclass {
public:
	//virtual //- not needed, because vtable is already exists
		~childclass() {
		std::cout << "childclass dtor\n";
	}
	//virtual //- not needed, because vtable is already exists
		void func() {
		std::cout << "childclass func\n";
	}
};

int main(void) {
	myclass *obj = new childclass;
	obj->func();
	delete obj;
	return 0;
}
