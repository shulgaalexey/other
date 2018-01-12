// Templates
// https://www.youtube.com/watch?v=9PVRYDrnm9A
#include <iostream>
#include <algorithm>
#include <type_traits>


template<typename t>
t min(t a, t b) {
	static_assert(
			std::is_arithmetic<t>::value,
			"Parameter to min() call must be numeric!");
	if (a < b)
		return a;
	else
		return b;
}

// Type specification
template<>
char min(char a, char b) {
	std::cout << "Specialized min" << std::endl;
	return (a < b) ? a : b;
}

template<typename t>
void swap(t &a, t &b) {
	t tmp = a;
	a = b;
	b = tmp;
}

template<typename t>
class Point {
	t x, y;
public:
	Point(const t &x, const t &y) {
		this->x = x;
		this->y = y;
	}
	bool operator < (const Point &b) {
		t dist = sqrt((x * x) + (y * y));
		t distb = sqrt((b.x * b.x) + (b.y * b.y));
		return dist < distb;
	}
};

int main(void) {

	{ // Basics
		auto a = 1.2;
		auto b = 2;

		auto minimal = min<double>(a, b);

		std::cout << minimal << std::endl;

		auto c = 3;
		swap(b, c);

		std::cout << b << std::endl;
	}

	{ // Classes
		Point<double> a(1, 3);
		Point<double> b(2, 4);

		std::cout << ((a < b) ? "a" : "b") << std::endl;
	}

	return 0;
}
