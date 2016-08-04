// Cool iterative find of min and max in (3n/2 + 2) complexity
// Regular minmax performs on 2n + 2, so the cool one is 25% faster
// However, the simple experiment shows:
// Cool 9
// Regular 4
// The smallest number is better
// TODO check more
#include <iostream>
#include <climits>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
using namespace std;

void cool_minmax(int *a, const int n, int *min, int *max) {
	if(n % 2) {
		*min = a[n - 1];
		*max = a[n - 1];
	} else {
		*min = INT_MAX;
		*max = INT_MIN;
	}

	int idx = 0;
	for(int i = 1; i <= int(n / 2); i ++) {
		//const int a1 = a[2 * i - 2];
		//const int a2 = a[2 * i - 1];
		const int a1 = a[idx ++];
		const int a2 = a[idx ++];
		if(a1 < a2) {
			if(a1 < (*min))
				*min = a1;
			if(a2 > (*max))
				*max = a2;
		} else {
			if(a2 < (*min))
				*min = a2;
			if(a1 > (*max))
				*max = a1;
		}
	}
}

void regular_minmax(int *a, const int n, int *min, int *max) {
	*min = INT_MAX;
	*max = INT_MIN;
	for(int i = 0; i < n; i ++) {
		if(a[i] < (*min))
			*min = a[i];
		if(a[i] > (*max))
			*max = a[i];
	}
}


unsigned long GetTickCount()
{
	struct timeval tv;
	if(gettimeofday(&tv, NULL) != 0)
		return 0;

	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

int main(void) {
	{ // 1
		int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		int min = INT_MAX;
		int max = INT_MIN;
		cool_minmax(a, (sizeof(a) / sizeof(a[0])), &min, &max);
		if((min != 0) || (max != 9))
			cout << "Error1" << endl;
	}

	{ // 2
		int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
		int min = INT_MAX;
		int max = INT_MIN;
		cool_minmax(a, (sizeof(a) / sizeof(a[0])), &min, &max);
		if((min != 0) || (max != 8))
			cout << "Error2" << endl;
	}


	{
		srand(time(NULL));

		const int n = 1000000;
		int *a = new int[n];
		for(int i = 0; i < n; i ++)
			a[i] = rand();

		int min_cool = INT_MAX;
		int max_cool = INT_MIN;
		int min_regular = INT_MAX;
		int max_regular = INT_MIN;

		const unsigned long t1_cool = GetTickCount();
		cool_minmax(a, n, &min_cool, &max_cool);
		const unsigned long t2_cool = GetTickCount();


		const unsigned long t1_regular = GetTickCount();
		regular_minmax(a, n, &min_regular, &max_regular);
		const unsigned long t2_regular = GetTickCount();

		if((min_cool != min_regular) || (max_cool != max_regular))
			cout << "ERROR rnd" << endl;

		cout << "COOL: " << (unsigned long)(t2_cool - t1_cool) << endl;
		cout << "REGULAR: " << (unsigned long)(t2_regular - t1_regular) << endl;

		delete [] a;
	}

	return 0;
}
