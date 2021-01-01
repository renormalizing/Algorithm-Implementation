#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
template <typename T>
class Disjoin_Set{
	struct Node{
		T elem;
		int height;
	};
private:
	unordered_map<T, Node*> sets;
	unordered_map<T, Node*> parents;
public:
//	Disjoin_Set<T>(){sets = unordered_map<T, Node*>(), parents = unordered_map<T, Node*>();}
	void make_set(const T& elem){
		Node* n = new Node{elem, 0};
		sets[elem] = n;
		parents[elem] = NULL;
	}
	Node* find_set(T u){
		if(!parents[u])
			return sets[u];
		else{
			parents[u] = find_set(parents[u]->elem);
			return parents[u];
		}
	}
	void union_set(Node *u, Node *v){
		if(u->height > v->height)
			parents[v->elem] = u;
		else if(u->height == v->height){
			parents[v->elem] = u;
			u->height++;
		} else
			parents[u->elem] = v;
	}
};
struct edge{
	int weight;
	int u, v;
	bool operator < (const edge& other) const{
		return weight < other.weight;
	}
};
set<edge> Kruskal(set<edge> E, const vector<int>& V){
	Disjoin_Set<int> s;
	set<edge> T;
	for (const auto &v : V) {
		s.make_set(v);
	}
	for(auto const& e:E){
		int u = e.u, v = e.v;
		if(s.find_set(u) != s.find_set(v)){
			T.insert(e);
			s.union_set(s.find_set(u),s.find_set(v));
		}
	}
	return T;
}
int main() {
	vector<int> V;
	for (int i = 0; i < 7; ++i) {
		V.push_back(i);
	}
	set<edge> E;
	E.insert(edge{9,V[0],V[1]});
	E.insert(edge{1,V[0],V[2]});
	E.insert(edge{5,V[1],V[2]});
	E.insert(edge{13,V[2],V[4]});
	E.insert(edge{19,V[1],V[3]});
	E.insert(edge{17,V[1],V[4]});
	E.insert(edge{25,V[3],V[4]});
	E.insert(edge{2,V[3],V[5]});
	E.insert(edge{14,V[4],V[5]});
	E.insert(edge{21,V[4],V[6]});
	E.insert(edge{8,V[5],V[6]});
	set<edge> T = Kruskal(E,V);
	for (const auto &item : T) {
		cout << item.weight << ' ';
	}
	return 0;
}
