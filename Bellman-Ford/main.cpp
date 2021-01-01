#include <iostream>
#include <climits>

using namespace std;
struct edge{
	int src, dest, weight;
};
struct Graph{
	int V, E;
	edge* edges;
	Graph(int V, int E);
	void Bellman_Ford(int src);
	void printArr(int dist[], int n)
	{
		printf("Vertex   Distance from Source\n");
		for (int i = 0; i < n; ++i)
			printf("%d \t\t %d\n", i, dist[i]);
	}
};
Graph::Graph(int V, int E) {
	this->V = V;
	this->E = E;
	edges = new edge[E];
}
void Graph::Bellman_Ford(int src) {
	int dis[V];
	for (int i = 0; i < V; ++i) {
		dis[i] = INT_MAX;
	}
	dis[src] = 0;
	for (int i = 0; i < V-1; ++i) {
		for (int j = 0; j < E; ++j) {
			int s = edges[j].src, dest = edges[j].dest;
			if(dis[s] != INT_MAX && dis[s] + edges[j].weight < dis[dest]){
				dis[dest] = dis[s] + edges[j].weight;
			}
		}
	}
	for (int i = 0; i < E; ++i) {
		int s = edges[i].src, dest = edges[i].dest;
		int weight = edges[i].weight;
		if(dis[dest] != INT_MAX && dis[dest] > dis[s] + weight){
			cout << "negative circle" << endl;
			return;
		}
	}
	printArr(dis,V);
}
int main() {

	/* Let us create the graph given in above example */
	int V = 5; // Number of vertices in graph
	int E = 8; // Number of edges in graph
	struct Graph* graph = new Graph(V, E);

	// add edges 0-1 (or A-B in above figure)
	graph->edges[0].src = 0;
	graph->edges[0].dest = 1;
	graph->edges[0].weight = -1;

	// add edges 0-2 (or A-C in above figure)
	graph->edges[1].src = 0;
	graph->edges[1].dest = 2;
	graph->edges[1].weight = 4;

	// add edges 1-2 (or B-C in above figure)
	graph->edges[2].src = 1;
	graph->edges[2].dest = 2;
	graph->edges[2].weight = 3;

	// add edges 1-3 (or B-D in above figure)
	graph->edges[3].src = 1;
	graph->edges[3].dest = 3;
	graph->edges[3].weight = 2;

	// add edges 1-4 (or A-E in above figure)
	graph->edges[4].src = 1;
	graph->edges[4].dest = 4;
	graph->edges[4].weight = 2;

	// add edges 3-2 (or D-C in above figure)
	graph->edges[5].src = 3;
	graph->edges[5].dest = 2;
	graph->edges[5].weight = 5;

	// add edges 3-1 (or D-B in above figure)
	graph->edges[6].src = 3;
	graph->edges[6].dest = 1;
	graph->edges[6].weight = 1;

	// add edges 4-3 (or E-D in above figure)
	graph->edges[7].src = 4;
	graph->edges[7].dest = 3;
	graph->edges[7].weight = -3;

	graph->Bellman_Ford(0);
	return 0;
}
