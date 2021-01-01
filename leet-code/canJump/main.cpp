#include <iostream>
#include <vector>
using namespace std;
// dp is too slow!!!
//class Solution {
//public:
//	bool canJump(vector<int>& nums) {
//		if(nums.size() == 1)
//			return true;
//		bool dp[nums.size()];
//		dp[nums.size() - 2] = nums[nums.size() - 2] >= 1;
//		for(int i = nums.size() - 3; i >= 0; i--){
//			dp[i] = nums[i] >= nums.size() - 1 - i;
//			if(!dp[i]){
//				for (int j = 1; j <= nums[i]; ++j) {
//					if(dp[i+j]){
//						dp[i] = true;
//						break;
//					}
//				}
//			}
//		}
//		return dp[0];
//	}
//};
class Solution{
public:
	bool canJump(vector<int>& nums)
	{
		int k = 0; //表示能到达的最远距离
		for (int i = 0; i < nums.size(); i++)
		{
			if (i > k) return false;
			k = max(k, i + nums[i]);
		}
		return true;
	}
};
int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
