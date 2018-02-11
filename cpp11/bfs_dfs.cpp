#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#include <algorithm>

template <typename T>
class node {
	std::vector<node<T> *> adj;
	bool visited;
	T data;
public:
	node(const T &_data) : visited(false), data(_data) {}
public:
	void set_adjacent(const std::vector<node<T> *> &_adj) {
		adj = std::move(_adj);
	}
	std::vector<node<T> *> adjacent() const { return adj; }
	void visit() { visited = true; }
	bool is_visited() const { return visited; }
	T get_data() const { return data; }
};

//==========================
//             -- d
//     -- b -- |
//		 |       -- e
// a --|          |
//     |       -- f
//     -- c -- |
//             -- g
//==========================
using TNode = node<char>;

void bfs_demo() {
	auto a = std::make_unique<TNode>('a');
	auto b = std::make_unique<TNode>('b');
	auto c = std::make_unique<TNode>('c');
	auto d = std::make_unique<TNode>('d');
	auto e = std::make_unique<TNode>('e');
	auto f = std::make_unique<TNode>('f');
	auto g = std::make_unique<TNode>('g');

	a->set_adjacent({b.get(), c.get()});
	b->set_adjacent({a.get(), d.get(), e.get()});
	c->set_adjacent({a.get(), f.get(), g.get()});
	d->set_adjacent({b.get()});
	e->set_adjacent({b.get(), f.get()});
	f->set_adjacent({c.get(), e.get()});
	g->set_adjacent({c.get()});


	// Trace all reachable nodes
	auto &start = a;
	std::queue<TNode *> q;
	q.push(start.get());
	start->visit();

	while (!q.empty()) {
		auto n = q.front();
		q.pop();
		std::cout << "Visit: " << n->get_data() << std::endl;
		for (auto cur: n->adjacent()) {
			if (!cur->is_visited()) {
				q.push(cur);
				cur->visit();
			}
		}
	}
	std::cout << std::endl;
}

//==========================
//             -- d
//     -- b -- |
//		 |       -- e
// a --|          |
//     |       -- f
//     -- c -- |
//             -- g
//==========================
void do_dfs(TNode *n) {
	std::cout << "Visiting: " << n->get_data() << std::endl;
	n->visit();
	auto adj = n->adjacent();
	std::for_each(std::begin(adj), std::end(adj), [](TNode *r) {
			if (!r->is_visited())
			do_dfs(r);
			});
};

void dfs_demo() {
	auto a = std::make_unique<TNode>('a');
	auto b = std::make_unique<TNode>('b');
	auto c = std::make_unique<TNode>('c');
	auto d = std::make_unique<TNode>('d');
	auto e = std::make_unique<TNode>('e');
	auto f = std::make_unique<TNode>('f');
	auto g = std::make_unique<TNode>('g');

	a->set_adjacent({b.get(), c.get()});
	b->set_adjacent({a.get(), d.get(), e.get()});
	c->set_adjacent({a.get(), f.get(), g.get()});
	d->set_adjacent({b.get()});
	e->set_adjacent({b.get(), f.get()});
	f->set_adjacent({c.get(), e.get()});
	g->set_adjacent({c.get()});


	// Trace all nodes
	auto graph =
		{a.get(), b.get(), c.get(), d.get(), e.get(), f.get(), g.get()};
	std::for_each(std::begin(graph), std::end(graph), [](auto n){
			if (!n->is_visited())
				do_dfs(n);
			});
}

int main(void) {
	//bfs_demo();
	dfs_demo();
	return 0;
}
