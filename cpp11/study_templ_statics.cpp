#include <iostream>


template <typename T>
void print(T var) {
	static int st = 100;
	std::cout << var << std::endl;
	std::cout << st << std::endl;
	++st;
}

int main(void) {
	print(1);
	print(2);
	print('a');
	print("b");
	print(.5);

	return 0;
}
