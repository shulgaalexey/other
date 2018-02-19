#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 6;
const int M = 7;

int PRESET[N][M] = {
	{0, 0, 1, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 1},
	{0, 0, 1, 0, 0, 0, 0},
	{0, 0, 1, 0, 1, 0, 1},
	{0, 0, 0, 0, 1, 0, 1},
	{0, 0, 0, 0, 1, 0, 0}
};

int G[N][M] = {0};
vector<pair<int, int>> P;

bool find_path(int i, int j) {
	if ((i < 0) || (j < 0) || (i >= N) || (j >= M))
		return false;

	if ((i == 0) && (j == 0)) {
		for (auto &p: P) {
			G[p.first][p.second] = 8;
		}
	}

	if (G[i][j])
		return false; // already visited

	G[i][j] = 2; // visited
	P.push_back(pair<int, int>(i, j));

	return find_path(i - 1, j) || find_path(i, j - 1) ||
		find_path(i + 1, j) || find_path(i, j + 1);
}

bool find_path_bfs() {
	queue<pair<int, int>> q;
	q.push(pair<int, int>(N - 1, M - 1));
	G[N - 1][M - 1] = 4; // Finish

	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		if ((p.first == 0) && (p.second == 0))
			return true; // yay!!!

		// code : action : alg goto
		//    5 : v      : N
		//    6 : >      : W
		//    7 : ^      : S
		//    8 : <      : E
		//
		// vector<point, code>
		vector<pair<pair<int, int>, int>> candidates;
		candidates.push_back(make_pair(make_pair(p.first - 1, p.second), 5));
		candidates.push_back(make_pair(make_pair(p.first, p.second - 1), 6));
		candidates.push_back(make_pair(make_pair(p.first + 1, p.second), 7));
		candidates.push_back(make_pair(make_pair(p.first, p.second + 1), 8));

		for (auto &a: candidates) {
			const pair<int, int> cell = a.first;
			const int code = a.second;
			if ((cell.first >= 0) && (cell.second >= 0) &&
					(cell.first < N) && (cell.second < M) &&
					!G[cell.first][cell.second]) {
				q.push(cell);
				G[cell.first][cell.second] = code;
			}
		}
	}
	return false;
}

void print() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
}

void print_dir() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			switch (G[i][j]) {
				case 1: cout << "#"; break;
				case 4: cout << "F"; break;
				case 5: cout << "v"; break;
				case 6: cout << ">"; break;
				case 7: cout << "^"; break;
				case 8: cout << "<"; break;
				default: cout << "*"; break;
			}
			cout << " ";
		}
		cout << endl;
	}

	cout << endl;

	// Reconstructing the path
	P.push_back(make_pair(0, 0));
	while (true) {
		auto p = P.back();
		if ((p.first == (N - 1)) && (p.second == (M - 1))) {
			cout << 'F' << endl;
			break;
		}
		switch (G[p.first][p.second]) {
			case 5:
				cout << 'v' << " ";
				P.push_back(make_pair(p.first + 1, p.second));
				break;
			case 6:
				cout << '>' << " ";
				P.push_back(make_pair(p.first, p.second + 1));
				break;
			case 7:
				cout << '^' << " ";
				P.push_back(make_pair(p.first - 1, p.second));
				break;
			case 8:
				cout << '<' << " ";
				P.push_back(make_pair(p.first, p.second - 1));
				break;
			default: cout << "?" << endl; break;
		}
	}
}

void set_graph() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			G[i][j] = PRESET[i][j];

	P.clear();
}

int main(void) {
	{
		set_graph();
		print();
		cout << endl;
		find_path(N - 1, M - 1);
		print();
	}

	cout << "\n====================\n\n";

	{
		set_graph();
		print();
		cout << endl;
		find_path_bfs();
		print_dir();
	}

	return 0;
}
