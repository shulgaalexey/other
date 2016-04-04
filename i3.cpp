// Given a number of box columns, each of integer height.
// Move top box of tallest column on-top of shortest column.
// Repeat for a specified number of times.
// What would be the difference in height of tallest and shortest column?
//
// SOLUTION: maintain two heaps, one max_heap for extracting the box from the
// tallest column and one min_heap for putting the box on-top of shortest column.
// After performing specified number of exchange, it is needed to extract the
// root item of min_heap from the root number of max_heap.

#include <iostream>
using namespace std;

typedef int * column;
typedef bool (*cmp_func)(column a, column b);

bool cmp_max(column a, column b) {
	return (*a >= *b);
}

bool cmp_min(column a, column b) {
	return (*a <= *b);
}

void swap(column *a, int i, int j) {
	column tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

/*void trace(const char *tag, column *a, int n) {
	cout << endl << tag << endl;
	for(int i = 0; i < n; i ++) cout << *a[i] << " "; cout << endl;
}*/

void heapify(column *a, int i, int n, cmp_func cmp) {
	int l = i * 2 + 1;
	if((l < n) && cmp(a[l], a[i])) {
		swap(a, i, l);
		heapify(a, l, n, cmp);
	}

	int r = i * 2 + 2;
	if((r < n) && cmp(a[r], a[i])) {
		swap(a, i, r);
		heapify(a, r, n, cmp);
	}
}

void build_heap(column *a, int n, cmp_func cmp) {

	// Pre-heapify
	for(int i = int(n / 2); i >= 0; i --)
		heapify(a, i, n, cmp);
}

void dump(column *a_max, column *a_min, int n, int cnt) {
	for(int i = 0; i < cnt; i ++) {
		if(!(*a_max[0]))
			continue;
		(*a_max[0]) --;
		heapify(a_max, 0, n, cmp_max);

		(*a_min[0]) ++;
		heapify(a_min, 0, n, cmp_min);
	}
}

int solution(int *a, int n, int cnt) {
	column *a_min = new column[n];
	column *a_max = new column[n];

	for(int i = 0; i < n; i ++) {
		int *col = new int;
		*col = a[i];
		a_min[i] = col;
		a_max[i] = col;
	}

	build_heap(a_min, n, cmp_min);
	build_heap(a_max, n, cmp_max);

	dump(a_max, a_min, n, cnt);

	int result = *a_max[0] - *a_min[0];

	delete [] a_min;
	delete [] a_max;

	return result;
}

int main(void) {

		{ // 1
		int a[] = {5, 8, 3, 1, 5, 6, 9, 9, 2, 2, 4};
		int r = solution(a, int(sizeof(a) / sizeof(a[0])), 2);

		if(r != 6)
			cout << "1. ERROR: " << r << endl;
		else
			cout << "1. OK: " << r << endl;
	}

	{ // 2
		int a[] = {5, 8, 3, 1, 5, 6, 9, 9, 2, 2, 4};
		int r = solution(a, int(sizeof(a) / sizeof(a[0])), 5);

		if(r != 4)
			cout << "2. ERROR: " << r << endl;
		else
			cout << "2. OK: " << r << endl;
	}


	return 0;
}
