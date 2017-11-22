// Find all nodes at k-distance from a given node in a binary tree
#include <iostream>
#include <vector>
using namespace std;

struct tree {
	char data;
	tree *left;
	tree *right;
	tree(char ch) : data(ch), left(NULL), right(NULL) {}
};

vector<tree *> result;

void find_k_dist_nodes(tree *root, const int k) {

	if (!root)
		return;

	if (k == 0)
		result.push_back(root);
	else {
		find_k_dist_nodes(root->left, k - 1);
		find_k_dist_nodes(root->right, k - 1);
	}
}

int main(void) {
	tree *a = new tree('a');
	tree *b = new tree('b');
	tree *c = new tree('c');
	tree *d = new tree('d');
	tree *e = new tree('e');
	tree *f = new tree('f');
	tree *g = new tree('g');

	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;

	const int k = 2;
	find_k_dist_nodes(a, k);

	for (size_t i = 0; i < result.size(); i++)
		cout << result[i]->data << endl;

	return 0;
}

