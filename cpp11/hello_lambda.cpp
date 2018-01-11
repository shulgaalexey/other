// Lambda functions in C++11
// Lesson: https://www.youtube.com/watch?v=uk0Ytomv0wY
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

// Basic lambda features and syntax
void lambda_demo1() {
	int n = 42;
	int a = 1;

	auto my_lambda = [n, &a](const std::string &str) -> int {
		std::cout << str << n << std::endl;
		a = 13;
		return a;
	};

	std::cout << my_lambda("Hello lambda") << std::endl;

	//auto my_lambda_with_sugar = [=, &n](const std::string &str) {
	auto my_lambda_with_sugar = [&](const std::string &str) {
		std::cout << "lambda sugar" << std::endl;
		n = 43;
		a = 2;
		return n + a;
	};

	std::cout << my_lambda_with_sugar("Lambda with sugar") << std::endl;


}

// Using lambda in iterators
void lambda_demo2() {
	std::vector<int> arr = {1, 2, 3, 4, 5};
	int total = 0;

	std::for_each(begin(arr), end(arr),
			[&](int x) {
				total += x;
			});

	std::cout << "Sum is: " << total << std::endl;
}

// Using lambda for sorting
void lambda_demo3() {
	std::vector<int> arr = {3, 1, 5, 4, 2};
	std::sort(begin(arr), end(arr),
			[](const int &a, const int &b) -> bool {
				return a < b;
			});
	std::for_each(begin(arr), end(arr),
			[](int x) {
				std::cout << x << std::endl;
			});
}

// Lambdas and std::function
void perform_operation(std::function<void ()> f) {
	f();
}

void lambda_demo4() {

	int x = 100;

	perform_operation([&]() {
			x++;
			});

	auto func = [&]() {
		x += 10;
	};

	perform_operation(func);

	std::cout << x << std::endl;
}

int main(void) {

	lambda_demo1();
	lambda_demo2();
	lambda_demo3();
	lambda_demo4();

	return 0;
}
