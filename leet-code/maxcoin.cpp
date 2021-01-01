#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int dp[n+2][n+2];
        for(int i = 0; i < n+2; i++){
            for(int j = 0; j < n+2; j++)
                dp[i][j] = 0;
        }
        vector<int> val(n+2);
        val[0] = val[n+1] = 1;
        for(int i = 1; i <= n; i++)
            val[i] = nums[i-1];
        for(int k = 2; k <= n+1; k++){
            for(int i = 0; i <= n+1-k; i++){
                for(int j = i+1; j <= i+k-1; j++){
                    dp[i][i+k] = max(dp[i][i+k], dp[i][j] + dp[j][i+k] + val[i]*val[j]*val[i+k]);
                }
            }
        }
        return dp[0][n+1];
    }
};