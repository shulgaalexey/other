// 17. Find the similarity of two streams
// (including possible insertions and deletions)

#include <iostream>
using namespace std;

double get_similarity(const char *X, const char *Y, int N) {
	int *b1 = new int[N];
	int *b2 = new int[N];

	int max_len = 0;

	int *p1 = b1;
	int *p2 = b2;

	// First line of prefix length matrix
	p1[0] = (X[0] == Y[0]) ? 1 : 0;
	for(int j = 1; j < N; j ++)
		p1[j] = (X[j] == Y[j]) ? 1 : p1[j - 1];

	// Estimating the matrix of prefix lengths
	for(int i = 1; i < N; i ++) {
		p2[0] = (X[0] == Y[i]) ? 1 : p1[0];
		for(int j = 1; j < N ; j ++) {
			if((X[j] == Y[i]) && (p1[j] == p2[j - 1]))
				p2[j] = p1[j - 1] + 1;
			p2[j] = max(p2[j],
				    max(p1[j - 1],
					max(p1[j], p2[j - 1])));
		}
		max_len = p2[N - 1];
		int *tmp = p1;
		p1 = p2;
		p2 = tmp;
	}

	delete [] b1;
	delete [] b2;

	return (max_len > 0) ? (100. * max_len / N) : .0;
}

int main(void) {
	double d = get_similarity("RBKBGRBGGG",
				  "BGKRBRKBGB",
				  10);
	if((d < 0.59) || (d > 0.61))
		cout << "ERROR: " << d << endl;
	else
		cout << "OK: " << d << endl;
	return 0;
}
