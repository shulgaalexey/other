// Find palindromes of a specified length in a matrix NxN.
// Solution: calculate floating hash (simplified Karp-Rabin method)
// for each row a) left to right and b) right to left. Length of the window is a
// half of specified palindrom length. Positions when ltr_hash == rtl_hash
// indicate palindroms.
// Same approach is taken for columns.

#include <iostream>
#include <iomanip>
using namespace std;

int calc_palindroms(char *a, int N, int length) { // N <= 8
	int total = 0;
	const int half_length = length / 2 + length % 2;
	unsigned int mask = (-1) << 8 * half_length;
	mask = ~mask;
	//cout << "mask: " << hex << setw(8) << mask << endl;

	// 1. Calc using simplified Karp-Rabin left-to-right and right-to-left
	int *ltr = new int[N];
	int *rtl = new int[N];
	for(int i = 0; i < N ; i ++) {

		int hash = 0;
		int hash_length = 0;
		for(int j = 0; j < N; j ++) {
			hash_length ++;
			hash = hash | (0x000000FF & a[i * N + j]);
			if(hash_length < half_length)
				ltr[j] = 0;
			else
				ltr[j] = hash;
			hash <<= 8;
			hash &= mask;
		}

		hash = 0;
		hash_length = 0;
		for(int j = (N - 1); j >= 0; j --) {
			hash_length ++;
			hash = hash | (0x000000FF & a[i * N + j]);
			if(hash_length < half_length)
				rtl[j] = 0;
			else
				rtl[j] = hash;
			hash <<= 8;
			hash &= mask;
		}

		if(length %2) {
			for(int j = 0; j < N; j ++) {
				if(!ltr[j] || !rtl[j])
					continue;
				if(ltr[j] == rtl[j]) {
					total ++;

					/*cout << "(" << i << ", " << j << ")"
						<< endl;*/
				}
			}
		} else {
			for(int j = 1; j < N; j ++) {
				if(!ltr[j - 1] || !rtl[j])
					continue;
				if(ltr[j - 1] == rtl[j]) {
					total ++;

					/*cout << "(" << i << ", " << j << ")"
						<< endl;*/
				}
			}
		}
	}
	delete [] ltr;
	delete [] rtl;

	// 2. Calc using simplified Karp-Rabin top-to-bottom and bottom-to-top
	int *ttb = new int[N];
	int *btt = new int[N];
	for(int j = 0; j < N ; j ++) {
		int hash = 0;
		int hash_length = 0;
		for(int i = 0; i < N; i ++) {
			hash_length ++;
			hash = hash | (0x000000FF & a[i * N + j]);
			if(hash_length < half_length)
				ttb[i] = 0;
			else
				ttb[i] = hash;
			hash <<= 8;
			hash &= mask;
		}

		hash = 0;
		hash_length = 0;
		for(int i = (N - 1); i >= 0; i --) {
			hash_length ++;
			hash = hash | (0x000000FF & a[i * N + j]);
			if(hash_length < half_length)
				btt[i] = 0;
			else
				btt[i] = hash;
			hash <<= 8;
			hash &= mask;
		}

		if(length %2) {
			for(int i = 0; i < N; i ++) {
				if(!ttb[i] || !btt[i])
					continue;
				if(ttb[i] == btt[i]) {
					total ++;

					/*cout << "(" << i << ", " << j << ")"
						<< endl;*/
				}
			}
		} else {
			for(int i = 1; i < N; i ++) {
				if(!ttb[i - 1] || !btt[i])
					continue;
				if(ttb[i - 1] == btt[i]) {
					total ++;

					/*cout << "(" << i << ", " << j << ")"
						<< endl;*/
				}
			}

		}
	}
	delete [] ttb;
	delete [] btt;

	return total;
}

const char A = 'A';
const char B = 'B';
const char C = 'C';

/*
const char A = 0xAA;
const char B = 0xBB;
const char C = 0xCC;
*/

int main(void) {
	const int N = 8;
	char a[] = {
		C, B, C, A, B, B, A, C,
		B, B, A, B, C, A, B, A,
		A, B, C, B, C, C, C, A,
		B, A, C, C, A, A, B, B,
		B, C, B, C, A, C, B, C,
		C, A, B, A, C, A, C, B,
		C, A, A, A, C, C, A, B,
		C, B, A, B, A, C, A, C
	};

	int r = calc_palindroms(a, N, 5);
	cout << r << endl;
	if(r != 5)
		cout << "ERROR" << endl;
	else
		cout << "OK" << endl;

	return 0;
}
