#include <iostream>
class Solution {
public:
	int waysToChange(int n) {
		int dp[n+1];
		int coins[] = {1,5,10,25};
		dp[0] = 1;
		for (int i = 1; i <= n; ++i) {
			dp[i] = 0;
		}
		for (int i = 0; i < 4; ++i) {
			for (int j = 1; j <= n; ++j) {
				if(j-coins[i]>=0)
					dp[j] = (dp[j] + dp[j-coins[i]])%1000000007;
			}
		}
		return dp[n]%1000000007;
	}
};
int main() {
	int n = 900750;
	std::cout << Solution().waysToChange(n);
	return 0;
}
