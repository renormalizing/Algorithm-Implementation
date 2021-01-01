#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool kLengthApart(vector<int>& nums, int k) {
		auto iter = nums.begin();
		int count=0;
		while(iter != nums.end() && *iter == 0)
			iter++;
		if(iter==nums.end())
			return true;
		iter++;
		while(iter!=nums.end()){
			if(*iter == 0)
				count++;
			else {
				if(count < k)
					return false;
				count = 0;
			}
			iter++;
		}
		return true;
	}
};
int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
