#include <iostream>
#include <vector>
using namespace std;
class MajorityChecker {
private:
	int *lo, *hi;
	vector<int> idx[20001];
	pair<int, int>* candidate;
public:
	void init(int i, int a, int b, vector<int>& arr){
		lo[i] = a;
		hi[i] = b;
		if(a == b) {
			candidate[i] = make_pair(arr[a], 1);
			return;
		}
		int m = (a+b)/2;
		init(2*i, a, m, arr);
		init(2*i+1, m+1, b, arr);
		pair<int, int> candidate1 = candidate[2*i], candidate2 = candidate[2*i+1];
		if(candidate1.first == candidate2.first)
			candidate[i] = make_pair(candidate1.first, candidate1.second + candidate2.second);
		else{
			if(candidate1.second > candidate2.second)
				candidate[i] = make_pair(candidate1.first, candidate1.second - candidate2.second);
			else
				candidate[i] = make_pair(candidate2.first, candidate2.second - candidate1.second);
		}

	}
	MajorityChecker(vector<int>& arr) {
		int n = arr.size();
		lo = new int[4*n+1];
		hi = new int[4*n+1];
		candidate = new pair<int, int> [4*n+1];
		for(int i = 0; i < arr.size(); i++)
			idx[arr[i]].push_back(i);
		init(1, 0, n-1, arr);
	}
	pair<int, int> _query(int i, int left, int right){
		if(left > hi[i] || lo[i] > right){
			return make_pair(-1,0);
		}
		if(left <= lo[i] && hi[i] <= right){
			return candidate[i];
		}
		pair<int, int> candidate1 = _query(2*i , left , right), candidate2 = _query(2*i+1, left, right);
		if(candidate1.first != -1 && candidate2.first != -1){
			if(candidate1.first == candidate2.first)
				return make_pair(candidate1.first, candidate1.second + candidate2.second);
			else{
				if(candidate1.second > candidate2.second)
					return make_pair(candidate1.first, candidate1.second - candidate2.second);
				else
					return make_pair(candidate2.first, candidate2.second - candidate1.second);
			}
		}else if(candidate1.first!=-1)
			return candidate1;
		else if(candidate2.first!=-1)
			return candidate2;
		return candidate1;

	}

	int query(int left, int right, int threshold) {
		pair<int, int> ans = _query(1, left,right);
		if(upper_bound(idx[ans.first].begin(), idx[ans.first].end(), right)-lower_bound(idx[ans.first].begin(), idx[ans.first].end(), left) < threshold)
			return -1;
		return ans.first;

	}
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
int main() {
	vector<int> a = {1,1,2,2,1,1,3,3,3};
	MajorityChecker majorityChecker(a);
	cout << majorityChecker.query(0,,3); // 返回 1
	cout << majorityChecker.query(0,3,3); // 返回 -1
	cout <<majorityChecker.query(2,3,2); // 返回 2

	return 0;
}
