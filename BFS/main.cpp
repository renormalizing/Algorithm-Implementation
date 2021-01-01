#include <iostream>
#include <list>
#include <queue>
using namespace std;
enum Color{WHITE, GREY, BLACK};
struct Vertex{
	int val;
	int d;
	Color color;
	Vertex *p;
};
class Graph{
private:
	int capacity, size;
	Vertex **vertices;
	list<Vertex*> *adj;
	void DFS_visit(Vertex* src);
public:
	explicit Graph(int capacity);
	void add_node(Vertex* v);
	void add_edge(Vertex* src,Vertex* dest);
	void print_adj();
	void bfs(Vertex* src);
	void dfs();
};

Graph::Graph(int capacity){
	this->capacity = capacity;
	this->size = 0;
	this->vertices = new Vertex*[capacity];
	this->adj = new list<Vertex*>[capacity];
}
void Graph::add_node(Vertex *v) {
	vertices[size++] = v;
}
void Graph::add_edge( Vertex* src,  Vertex* dest) {
	//directed graph
	this->adj[src->val-1].push_back(dest);
}
void Graph::print_adj() {
	for (int i = 0; i < size; ++i) {
		cout << i + 1 << ':';
		auto iter = adj[i].begin();
		while(iter!=adj[i].end()){
			cout << (*iter)->val << " ";
			iter++;
		}
		cout << endl;
	}
}
void Graph::bfs(Vertex* src) {
	for (int i = 0; i < size; ++i) {
		vertices[i]->color = WHITE;
	}
	queue<Vertex*> q;
	q.push(src);
	cout << src->val;
	while(!q.empty()){
		Vertex* v = q.front();
		q.pop();
		for (auto item : adj[v->val-1]) {
			if(item->color == WHITE){
				item->color = GREY;
				cout << ' ' <<item->val;
				item->d = v->d + 1;
				item->p = v;
				q.push(item);
			}
		}
		v->color = BLACK;
	}
}
void Graph::DFS_visit(Vertex *src) {
	src->color = GREY;
	cout << src->val << ' ';
	for(auto& v : adj[src->val-1]){
		if(v->color==WHITE)
			DFS_visit(v);
	}
	src->color = BLACK;
}
void Graph::dfs() {
	for (int i = 0; i < size; ++i) {
		vertices[i]->color = WHITE;
	}
	for (int i = 0; i < size; ++i) {
		if(vertices[i]->color == WHITE)
			DFS_visit(vertices[i]);
	}
}
int main() {
	Graph g(10);
	int data[] = {1,2,3,4};
	Vertex v[4];
	for(int i = 0; i < 4; ++i) {
		v[i] = Vertex{data[i], 0};
		g.add_node(v+i);
	}
	g.add_edge(v, v+1);
	g.add_edge(v, v+2);
	g.add_edge(v+1, v+3);
	g.print_adj();
	g.bfs(v);
	cout << endl;
	g.dfs();
	return 0;
}
