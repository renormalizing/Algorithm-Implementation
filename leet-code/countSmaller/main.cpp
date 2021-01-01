#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
class Solution {
private:
	int *tree, n;
	void update(long idx, int val){
		while(idx <= n-1){
			tree[idx] += val;
			idx += (idx & -idx);
		}
	}
	int sum(long idx){
		int sum = 0;
		while(idx > 0){
			sum += tree[idx];
			idx -= (idx&-idx);
		}
		return sum;
	}
public:
	int reversePairs(vector<int>& nums) {
		int ans = 0;
		set<int> s(nums.begin(), nums.end());
		map<int, int> m;
		for (const auto &item : s) {
			m[item] = m.size() + 1;
		}
//		int minimum = INT_MAX, maximum = INT_MIN;
//		for (int i = 0; i < nums.size(); ++i) {
//			maximum = max(maximum, nums[i]);
//			minimum = min(minimum, nums[i]);
//		}
		if(nums.size() == 0){
			return ans;
		}
//		n = (long)maximum-(long)minimum+2;
		n = m.size()+1;
		tree = new int[n];
		memset(tree, 0, sizeof(int) * n);
		for(int i = nums.size() - 1; i >=0 ; i--){
			int target = (nums[i] > 0) ? ((nums[i]-1)/2) : (nums[i]/2 - 1);
			auto it = m.upper_bound(target);
			if(it!=m.begin()){
				ans += sum((--it)->second);
			}
			update(m[nums[i]], 1);
		}
		return ans;
	}
};

int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	for(int i = 0; i < N; i++)
		cin >> a[i];
	cout << Solution().reversePairs(a) << endl;
//	vector<int> data = {3,0,0,6};
//	Solution().reversePairs(data);
	return 0;
}
