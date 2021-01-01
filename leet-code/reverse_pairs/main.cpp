#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int reversePairs(vector<int>& nums) {
		return merge(0, nums.size()-1, nums);
	}
	int merge(int left, int right, vector<int>& nums){
		if(left>=right)
			return 0;
		int mid = left + (right-left)/2;
		int ans = merge(left,mid,nums) + merge(mid+1,right,nums);
		int walk1 = left, walk2 = mid+1, p = 0;
		vector<int> tmp(right-left+1);
		while(walk1<= mid && walk2 <= right){
			if(nums[walk1] <= nums[walk2]) {
				tmp[p] = nums[walk1];
				p++, walk1++;
			}else{
				tmp[p] = nums[walk2];
				ans += (mid - walk1 + 1);
				p++,walk2++;
			}
		}
		if(walk1 <= mid){
			while(walk1 <= mid){
				tmp[p] = nums[walk1];
				walk1++, p++;
			}
		}
		for (int i = 0; i < p; ++i) {
			nums[i+left] = tmp[i];
		}
		return ans;
	}
};
int main() {
	vector<int> nums = {7,5,6,4};
	cout << Solution().reversePairs(nums);
	return 0;
}
