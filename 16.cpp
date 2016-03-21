// Finding node with minimal distance to friends in an unweighted graph
// Input: adjacent matrix, number of nodes
#include <iostream>
using namespace std;

// Use BFS to traverse the graph and find distances to each node
int get_closer(int *M, int n) {
	int min_dist = 1000000;
	int *q = new int[n];
	int q_size = 0;
	bool *visited = new bool[n];
	int *level = new int[n];

	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < n; j ++)
			visited[j] = false;

		// Start from i-th node: push it to the queue
		q_size = 0;
		q[q_size++] = i;
		visited[i] = true;
		level[i] = 0;

		int dist = 0;

		// Do BFS
		while(q_size) {
			int cur_node = q[--q_size]; // pop a node from the queue
			for(int j = 0; j < n; j ++) {
				int friend_node = M[cur_node * n + j];
				if(friend_node && !visited[j]) {
					visited[j] = true;
					q[q_size ++] = j;
					level[j] = level[cur_node] + 1;
					dist += level[j];
				}
			}

			if(dist > min_dist)
				break; // i-th node is not the closest one
		}

		if(dist < min_dist)
			min_dist = dist;
	}

	delete [] q;
	delete [] visited;
	delete [] level;

	return min_dist;
}

int main(void) {
	{ // 1
		int M[] = {
			0, 1, 1, 0, 0,
			1, 0, 1, 1, 1,
			1, 1, 0, 0, 0,
			0, 1, 0, 0, 0,
			0, 1, 0, 0, 0
		};
		int cc = get_closer(M, 5);
		if(cc != 4)
			cout << "ERROR1: " << cc << endl;
	}

	{ // 2
		int M[] = {
			0, 0, 1, 1, 0,
			0, 0, 1, 0, 0,
			1, 1, 0, 0, 1,
			1, 0, 0, 0, 1,
			0, 0, 1, 1, 0
		};
		int cc = get_closer(M, 5);
		if(cc != 5)
			cout << "ERROR2: " << cc << endl;
	}

	return 0;
}
