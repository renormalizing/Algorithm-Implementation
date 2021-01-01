#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Graph{
private:
	vector<vector<int>> cap;
	int num_node;
	vector<bool> seen;
public:
	Graph(int n){
		this->num_node = n;
		cap.resize(n,vector<int>(n));
		seen.resize(n);
	}
	void add_edge(int i, int j, int w){
		cap[i][j] += w;
	}
	int dfs(int s, int t, int minimum){
		if(s == t)
			return minimum;
		seen[s] = true;
		for (int i = 0; i < num_node; ++i) {
			if(cap[s][i] && !seen[i]){
				int tmp = dfs(i, t, min(minimum, cap[s][i]));
				if(tmp > 0){
					cap[s][i] -= tmp;
					cap[i][s] += tmp;

					return tmp;
				}
			}
		}
		return 0;
	}
	int max_flow(int s, int t){
		int ans = 0;
		int increase = -1;
		while(increase != 0){
			fill(seen.begin(), seen.end(), false);
			increase = dfs(s, t, INT_MAX);
			ans += increase;
		}
		return ans;
	}
};
int main() {
	int n, e;
	int s, t, w, tmp1, tmp2;
	cin >> n;
	cin >> e;
	Graph g(n);
	for (int i = 0; i < e; ++i) {
		cin >> tmp1 >> tmp2 >> w;
		g.add_edge(tmp1, tmp2, w);
	}
	cin >> s >> t;
	cout << g.max_flow(s, t);
	return 0;
}
