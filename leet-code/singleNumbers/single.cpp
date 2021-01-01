#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int mask = 0;
        for(int i = 0; i < nums.size(); i++){
            mask ^= nums[i];
        }
        int div = 1;
        while((div & mask) == 0){
            div <<=  1;
        }
        int a = 0, b = 0;
        for(int i = 0; i < nums.size(); i++ ){
            if(div & nums[i])
                a ^= nums[i];
            else
                b ^= nums[i];
        }
        vector<int> ans{a,b};
        return ans;
    }
};
