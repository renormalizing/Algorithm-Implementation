#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
	string destCity(vector<vector<string>>& paths) {
		int n = paths.size();
		unordered_set<string> s(n);
		for (int i = 0; i < n; ++i) {
			s.insert(paths[i][0]);
		}
		int t = 0;
		for (; t < n; ++t) {
			if(s.count(paths[t][1]) == 0)
				break;
		}
		return paths[t][1];
	}
};
int main() {
	vector<vector<string>> s={{"A","B"},{"B","C"},{"C","D"}};
	cout << Solution().destCity(s);
	return 0;
}
