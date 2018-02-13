#include <iostream>
#include <vector>
#include <algorithm> // for final check
#include <string> // for trace
using namespace std;

void merge(vector<int> &arr, int p1, int p2, int finish, vector<int> &tmp) {
	int i = p1;
	int j = p2;
	int k = p1;

	while ((i < p2) && (j <= finish)) {
		if (arr[j] < arr[i])
			tmp[k++] = arr[j++];
		else
			tmp[k++] = arr[i++];
	}

	while (i < p2)
		tmp[k++] = arr[i++];
	while (j <= finish)
		tmp[k++] = arr[j++];

	for (k = p1; k <= finish; k++)
		arr[k] = tmp[k];
}

void split_and_sort(vector<int> &arr, int start, int finish, vector<int> &tmp) {
	if (start >= finish)
		return;
	if ((finish - start) == 1) {
		if (arr[start] > arr[finish])
			std::swap(arr[start], arr[finish]);
		return;
	}

	const int mid = start + (finish - start) / 2;
	split_and_sort(arr, start, mid, tmp);
	split_and_sort(arr, mid + 1, finish, tmp);
	merge(arr, start, mid + 1, finish, tmp);
}

void msort(vector<int> &arr) {
	vector<int> tmp(arr.size());
	split_and_sort(arr, 0, arr.size() - 1, tmp);
}

void print(const string &tag, const vector<int> &arr) {
	cout << tag;
	for (size_t i = 0; i < arr.size(); ++i)
		cout << arr[i] << " ";
	cout << endl;
}

int main(void) {
	vector<int> arr = {13, 7, 6, 45, 21, 9, 101, 102};
	vector<int> arr2 = arr;
	print("Origin: ", arr);
	msort(arr);
	print("Sorted: ", arr);
	std::sort(begin(arr2), end(arr2));
	print("Needed: ", arr2);
	return 0;
}
