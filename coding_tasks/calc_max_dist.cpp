// Given an array,find the maximum j – i such that arr[j] > arr[i]
#include <iostream>
using namespace std;

int main(void) {
	int a[] = {34, 8, 10, 3, 2, 80, 30, 33, 1};
	const int N = int(sizeof(a) / sizeof(a[0]));

	/* O(n^2)
	int len = 0;

	for (int i = 0; i < (N - 1); i++) {

		int j = i + 1;
		for (; ((j < N) && (a[j] > a[i])); j++);
		const int cur_len = j - i;

		if (cur_len > len)
			len = cur_len;
	}*/

	/* O(n) */
	int LMin[N];
	LMin[0] = a[0];
	for (int i = 1; i < N; i++)
		LMin[i] = std::min(LMin[i - 1], a[i]);

	int RMax[N];
	RMax[N - 1] = a[N - 1];
	for (int i = N - 2; i >= 0; i--)
		RMax[i] = std::max(RMax[i + 1], a[i]);

	int len = -1;
	int i = 0;
	int j = 0;
	while(j < N && i < N) {
		if (LMin[i] < RMax[j]) {
			len = std::max(len, j - i);
			j++;
		} else
			i++;
	}

	cout << len << endl;

	return 0;
}
