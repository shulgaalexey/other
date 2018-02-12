#include <iostream>
#include <string>

class myclass {
public:
	myclass() {};
	void operator()(const std::string &str) {
		std::cout << str << std::endl;
	}
};

int main(void) {
	myclass obj;
	obj("aaaaa");
	return 0;
}
