#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int findKnum(vector<int>& nums1, vector<int>& nums2, int k){
		int n = nums1.size(), m = nums2.size();
		int left = max(k-m, 0), right = min(n-1, k-1);
		int mid;
		// find the lowest element that satisfies the condition
		while(left <= right){
			mid = left + (right - left)/2;
			if(nums1[mid]<nums2[k - mid -1])
				left = mid + 1;
			else
				right = mid - 1;
		}
		int num1 = left==0?INT_MIN:nums1[left-1];
		int num2 = left==k?INT_MIN:nums2[k - left - 1];
		return max(num1, num2);
	}
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size(), m = nums2.size();
		if((n+m)%2)
			return findKnum(nums1, nums2, (n+m)/2+1);
		else
			return (findKnum(nums1, nums2, (n+m)/2+1) + findKnum(nums1, nums2, (n+m)/2))/2.0;
	}

};
int main() {
	vector<int> nums1{1,1,1}, nums2{1,1,1};
	cout << Solution().findMedianSortedArrays(nums1, nums2);
	return 0;
}
