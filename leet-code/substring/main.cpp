#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int findTheLongestSubstring(string s) {
		string d = "aeiou";
		int ans = 0;
		vector<int> first(1<<5, -2);
		first[0] = -1;
		int state = 0;
		for (int i = 0; i < s.size(); ++i) {
			for (int j = 0; j < 5; ++j) {
				if(s[i] == d[j])
					state ^= (1<<j);
				if(first[state] == -2)
					first[state] = i;
			}
			ans = max(ans, i - first[state]);
		}
		return ans;
	}
};
int main() {
	Solution().findTheLongestSubstring("leetcodeisgreat");
	return 0;
}
