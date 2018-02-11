//https://www.geeksforgeeks.org/useful-array-algorithms-in-c-stl/
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric> // for iota

void using_iota() {
	int a[6] = {0};
	std::iota(a, a + 6, 20);

	std::for_each(a, a + 6, [](int x) {
			std::cout << x << std::endl; });
}

int main(void) {
	using_iota();
	return 0;

	std::vector<int> v = {1, 2, 3, 4, 5, 6};

	//std::all_of(std::begin(v), std::end(v), std::ispositive());
	std::all_of(std::begin(v), std::end(v), [](int x) {
			std::cout << x << " ";
			if (x & 1)
				std::cout << "ODD\n";
			else
				std::cout << "even\n";
			return x > 0;
			});

	std::any_of(std::begin(v), std::end(v), [](int x) {
			return x > 0; }) ?
	std::cout << "some are positive\n" :
		std::cout << "some are nogotive/n";

	std::none_of(std::begin(v), std::end(v), [](int x) {
			return x < 0; }) ?
		std::cout << "none are negative\n" :
		std::cout << "none are positive\n";

	return 0;
}
