#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), true));
//		for (int i = 0; i < s.size(); ++i) {
//			dp[i][i] = true;
//		}
		int left = 0, right = 0;
		for (int l = 2; l <= s.size(); ++l) {

			for (int i = 0; i < s.size() - l + 1; ++i) {
				dp[i][i+l-1] = dp[i+1][i+l-2] && (s[i] == s[i+l-1]);
				if(dp[i][i+l-1]){
					left = i, right = i+l-1;
				}
			}
		}
		return string(s.begin()+left, s.begin() + right + 1);
	}
};
int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
