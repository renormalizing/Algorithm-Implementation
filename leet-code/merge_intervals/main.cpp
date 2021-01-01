#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> ans;
		sort(intervals.begin(), intervals.end(), cmp);
		int count = 0, i = 0;
		while(i < intervals.size()){
			int j = i+1;
			int maximum = intervals[i][1];
			while(j < intervals.size() && intervals[j][0]<=maximum){
				maximum = max(intervals[j][1], maximum);
				j++;
			}
			vector<int> tmp;
			tmp.push_back(intervals[i][0]), tmp.push_back(maximum);
			ans.push_back(tmp);
			i = j;
		}
		return ans;
	}
	static bool cmp(const vector<int>& i1, const vector<int>& i2){
		if(i1[0] == i2[0])
			return i1[1] < i2[1];
		else
			return i1[0] < i2[0];
	}
};
int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
