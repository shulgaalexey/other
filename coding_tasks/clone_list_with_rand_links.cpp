// Clone a linked list with next and random pointer
#include <iostream>
#include <ctype.h>
using namespace std;

struct list {
	char data;
	list *next;
	list *rand;
	list(char ch) : data(ch), next(NULL), rand(NULL) {}
};

void print_list(list *l) {

	while(l) {
		cout << l->data;
		if (l->rand)
			cout << "(" << l->rand->data << ")";
		cout << " ";
		l = l->next;
	}
	cout << endl;
}

list *clone_list(list *l) {

	if (!l)
		return NULL;

	// 1. Insert dublicate items to the original list
	list *head = l;
	while (head) {
		list *next = head->next;
		list *new_item = new list(toupper(head->data));
		head->next = new_item;
		new_item->next = next;
		head = next;
	}

	// 2. Assign random links in new list corresponding to random links in old list
	head = l;
	while (head) {
		head->next->rand = head->rand->next;
		head = head->next->next;
	}

	// 3. Extracting clonned list
	list *cloned = l->next;
	while (cloned && cloned->next) {
		cloned->next = cloned->next->next;
		cloned = cloned->next;
	}


	return l->next;
}

int main(void) {
	list *a = new list('a');
	list *b = new list('b');
	list *c = new list('c');
	list *d = new list('d');
	list *e = new list('e');

	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;

	a->rand = c;
	b->rand = e;
	c->rand = b;
	d->rand = a;
	e->rand = c;

	print_list(a);

	list *cloned = clone_list(a);

	print_list(cloned);

	return 0;
}
