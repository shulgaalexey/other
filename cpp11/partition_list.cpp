#include <iostream>
using namespace std;

template <typename T>
struct list {
	list<T> *next;
	T data;
};

template <typename T>
list<T> *partition(list<T> *l, const T &pivot) {
	list<T> *head = l;
	list<T> *cur = l->next;
	list<T> *prev = l;

	while (cur) {
		if (cur->data < pivot) {
			prev->next = cur->next;
			cur->next = head;
			head = cur;
			cur = prev->next;
		} else {
			cur = cur->next;
		}
	}
	return head;
}

template <typename T>
void trace(list<T> *l) {
	while (l) {
		cout << l->data << " ";
		l = l->next;
	}
	cout << endl;
}

int main(void) {
	list<int> *l5 = new list<int>{nullptr, 7};
	list<int> *l4 = new list<int>{l5, 1};
	list<int> *l3 = new list<int>{l4, 2};
	list<int> *l2 = new list<int>{l3, 3};
	list<int> *l1 = new list<int>{l2, 8};

	trace(l1);

	list<int> *partitioned = partition(l1, 5);

	trace(partitioned);

	list<int> *l = l1;
	while (l) {
		list<int> *del = l;
		l = l->next;
		delete del;
	}

	return 0;
}
