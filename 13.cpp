// 13. Finding Matrices
#include <iostream>
using namespace std;

struct list {
	int r;
	int c;
	int s;
	list *next;
};

list *head;
int cnt;

int N;
int *a;
int M;

void solution() {

	for(int i = 1; i < (M -1); i ++) {
		for(int j = 1; j < (M - 1); j ++) {
			if(!a[i * M + j]
			   || a[(i + 1) * M + j] || a[i * M + j + 1])
				continue;

			cnt ++;

			int ic = i;
			int rows = 0;
			while(a[ic * M + j]) {
				ic --;
				rows ++;
			}

			int jc = j;
			int cols = 0;
			while(a[i * M + jc]) {
				jc --;
				cols ++;
			}

			list *l = new list;
			l->c = cols;
			l->r = rows;
			l->s = cols * rows;
			l->next = NULL;

			if(!head)
				head = l;
			else {
				list *p1 = head;
				list *p2 = NULL;
				while(p1 && (p1->s < l->s)) {
					p2 = p1;
					p1 = p1->next;
				}
				if(p2) {
					p2->next = l;
					l->next = p1;
				} else {
					l->next = head;
					head = l;
				}
			}

		}
	}
}

int main(void) {
	{ //1
		N = 9;
		M = N + 2;
		int G[] = {
			1, 1, 3, 2, 0, 0, 0, 0, 0,
			3, 2, 5, 2, 0, 0, 0, 0, 0,
			2, 3, 3, 1, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 4, 5, 5, 3, 1,
			1, 2, 5, 0, 3, 6, 4, 2, 1,
			2, 3, 6, 0, 2, 1, 1, 4, 2,
			0, 0, 0, 0, 4, 2, 3, 1, 1,
			0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0
		};

		a = new int [M * M];

		// Make borders 0
		for(int i = 0; i < M; i ++)
			a[i] = 0;
		for(int i = 0; i < M; i ++)
			a[M * (M - 1) + i] = 0;
		for(int i = 0; i < M; i ++)
			a[i * M] = 0;
		for(int i = 0; i < M; i ++)
			a[i * M + M - 1] = 0;

		for(int i = 1; i < (M - 1); i ++) {
			for(int j = 0; j < N; j ++) {
				a[i * M + 1 + j] = G[(i - 1) * N + j];
			}
		}

		head = NULL;
		cnt = 0;

		solution();

		cout << "#1 " << cnt << " ";
		list *p = head;
		while(p) {
			cout << p->r << " " << p->c << " ";
			p = p->next;
		}
		cout << endl;

		p = head;
		while(p) {
			list *p1 = p->next;
			delete p;
			p = p1;
		}


		/*for(int i = 0; i < M; i ++) {
			for (int j = 0; j < M; j ++) {
				cout << a[i * M + j] << " ";
			}
			cout << endl;
		}*/

		delete [] a;
	}

	{ //2
		N = 4;
		M = N + 2;
		int G[] = {
			1, 2, 0, 0,
			0, 0, 0, 0,
			9, 4, 2, 0,
			1, 7, 3, 0
		};

		a = new int [M * M];

		// Make borders 0
		for(int i = 0; i < M; i ++)
			a[i] = 0;
		for(int i = 0; i < M; i ++)
			a[M * (M - 1) + i] = 0;
		for(int i = 0; i < M; i ++)
			a[i * M] = 0;
		for(int i = 0; i < M; i ++)
			a[i * M + M - 1] = 0;

		for(int i = 1; i < (M - 1); i ++) {
			for(int j = 0; j < N; j ++) {
				a[i * M + 1 + j] = G[(i - 1) * N + j];
			}
		}

		head = NULL;
		cnt = 0;

		solution();

		cout << "#2 " << cnt << " ";
		list *p = head;
		while(p) {
			cout << p->r << " " << p->c << " ";
			p = p->next;
		}
		cout << endl;

		p = head;
		while(p) {
			list *p1 = p->next;
			delete p;
			p = p1;
		}


		/*for(int i = 0; i < M; i ++) {
			for (int j = 0; j < M; j ++) {
				cout << a[i * M + j] << " ";
			}
			cout << endl;
		}*/

		delete [] a;
	}
	return 0;
}
