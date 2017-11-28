// Serialise and Deserialise a linked list with next and random pointer.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct list {
	char data;
	list *next;
	list *rand;
	list(char ch) : data(ch), next(NULL), rand(NULL) {}
};

struct list_idx : public list {
	int idx;
	list_idx(int n) : list('#'), idx(n) {}
};

void print_list(list *l, const char *label) {

	if (label)
		cout << endl<< label << endl;

	while(l) {
		cout << l->data;
		if (l->rand)
			cout << "(" << l->rand->data << ")";
		cout << " ";
		l = l->next;
	}
	cout << endl;
}

typedef list * list_ptr;

void serialize_list(list *l) {
	ofstream out_file("list.dat");
	if (out_file.is_open()) {

		// 1. Save all list items
		list *head = l;
		while (head) {
			out_file << head->data;
			head = head->next;
		}
		out_file << endl;

		// 2. Insert after each item its index
		head = l;
		int i = 0;
		while (head) {
			list *next = head->next;
			head->next = new list_idx(i++);
			head->next->next = next;
			head = next;
		}

		// 3. save all indexes of rand link
		head = l;
		while (head) {
			list_idx *idx = (list_idx *)head->rand->next;
			out_file << idx->idx;
			head = head->next->next;
		}
		out_file << endl;

		// 4. Remove all indexes
		head = l;
		while (head) {
			list_idx *idx = (list_idx *)head->next;
			list *next = idx->next;
			delete idx;
			head->next = next;
			head = next;
		}

		out_file.close();
	} else {
		cout << "Unable to open file for serialization" << endl;
	}
}


list *deserialize_list() {

	list *restored = NULL;

	ifstream in_file("list.dat");
	if (in_file.is_open()) {
		string line1;
		string line2;
		getline(in_file, line1);
		getline(in_file, line2);
		cout << endl << "Read from file:" << endl << line1 << endl << line2 << endl;

		const int N = line1.length();

		// 1. Reading all list items into buffer array
		list_ptr *buf = new list_ptr[N];
		for (int i = 0; i < N; i++) {
			buf[i] = new list(line1[i]);
			if (i > 0)
				buf[i - 1]->next = buf[i];
		}

		// 2. Assigning rand link
		for (int i = 0; i < N; i++) {
			int idx = line2[i] - '0';
			buf[i]->rand = buf[idx];
		}

		restored = buf[0];

		in_file.close();
	} else {
		cout << "Unable to open file for deserialization" << endl;
	}

	return restored;
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

	print_list(a, "initial list");

	serialize_list(a);

	print_list(a, "list after serialization. must be same as initial");

	list *restored = deserialize_list();

	print_list(restored, "restored list");

	return 0;
}
