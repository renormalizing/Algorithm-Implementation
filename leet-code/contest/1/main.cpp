#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
		int max_num = 0;
		for(int i = 0; i < candies.size(); i++){
			max_num = max(max_num, candies[i]);
		}
		vector<bool> ans(candies.size());
		for(int i = 0; i < candies.size(); i++){
			ans[i] = extraCandies + candies[i] >= max_num;
		}
		return ans;
	}
};
int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}