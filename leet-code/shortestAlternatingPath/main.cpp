
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
enum color{red, blue};
class Solution {
public:
	vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
		int step = 0;
		vector<int> ans(n, -1);
		vector<vector<bool>> seen(n, vector<bool>(2));
		queue<pair<int, color>> q;
		vector<vector<int>> red_adj(n), blue_adj(n);
		for(auto e:red_edges)
			red_adj[e[0]].push_back(e[1]);
		for(auto e:blue_edges)
			blue_adj[e[0]].push_back(e[1]);
		q.push({0, red});
		q.push({0,blue});
		while(!q.empty()){
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				auto u = q.front();
				seen[u.first][u.second] = true;
				ans[u.first] = ans[u.first] == -1 ? step : ans[u.first];
				q.pop();
				if(u.second == red){
					for (int & j : blue_adj[u.first]) {
						if(!seen[j][blue])
							q.push({j, blue});
					}
				}
				if(u.second == blue){
					for (int & j :red_adj[u.first]) {
						if(!seen[j][red])
							q.push({j, red});
					}
				}
			}
			step++;
		}
		return ans;
	}
};
int main() {

	return 0;
}
