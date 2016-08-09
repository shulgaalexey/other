// Matrix Chain Product problem
// Given an array p[] with dimensions of matrices.
// Matrix A[i] has dimensions p[i - 1] x p[i].
// Find minimum number of multiplications needed to multiply the chain.

#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;



// !!! n is a number of matrices, so the size of p is (n + 1)
int find_min_mul(int *p, const int n) {

	int c[n][n];

	// Initial fill (optional)
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
			c[i][j] = -1;

	// Diagonal 1
	for(int i = 1; i < n; i ++)
		c[i][i] = 0;

	// Diagonal d, d >= 2
	for(int d = 2; d < n; d ++) {
		// Fill entities in diagonal d
		for(int i = 1; i <= (n - d + 1); i ++) {
			// compute c[i][j]
			int j = i + d - 1;
			c[i][j] = INT_MAX;
			for(int k = i; k <= j; k ++) {
				int v = c[i][k] + c[k + 1][j] + p[i - 1] * p[k] * p[j];
				if(v < c[i][j]) {
					c[i][j] = v;
				}
			}
		}
	}

	return c[1][n -1];
}

int main(void) {
	{ // 1
		//int p[] = {40, 20, 30, 10, 30};
		int p[] = {4, 2, 3, 1, 3};
		const int m = find_min_mul(p, (sizeof(p)/sizeof(p[0])));
		cout << m << endl;
		if(m != 26)
			cout << "ERROR1" << endl;
	}

	{ // 2
		int p[] = {10, 20, 30, 40, 30};
		const int m = find_min_mul(p, (sizeof(p)/sizeof(p[0])));
		cout << m << endl;
		if(m != 30000)
			cout << "ERROR2" << endl;
	}

	{ // 3
		int p[] = {10, 20, 30};
		const int m = find_min_mul(p, (sizeof(p)/sizeof(p[0])));
		cout << m << endl;
		if(m != 6000)
			cout << "ERROR3" << endl;
	}
	return 0;
}
