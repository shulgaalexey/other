// Save all leaf nodes of a Binary tree in a Doubly Linked List by using Right
// node as Next node and Left Node as Previous Node.
#include <iostream>
using namespace std;

struct tree_list {
	char data;
	tree_list *left_prev;
	tree_list *right_next;
	tree_list(char c) : data(c), left_prev(NULL), right_next(NULL) {}
};


tree_list *get_tail(tree_list *tl) {

	while (tl && tl->right_next)
		tl = tl->right_next;

	return tl;
}

tree_list *get_head(tree_list *tl) {

	while (tl && tl->left_prev)
		tl = tl->left_prev;
	return tl;
}

tree_list *to_list(tree_list *tl) {

	if (!tl)
		return NULL;

	if (tl->left_prev) {
		tree_list *l = to_list(tl->left_prev);
		l = get_tail(l);
		tl->left_prev = l;
		if (l)
			l->right_next = tl;
	}

	if (tl->right_next) {
		tree_list *l = to_list(tl->right_next);
		l = get_head(l);
		tl->right_next = l;
		if (l)
			l->left_prev = tl;
	}

	return tl;
}

int main(void) {

	{ // Test 0
		tree_list *a = new tree_list('a');
		tree_list *b = new tree_list('b');
		tree_list *c = new tree_list('c');

		a->left_prev = b;
		a->right_next = c;

		tree_list *l = to_list(a);
		l = get_head(l);

		while (l) {
			cout << l->data << " ";
			tree_list *tmp = l;
			l = l->right_next;
			delete tmp;
		}
		cout << endl;
	}

	{ // Test 1
		tree_list *a = new tree_list('a');
		tree_list *b = new tree_list('b');
		tree_list *c = new tree_list('c');
		tree_list *d = new tree_list('d');
		tree_list *e = new tree_list('e');

		a->left_prev = b;
		a->right_next = c;

		b->left_prev = d;
		b->right_next = e;

		tree_list *l = to_list(a);
		l = get_head(l);

		while (l) {
			cout << l->data << " ";
			tree_list *tmp = l;
			l = l->right_next;
			delete tmp;
		}
		cout << endl;
	}

	{ // Test 2
		tree_list *a = new tree_list('a');
		tree_list *b = new tree_list('b');
		tree_list *c = new tree_list('c');
		tree_list *d = new tree_list('d');
		tree_list *e = new tree_list('e');
		tree_list *f = new tree_list('f');
		tree_list *g = new tree_list('g');

		a->left_prev = b;
		a->right_next = c;

		b->left_prev = d;
		b->right_next = e;

		e->left_prev = g;

		c->right_next = f;

		tree_list *l = to_list(a);
		l = get_head(l);

		while (l) {
			cout << l->data << " ";
			tree_list *tmp = l;
			l = l->right_next;
			delete tmp;
		}
		cout << endl;
	}

	return 0;
}

