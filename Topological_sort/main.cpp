#include <iostream>
#include <list>
#include <vector>
enum Color{WHITE, GREY, BLACK};
using namespace std;

int t;
struct Node{
	int val;
	Color color;
	Node* p;
	int d, f;
	list<Node*> adj;
};
struct Graph{
	vector<Node*> V;
};
void DFS_visit(Node* v, list<Node*>& l){
	t++;
	v->d = t;
	v->color = GREY;
	for (const auto &u : v->adj) {
		if(u->color == WHITE) {
			u->p = v;
			DFS_visit(u, l);
		}
	}
	v->color = BLACK;
	t++;
	v->f = t;
	l.push_front(v);
}
list<Node*> Topological_sort(Graph& G){
	for (int i = 0; i < G.V.size(); ++i) {
		G.V[i]->color = WHITE;
	}
	t = 0;
	list<Node*> l;
	for (const auto &v : G.V) {
		if(v->color == WHITE){
			DFS_visit(v, l);
		}
	}
	return l;
}

int main() {
	Node a, b, c;
	a.val=1, b.val=2, c.val=3;
	a.adj = list<Node*>(),b.adj = list<Node*>(),c.adj = list<Node*>();
	a.adj.push_back(&c), c.adj.push_back(&b);
	Graph g;
	g.V = vector<Node*>();
	g.V.push_back(&a), g.V.push_back(&b), g.V.push_back(&c);
	list<Node*> l = Topological_sort(g);
	for (const auto &item : l) {
		cout << item->val << ' ';
	}
	return 0;
}
