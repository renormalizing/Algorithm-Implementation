#include <iostream>
#include <vector>
using namespace std;
// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
private:
	vector<int> a{1,5,2};
public:
	int get(int index){
		return a[index];
	};
	int length(){
		return a.size();
	};
};

class Solution {
public:
	int findInMountainArray(int target, MountainArray &mountainArr) {
		int peak = find_peak(1, mountainArr.length() - 1, mountainArr);
		int left = 0, right = peak;
		int mid, ans = -1;
		while(left <= right){
			mid = left + (right - left)/2;
			if(mountainArr.get(mid) <= target) {
				ans = mid;
				left = mid + 1;
			} else
				right = mid - 1;
		}
		if(ans != -1 && mountainArr.get(ans) == target)
			return ans;
		left = peak+1, right = mountainArr.length()-1;
		while (left <= right){
			mid = left + (right-left)/2;
			if(mountainArr.get(mid) <= target){
				ans = mid;
				right = mid - 1;
			} else
				left = mid + 1;
		}
		if(ans!=-1 && mountainArr.get(ans) == target)
			return ans;
		return -1;
	}
	int find_peak(int left, int right, MountainArray& mountainarr){
		int ans = -1;
		while(left <= right){
			int mid = left + (right - left)/2;
			if(mountainarr.get(mid-1) < mountainarr.get(mid)){
				ans = mid;
				left = mid+1;
			} else
				right = mid - 1;
		}
		return ans;
	}
};
int main() {
	MountainArray m;
	cout << Solution().findInMountainArray(1,m);
	return 0;
}
