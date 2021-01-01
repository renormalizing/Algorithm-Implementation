#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct cmp{
	bool operator() (const pair<int, pair<int,int>>& a, const pair<int, pair<int,int>>& b)const {
		return a.first+a.second.first > b.first+b.second.first;
	}
};
class Solution {
public:
	vector<int> kmin(vector<vector<int>> &mat, int up, int down, int k){
		vector<int> ans;
		if(up==down) {
			for (int i = 0; i < min(k, (int)mat[up].size()); ++i) {
				ans.push_back(mat[up][i]);
			}
			return ans;
		}
		else if(up==down-1){
			priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, cmp> q;
			for (int i = 0; i < mat[up].size(); ++i) {
				q.push({mat[up][i], {mat[down][0],0}});
			}
			for (int i = 0; i < k && !q.empty(); ++i) {
				auto t = q.top();
				q.pop();
				ans.push_back(t.first+t.second.first);
				t.second.second++;
				if(t.second.second < mat[down].size())
					q.push({t.first,{mat[down][t.second.second], t.second.second}});
			}
			return ans;
		} else{
			int mid = (up+down)/2;
			vector<vector<int>> tmp;
			tmp.push_back(kmin(mat, up, mid, k));
			tmp.push_back(kmin(mat, mid+1, down, k));
			return kmin(tmp, 0, tmp.size()-1, k);
		}
	}
	int kthSmallest(vector<vector<int>>& mat, int k) {
		return kmin(mat, 0, mat.size()-1, k).back();
	}
};
int main() {
	vector<vector<int>> mat = {{1,10,10},{1,4,5},{2,3,6}};
	cout << Solution().kthSmallest(mat, 7);
	return 0;
}
