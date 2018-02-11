// https://www.geeksforgeeks.org/stdpartition-in-c-stl/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

void simple_demo() {
	std::vector<int> a(8);

	std::iota(std::begin(a), std::end(a), 1);

	std::for_each(std::begin(a), std::end(a),
			[](int x){ std::cout << x << " "; });
	std::cout << std::endl;

	std::is_partitioned(std::begin(a), std::end(a),
			[](int x) { return x % 2; }) ?
		std::cout << "Partitioned\n" :
			std::cout << "NOT partitioned\n";

	std::cout << "Partitioning.....\n";
	std::partition(std::begin(a), std::end(a),
			[](int x) { return x % 2; });

	for (auto &x: a)
		std::cout << x << " ";
	std::cout << std::endl;

}

void stable_partition_demo() {
	std::vector<int> a = {2, 1, 5, 6, 7, 8 };

	for (auto &x: a) std::cout << x << " ";
	std::cout << std::endl;

	std::cout << "Stable partitioning...\n";
	std::stable_partition(std::begin(a), std::end(a),
			[](int x) { return x % 2; });

	for (auto &x: a) std::cout << x << " ";
	std::cout << std::endl;

	std::cout << "Partitioned first part:\n";
	auto it = std::partition_point(std::begin(a), std::end(a),
			[](int x) { return x % 2; });

	for (auto it2 = std::begin(a); it2 != it; ++it2)
		std::cout << *it2 << " ";
	std::cout << std::endl;
}

void copy_partition_demo() {

	// Partition predicate
	auto odd_test = [](int x) { return x % 2; };

	std::vector<int> a = {2, 1, 5, 6, 7, 8};

	for (auto &x: a) std::cout << x << " ";
	std::cout << std::endl;

	const auto n = std::count_if(std::begin(a), std::end(a), odd_test);

	// Copying partitions to new arrays
	std::vector<int> b;
	std::vector<int> c;
	c.resize(a.size() - n);
	b.resize(n);

	std::partition_copy(std::begin(a), std::end(a),
			std::begin(b), std::begin(c), odd_test);

	std::cout << "New arrays with partitions:\n";
	for (auto &x: b) std::cout << x << " ";
	std::cout << std::endl;

	for (auto &x: c) std::cout << x << " ";
	std::cout << std::endl;
}

//--------------------------------------------------------------------
namespace myqsortns {

int mypartition(int *a, int p, int q) {
	std::cout << "Patitioning from " << p << " to " << q << std::endl;
	std::vector<int> v1, v2;
	const auto pivot = a[p];
	for (int i = p + 1; i <= q; ++i) {
		if (a[i] <= pivot)
			v1.push_back(a[i]);
		else
			v2.push_back(a[i]);
	}
	int i = p;
	for (auto &x: v1) a[i++] = x;
	a[i++] = pivot;
	for (auto &x: v2) a[i++] = x;
	return p + v1.size();
}

void myqsort(int *a, int p, int q) {
	if (p < q) {
		const auto r = mypartition(a, p, q);
		myqsort(a, p, r - 1);
		myqsort(a, r + 1, q);
	}
}

void qsort_demo() {

	//std::vector<int> a = {2, 5, 1, 6, 8, 7, 3, 4};
	int a[] = {2, 5, 1, 6, 8, 7, 3, 4};
	//std::vector<int> a = {2};
	//int a[] = {2, 1, 3};

	std::cout << "Original array:\n";
	for (const auto &x: a) std::cout << x << " ";
	std::cout << std::endl;

	myqsort(a, 0, sizeof(a) / sizeof(a[0]) - 1);

	std::cout << "Sorted array:\n";
	for (const auto &x: a) std::cout << x << " ";
	std::cout << std::endl;
}
} // end of myqsortns


//--------------------------------------------------------------------
namespace myqsortns2 {
//using myiter = std::vector<int>::iterator;


template <typename TMyiter>
TMyiter mypartition(TMyiter p, TMyiter q) {
	const auto pivot = *p;

	auto r = std::partition(p, q + 1,
			[&pivot](const decltype(*p) &x) { return x <= pivot; });

	if (r > p)
		std::iter_swap(p, r - 1);

	return r;
}

template <typename TMyiter>
void myqsort(TMyiter p, TMyiter q) {
	if (p < q) {
		const auto r = mypartition(p, q);
		myqsort(p, r - 1);
		myqsort(r, q);
	}
}

void qsort_demo() {

	//std::vector<int> a = {2, 5, 1, 6, 8, 7, 3, 4};
	std::vector<std::string> a = {"22", "5a", "gg1", "667", "world", "hello"};

	std::cout << "Original array: ";
	for (const auto &x: a) std::cout << x << " ";
	std::cout << std::endl;

	myqsort(std::begin(a), std::end(a) - 1);

	std::cout << "Sorted array:   ";
	for (const auto &x: a) std::cout << x << " ";
	std::cout << std::endl;
}
} // end of myqsortns2

int main(void) {

	//simple_demo();
	//stable_partition_demo();
	//copy_partition_demo();
	myqsortns2::qsort_demo();

	return 0;
}
