#include <iostream>
using namespace std;
void compute(int capacity, int n, int weights[], int values[], int dp[][1000]){
	for (int i = 0; i <= n; ++i)
		dp[i][0] = 0;
	for (int i = 0; i <= capacity; ++i) {
		dp[0][i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= capacity; ++j) {
			if (weights[i - 1] > j)
				dp[i][j] = dp[i-1][j];
			else{
				dp[i][j] = max(dp[i - 1][j - weights[i-1]] + values[i-1], dp[i - 1][j]);
			}
		}
	}
}
void construct(int dp[][1000], int n, int capacity, int weights[], int values[]){
	int weight = capacity, walk = n;
	while(walk > 0 && weight > 0){
		if(dp[walk][weight] > dp[walk - 1][weight]) {
			cout << weights[walk-1] <<' ' << values[walk-1] << endl;
			weight = weight - weights[walk-1];
		}
		walk--;

	}
}
int main() {
	int n, capacity;
	cin >> n >> capacity;
	int weights[n], values[n];
	int dp[1000][1000];
	for (int i = 0; i < n; ++i) {
		cin >> weights[i] >> values[i];
	}
	compute(capacity, n, weights, values, dp);
	cout << dp[n][capacity]<<endl;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= capacity; ++j) {
			cout << dp[i][j]<<' ';
		}
		cout << endl;
	}
	construct(dp, n, capacity, weights, values);
	return 0;
}
