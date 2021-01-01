#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int parent[20]{};
int weight[20][20] ={{0, 5, 1, 2},
					 {5, 0, 3, 3},
					 {1, 3, 0, 4},
					 {2, 3, 4, 0}};
bool selected[20]{};
int key[20];
bool cmp (const int a, const int b)  {
	return key[a] > key[b];
}
void Prim(vector<int> V, int start){
	vector<int> q;
	// c++ priority_queue don't provide decrease_key()
    //	so use vector + make_heap instead
	for (int i = 0; i < V.size(); ++i) {
		if(i==start) {
			key[i] = 0;
			parent[i] = -1;
		}
		else
			key[i] = INT_MAX;
		q.push_back(i);
	}
	make_heap(q.begin(), q.end(), cmp);
	while(!q.empty()){
		int v = q.front();
		pop_heap(q.begin(), q.end());
		q.pop_back();
		selected[v] =true;
		for (int i = 0; i < 4; ++i) {
			if(weight[i][v]!=-1 && !selected[i] && weight[i][v] < key[i] ){
				key[i] = weight[i][v];
				parent[i] = v;
			}
		}
		make_heap(q.begin(), q.end());
	}
}
int main()
{
	vector<int> a = {0,1,2,3};
	Prim(a, 0);
	for (int i = 0; i < 4; ++i) {
		cout << parent[i] << ' ';
	}
	return 0;
}
