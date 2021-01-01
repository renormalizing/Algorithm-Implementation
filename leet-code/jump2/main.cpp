#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	int jump(vector<int>& nums) {
		int step = 0;
		int maxpos = 0;
		int end = 0;
		for (int i = 0; i < nums.size()-1; ++i) {
			maxpos = max(i+nums[i], maxpos);
			if(i==end){
				end = maxpos;
				step++;
			}
		}
		return step;
//		int tmp, size;
//		vector<bool> visited(nums.size());
//		queue<int> q;
//		q.push(0);
//		while(!q.empty()){
//			size = q.size();
//			for (int i = 0; i < size; ++i) {
//				tmp = q.front();
//				if(tmp == nums.size()-1)
//					return step;
//				q.pop();
//				visited[tmp] = true;
//				for (int s = 1; s <= nums[tmp]; ++s) {
//					if(!visited[tmp+s])
//						q.push(tmp+s);
//				}
//			}
//			step++;
//		}
	}
};
int main() {
	vector<int> a={1,2,0,1};
	cout << Solution().jump(a);
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
