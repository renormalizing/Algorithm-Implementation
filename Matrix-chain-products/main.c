#include <stdio.h>
#define MAX 1000000000
int dp[10000][10000], split[10000][10000];
int p[10000];
int n;
void compute_cost() {
	for (int i = 0; i < n; i++)
		dp[i][i] = 0;
	for (int len = 2; len <= n; len++) {
		for (int i = 0; i <= n - len; i++){
			int j = i + len -1;
			int tmp = MAX;
			for(int k = i+1; k <= j; k++){
				int c = dp[i][k-1] + dp[k][j] + p[i]*p[k]*p[j+1];
				if(tmp > c){
					tmp = c;
					split[i][j] = k;
				}
			}
			dp[i][j] = tmp;
		}
	}
}
void construct_order(int i, int j){
	if(i==j){
		printf("A%d", i+1);//矩阵链从1开始
	} else{
		printf("(");
		construct_order(i, split[i][j] - 1);
		construct_order(split[i][j], j);
		printf(")");
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i <= n; i++)
		scanf("%d", &p[i]);
	compute_cost();
	construct_order(0, n-1);
	return 0;
}
