#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
	vector<vector<int>> ans;
	void search(vector<int>& nums, vector<int>&path, vector<bool>& selected){
		if(path.size() == nums.size())
			ans.push_back(path);
		else{
			for(int i = 0; i < nums.size(); i++){
				if(!selected[i]){
					path.push_back(nums[i]);
					selected[i] = true;
					search(nums, path, selected);
					path.pop_back();
					selected[i] = false;
				}
			}
		}
	}
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<bool> selected(nums.size(), false);
		vector<int> path;
		search(nums, path, selected);
		return ans;
	}
};
int main() {
	vector<int> a = {1,2,3};
	Solution().permute(a);
	return 0;
}
