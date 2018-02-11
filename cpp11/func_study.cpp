#include <iostream>

int func1() {
	std::cout << "func1\n";
	return 42;
}

int func2() {
	std::cout << "func2\n";
	return 13;
}

int func3(int a, int b) {
	std::cout << "func3\n";
	return a + b;
}

int func4(int a) {
	std::cout << "func4\n";
	return a * 2;
}

int main(void) {
	func3(func1(), func2());
	std::cout << "---------\n";
	func4(func1() + func2());
	std::cout << "---------\n";
	func1(), func2(), func3(1, 2), func4(42);
	//std::cout << "---------\n";
	//int v1, v2;
	//v1 = 1,2,3;
	//v2 = (1, 2, 3);
	//std::cout << v1 << " " << v2 << std::endl;
	return 0;
}
