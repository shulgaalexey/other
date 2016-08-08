// Build a spanning tree from a given set of edges
//
// Implemented with Kaskal alg and Partition ADT
// Total complexity is O(m*logm + n * logn)
// where m is a number of edges, n is a number of vertices

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
	int p1;
	int p2;
	int w;
};

class my_partition {
	private:
		vector<int> parents;
		vector<int> sizes;
	public:
		void make(const vector<edge> &E);
		void unite(int A, int B);
		int find(int A);
};

void my_partition::make(const vector<edge> &E) {
	parents.clear();
	sizes.clear();

	int max_point = 0;
	for(size_t i = 0; i < E.size(); i ++) {
		if(E[i].p1 > max_point)
			max_point = E[i].p1;
		if(E[i].p2 > max_point)
			max_point = E[i].p2;
	}

	for(int i = 0; i <= max_point; i ++) {
		parents.push_back(i);
		sizes.push_back(1);
	}
}

void my_partition::unite(int A, int B) {
	if(sizes[A] < sizes[B])
		parents[A] = B;
	else
		parents[B] = A;
}

int my_partition::find(int A) {
	int p = parents[A];
	while(parents[p] != p)
		p = parents[p];
	return p;
}

bool _edge_cmp(const edge &A, const edge &B) {
	return A.w < B.w;
}

vector<edge> make_spanning_tree(vector<edge> &E) {
	vector<edge> tree;

	my_partition p;
	p.make(E);

	std::sort(E.begin(), E.end(), _edge_cmp);

	for(size_t i = 0; i < E.size(); i ++) {
		const edge e = E[i];
		const int A = p.find(e.p1);
		const int B = p.find(e.p2);
		if(A != B) {
			p.unite(A, B);
			tree.push_back(e);
		}
	}
	return tree;
}

char tochar(int n) {
	return char('A' + n);
}

int main(void) {
	// p1, p2, weight
	const edge edges[] = {
		{0, 1, 5},
		{0, 2, 7},
		//{1, 0, 5},  // dublicate, may be deleted
		{1, 2, 8},
		{1, 3, 11},
		{1, 4, 10},
		//{2, 0, 7},  // dublicate, may be deleted
		//{2, 1, 8},  // dublicate, may be deleted
		{2, 3, 9},
		{2, 4, 13},
		//{3, 1, 11}, // dublicate, may be deleted
		//{3, 2, 9},  // dublicate, may be deleted
		{3, 4, 12},
		{3, 5, 6},
		//{4, 1, 10}, // dublicate, may be deleted
		//{4, 2, 13}, // dublicate, may be deleted
		//{4, 3, 12}, // dublicate, may be deleted
		{4, 5, 18},
		//{5, 3, 6},  // dublicate, may be deleted
		//{5, 4, 18}  // dublicate, may be deleted
	};

	vector<edge> E;
	for(int i = 0; i < int(sizeof(edges) / sizeof(edges[0])); i ++)
		E.push_back(edges[i]);
	cout << "Initial graph:" << endl;
	for(size_t i = 0; i < E.size(); i ++)
		cout << tochar(E[i].p1) << " - " << tochar(E[i].p2) << ", weight: " << E[i].w << endl;


	vector<edge> tree = make_spanning_tree(E);

	int total_length = 0;
	cout << "Spanning tree:" << endl;
	for(size_t i = 0; i < tree.size(); i ++) {
		cout << tochar(tree[i].p1) << " - " << tochar(tree[i].p2) << endl;
		total_length += tree[i].w;
	}
	cout << "total length: " << total_length << endl;


	return 0;
}
