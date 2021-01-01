#include <iostream>
using namespace std;
class Solution {
private:
	int dp[10000+1][100+1]{};
public:
	int superEggDrop(int K, int N) {
		if(N==1)
			return 1;
		for (int i = 0; i <= N; ++i) {
			dp[i][1] = i;
		}
//		for (int k = 1; k <= K; ++k) {
//			dp[1][K] = 1;
//		}

		for (int num_eggs = 2; num_eggs <= K; ++num_eggs) {
			for (int floor = 2; floor <= N; ++floor) {
				int minimum = INT_MAX;
				for (int i = 1; i < floor; ++i) {
					minimum = min(minimum, max(dp[floor - i][num_eggs], dp[i-1][num_eggs - 1]));
				}
				dp[floor][num_eggs] = minimum + 1;
			}
		}
		return dp[N][K];
	}
};
int main() {
	int K, N;
	cin >> K >> N;
	cout << Solution().superEggDrop(K, N);
	return 0;
}
