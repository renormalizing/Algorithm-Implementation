#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> v;
		dfs_search(2*n, 0, "",v);
		return v;
	}
	void dfs_search(int n, int num_left, const string& s, vector<string>& v){
		if(num_left > n)
			return;
		if(n == 0) {
			v.push_back(s);
			return;
		}
		if(num_left==0) {
			string a = s + "(";
			dfs_search(n-1, 1, a, v);
		} else{
			string a = s + "(";
			dfs_search(n-1, num_left + 1, a, v);
			string b = s + ")";
			dfs_search(n-1, num_left - 1, b, v);
		}
	}
};
int main() {
	vector<string> v = Solution().generateParenthesis(3);
	for (const auto &item : v) {
		cout << item << endl;
	}
	return 0;
}
