#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
    	int max_area = 0;
    	auto left = height.begin();
    	auto right = height.end()-1;
    	while(left<right){
    		int width = right-left;
    		if(*left < *right){
    			max_area = max(max_area, *left * width);
    			left++;
    		} else{
    			max_area = max(max_area, *right * width);
    			right--;
    		}
    	}
		return max_area;
    }
};
int main() {
	vector<int> a = {1,2};
	return 0;
}
