#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
	vector<int> *adj;
	int max_depth = -1, max_depth_index = -1;
	int *parent;
//	struct cmp{
//		bool operator () (const pair<int,int>& a, const pair<int, int>& b) const{
//			return a.second < b.second;
//		}
//	};
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		adj = new vector<int>[n];
		parent = new int[n];
		vector<int> ans;

		for (const auto &edge : edges) {
			adj[edge[0]].push_back(edge[1]);
			adj[edge[1]].push_back(edge[0]);
		}
		bool *visited = new bool[n];
		for (int i = 0; i < n; ++i) {
			visited[i] = false;
		}
		dfs1(0, visited, 0);
		for (int i = 0; i < n; ++i) {
			visited[i] = false;
		}
		parent[max_depth_index] = -1;
		max_depth = -1;
		dfs2(max_depth_index, visited, 0);
		int walk = max_depth_index;
		for (int i = 0; i < max_depth/2; ++i) {
			walk = parent[walk];
		}
		if(max_depth%2==0){
			ans.push_back(walk);
		} else{
			ans.push_back(walk);
			ans.push_back(parent[walk]);
		}
		return ans;
	}
	void dfs1(int start,  bool visited[], int d){
		visited[start] = true;
		bool isleaf = true;
		for (int i = 0; i < adj[start].size(); ++i) {
			if(!visited[adj[start][i]]) {
				dfs1(adj[start][i], visited, d + 1);
				isleaf = false;
			}
		}
		if(isleaf && d > max_depth)
			max_depth = d, max_depth_index = start;

	}
	void dfs2(int start, bool visited[], int d){
		visited[start] = true;
		bool isleaf = true;
		for (int i = 0; i < adj[start].size(); ++i) {
			if(!visited[adj[start][i]]) {
				parent[adj[start][i]] = start;
				dfs2(adj[start][i], visited, d + 1);
				isleaf = false;
			}
		}
		if(isleaf && d > max_depth)
			max_depth = d, max_depth_index = start;
	}
};
int main() {
	vector<vector<int>> edges = {
//			{0,3},{1,3},{2,3},{4,3},{5,4}
	};
	cout << Solution().findMinHeightTrees(1, edges)[0];
	return 0;
}
