#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
//		int dp[matrix.size()][matrix.size()];
		queue<pair<int, int>> q;
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[i].size(); ++j) {
				if(matrix[i][j] == 0)
					q.push(make_pair(i,j));
				else
					matrix[i][j] = -1;
			}
		}
		while(!q.empty()){
			int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
			pair<int, int> cord = q.front();
			q.pop();
			for (int k = 0; k < 4; ++k) {
				int x = cord.first + dx[k], y = cord.second + dy[k];
				if(x>=0 && x<matrix.size() && y>=0 && y<matrix[0].size() && matrix[x][y]==-1) {
					matrix[x][y] = matrix[cord.first][cord.second] + 1;
					q.push(make_pair(x,y));
				}
			}
		}
		return matrix;
	}
};
int main() {
	vector<vector<int>> a = {{0},{0},{0},{0}};
	vector<vector<int>> ans = Solution().updateMatrix(a);
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a[i].size(); ++j) {
			cout << ans[i][j] <<' ';
		}
	}
	return 0;
}
