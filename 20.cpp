// 20. Topological sort: in-degree analysis + BFS
#include <iostream>
using namespace std;

class list {
public:
	int val;
	list *next;
public:
	list(int v) : val(v), next(NULL) {}
};

class node {
public:
	int tag;
	list *out_edges;
	int in_degree;
};

node *G = NULL;
node *sorted_G = NULL;
int V = 0;
int E = 0;

void topological_sort() {
	// 1. Calc initial in-degree
	for(int i = 0; i < V; i ++) {
		list *h = G[i].out_edges;
		while(h) {
			G[h->val].in_degree ++;
			h = h->next;
		}
	}

	// 2. pop nodes with in-degree = 0 to start the sort
	node *st = new node[V];
	int st_size = 0;
	for(int i = 0; i < V; i ++) {
		if(G[i].in_degree == 0)
			st[st_size ++] = G[i];
	}

	// 3. Topological sort: in-degree analysis + BFS
	int sorted_idx = 0;
	while(st_size) {
		node n = st[--st_size];
		sorted_G[sorted_idx++] = n;
		list *h = n.out_edges;
		while(h) {
			G[h->val].in_degree--;
			if(G[h->val].in_degree == 0)
				st[st_size ++] = G[h->val];
			h = h->next;
		}
	}

	delete [] st;
}

int main(void) {

	{ // 1
		// Test case input
		V = 9;
		E = 9;
		const int test_case[] =
			{4, 1, 1, 2, 2, 3, 2, 7, 5, 6, 7, 6, 1, 5, 8, 5, 8, 9};

		// Preparing a graph
		G = new node[V];
		sorted_G = new node[V];

		for(int i = 0; i < V; i ++) {
			G[i].tag = i;
			G[i].out_edges = NULL;
			G[i].in_degree = 0;
		}

		for(int i = 0; i < E; i ++) {
			int n = test_case[2 * i] - 1;
			int out_n = test_case[2 * i + 1] - 1;
			if(!G[n].out_edges)
				G[n].out_edges = new list(out_n);
			else {
				list *h = G[n].out_edges;
				while(h->next)
					h = h->next;
				h->next = new list(out_n);
			}
		}

		// Sort
		topological_sort();

		for(int i = 0; i < V; i++)
			cout << int(sorted_G[i].tag  + 1) << " ";
		cout << endl;

		delete [] G;
		delete [] sorted_G;
	}

	{ // 2
		// Test case input
		V = 5;
		E = 4;
		const int test_case[] =
			{1, 2, 2, 3, 4, 1, 1, 5};

		// Preparing a graph
		G = new node[V];
		sorted_G = new node[V];

		for(int i = 0; i < V; i ++) {
			G[i].tag = i;
			G[i].out_edges = NULL;
			G[i].in_degree = 0;
		}

		for(int i = 0; i < E; i ++) {
			int n = test_case[2 * i] - 1;
			int out_n = test_case[2 * i + 1] - 1;
			if(!G[n].out_edges)
				G[n].out_edges = new list(out_n);
			else {
				list *h = G[n].out_edges;
				while(h->next)
					h = h->next;
				h->next = new list(out_n);
			}
		}

		// Sort
		topological_sort();

		for(int i = 0; i < V; i++)
			cout << int(sorted_G[i].tag  + 1) << " ";
		cout << endl;

		delete [] G;
		delete [] sorted_G;
	}

	return 0;
}
