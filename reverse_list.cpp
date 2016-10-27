#include <iostream>
using namespace std;

struct Node {
	Node *next;
	int data;
	Node(int d) : next(NULL), data(d) {}
};

Node *reverse(Node *head) {
	Node *cur = head;
	Node *head1 = head;
	while(cur->next) {
		Node *next = cur->next;
		Node *next_next = (next) ? next->next : NULL;
		next->next = head1;
		head1 = next;
		cur->next = next_next;
	}
	return head1;
}

void trace(Node *l) {
	while(l) {
		cout << l->data << " ";
		l = l->next;
	}
	cout << endl;
}

int main(void) {
	Node *n1 = new Node(1);
	Node *n2 = new Node(2);
	Node *n3 = new Node(3);
	Node *n4 = new Node(4);
	Node *n5 = new Node(5);
	Node *n6 = new Node(6);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;

	trace(n1);

	Node *r = reverse(n1);

	trace(r);

	return 0;
}
