#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
		int walk = 0, count = 1;
		vector<int> counts;
		while(walk<nums.size()){
			if(nums[walk]%2 == 1) {
				counts.push_back(count);
				count = 1;
			}
			else
				count++;
			walk++;
		}
		int last = count;
		if(counts.size() < k)
			return 0;
		int ans = 0;
		walk = 0;
		while(walk+k<counts.size()){
			ans += counts[walk] * counts[walk + k];
			walk++;
		}
		return ans+counts[walk]*last;
    }
};
int main() {
	vector<int> a = {1,1,2,1,1};
	cout << Solution().numberOfSubarrays(a,3);
	return 0;
}
