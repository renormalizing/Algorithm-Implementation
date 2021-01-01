#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if(grid.empty())
			return 0;
		int n = grid.size(), m = grid[0].size();
		int ans = 2;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if(grid[i][j] == '1') {
					bfs(grid, i, j, ans);
					ans++;
				}
			}
		}
		return ans-2;
	}
	void bfs(vector<vector<char>>& grid, int i, int j, int mark){
		queue<pair<int, int>> q;
		q.push(make_pair(i,j));
		while(!q.empty()){
			pair<int, int> s = q.front();
			q.pop();
			if(s.first>=0 && s.second>=0 && s.first < grid.size() && s.second < grid[0].size()){
				if(grid[s.first][s.second]=='1') {
					grid[s.first][s.second] = '0' + mark;
					q.push(make_pair(s.first - 1, s.second));
					q.push(make_pair(s.first + 1, s.second));
					q.push(make_pair(s.first, s.second - 1));
					q.push(make_pair(s.first, s.second + 1));
				}
			}
		}
	}
};
int main() {
	vector<vector<char>> grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
	cout << Solution().numIslands(grid);
	return 0;
}
