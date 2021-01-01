#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
	int* lo, *hi, *count, *rank;
	int l;
	void init(int i, int left, int right){
		lo[i] = left;
		hi[i] = right;
		count[i] = 0;
		if(left == right) {
			return;
		}
		int mid = (left+right)/2;
		init(2*i,left, mid);
		init(2*i+1, mid+1, right);
	}
	void insert(int i, int x){
		if(hi[i] == lo[i]) {
			count[i]++;
			return;
		}
		int mid = (lo[i] + hi[i])/2;
		if(x <= mid)
			insert(2*i, x);
		else
			insert(2*i+1, x);
		count[i] = count[2*i] + count[2*i+1];
//		if(lo[i] <= x && x <= hi[i]) {
//			count[i]++;
//		}
//		if(lo[i] == hi[i])
//			return;
//		insert(2*i, x);
//		insert(2*i+1, x);

	}
	int query(int i, int lower, int upper){
		if(lower > hi[i] || upper < lo[i])
			return 0;
		if(lower <= lo[i] && upper >= hi[i]){
			return count[i];
		}

		int left = query(2*i, lower, upper);
		int right = query(2*i+1, lower, upper);
		return left+right;
	}
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		int n = nums.size();
		long  a[n+1], s[n+1];
		a[0] = s[0] = 0;
		for (int i = 1; i <= n; ++i) {
			s[i] = s[i-1] + nums[i-1]; // compute prefix sum
			a[i] = s[i];
		}
		//离散化
		sort(s, s+n+1);
		int len = unique(s, s+n+1) - s;
		l = len;
		rank = new int[n+1];
		for (int i = 0; i <= n; ++i) {
			rank[i] = lower_bound(s, s+len, a[i]) - s;
		}
		lo = new int[4*len + 1];
		hi = new int[4*len + 1];
		count= new int[4*len + 1];
		int ans = 0;
		init(1, 0, len-1);
		insert(1, rank[0]);
		for (int i = 1; i <= n; ++i) {
//			int tmp = a[i] - upper;
			int rank1 = lower_bound(s, s+len, a[i] - upper) - s, rank2 = upper_bound(s, s+len, a[i]-lower) - s -1;
			if(rank1 <= rank2)
				ans += query(1, rank1, rank2);
			insert(1, rank[i]);
		}
		return ans;
	}
};
int main() {
	vector<int> a={-2, 0,0, 2, 2, -2};
	cout << Solution().countRangeSum(a, -3, 1);
	return 0;
}
