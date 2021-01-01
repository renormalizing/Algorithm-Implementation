#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {

public:
	int longestSubarray(vector<int>& nums, int limit) {
		deque<int> d_max;
		deque<int> d_min;
		d_max.push_front(0);
		d_min.push_front(0);
		int ans = 1;
		int start = 0;
		for (int i = 1; i < nums.size(); ++i) {
			while(!d_max.empty() && nums[i] > nums[d_max.back()])
				d_max.pop_back();
			d_max.push_back(i);
			while (!d_min.empty() && nums[i] < nums[d_min.back()])
				d_min.pop_back();
			d_min.push_back(i);
			int mini = d_min.front(), maxi = d_max.front();
			if(abs(nums[mini] - nums[maxi]) <= limit){
				ans = max(ans, i-start+1);
			} else{
				int sign = min(maxi, mini);
				start = sign+1;
				while(!d_max.empty() && d_max.front() <= sign)
					d_max.pop_front();
				while(!d_min.empty() && d_min.front() <= sign)
					d_min.pop_front();
			}
		}
		return ans;
	}
};
int main() {
	vector<int> a= {8,2,4,7};
	cout << Solution().longestSubarray(a, 4);
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
