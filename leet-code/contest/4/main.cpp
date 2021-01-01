#include <iostream>
#include <vector>
using namespace std;
#define m 1000000007
class Solution {
private:
	bool selected[41]{};
public:
	int find(int i, int n, vector<vector<int>>& hats){
		int ans - 0
		if(i==n-1){
			for (int j = 0; i < ; ++i) {

			}
		}
	}
	int backtrack(int i, int n, vector<vector<int>>& hats){
		// i 从 0 开始
		if(i==n)
			return 1;
		int ans = 0;
		for (int j = 0; j < hats[i].size(); ++j) {
			if(!selected[hats[i][j]]) {
				selected[hats[i][j]] = true;
				ans = (ans + backtrack(i + 1, n, hats)) % m;
				selected[hats[i][j]] = false;
			}
		}
		return ans;
	}
    int numberWays(vector<vector<int>>& hats) {
//		for (int i = 0; i < 40; ++i) {
//			cout << selected[i];
//		}
		for (int i = 0; i < hats.size(); ++i) {
			sort(hats[i].begin(), hats[i].end());
		}
		return backtrack(0, hats.size(), hats);
    }
};
int main() {
	vector<vector<int>> hats = {{3,4},{4,5},{5}};
	cout << Solution().numberWays(hats);
	return 0;
}
