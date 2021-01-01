#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <queue>
using namespace std;
#define INF 1000001
typedef pair<int,int> iPair ;
class Graph{
private:
	int num;
	list<pair<int, int>> *adj_list;
public:
	Graph(int num);
	void shortest_path(int src);
	void addEdge(int u, int v, int w);
};
Graph::Graph(int num) {
	this->num = num;
	adj_list = new list<pair<int, int>> [num];
}
void Graph::addEdge(int u, int v, int w) {
	adj_list[u].emplace_back(w,v);
	adj_list[v].emplace_back(w,u); // comment this line if G is a directed graph
}
void Graph::shortest_path(int src) {
	vector<int> dis(num, INF);
	dis[src] = 0;
	priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
	pq.push(make_pair(0,src));
	while(!pq.empty()){
		iPair v = pq.top();
		pq.pop();
		for(auto iter : adj_list[v.second]){
			if(dis[iter.second] > dis[v.second] + iter.first){
				dis[iter.second] = dis[v.second] + iter.first;
				pq.push(make_pair(dis[iter.second], iter.second));
			}
		}

	}
	//set implementation
//	set<pair<int, int>> shortest;
//	shortest.insert(make_pair(0,src));
//	while(!shortest.empty()){
//		pair<int, int> v = *(shortest.begin());
//		shortest.erase(shortest.begin());
//		for(auto iter : adj_list[v.second]){
//			if(dis[iter.second] > dis[v.second] + iter.first){
//				if(dis[iter.second] != INF)
//					shortest.erase(shortest.find(make_pair(dis[iter.second], iter.second)));
//				dis[iter.second] = dis[v.second] + iter.first;
//				shortest.insert(make_pair(dis[iter.second], iter.second));
//			}
//		}
//	}
	for (int i = 0; i < num; ++i) {
		cout << i << ':' << dis[i] << endl;
	}
}
int main() {
	// create the graph given in above fugure
	int V = 9;
	Graph g(V);

	//  making above shown graph
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	g.shortest_path(0);

	return 0;
}
