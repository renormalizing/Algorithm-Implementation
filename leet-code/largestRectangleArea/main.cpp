#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		heights.insert( heights.begin(), 0);
		heights.push_back(0);
		stack<int> s;
		s.push(0);
		int ans = 0;
		for (int i = 1; i < heights.size(); ++i) {
			while(!s.empty() && heights[s.top()] > heights[i]){
				int tmp = s.top();
				s.pop();
				ans = max(ans, heights[tmp] * (i - s.top()-1));
			}
			s.push(i);
		}
		return ans;
	}
};
int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
