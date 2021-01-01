#include <stdio.h>
int dp[1000], end[1000], n, a[1000];
int max(int c, int b){
	return c>b?c:b;
}
void compute_maxlen(){
	dp[0] = 1;
	end[0] = -1;
	for(int i = 1; i < n; i++){
		int tmp = 0;
		for(int j = 0; j < i; j++){
			if(a[i] > a[j]){
				if(dp[j] > tmp){
					tmp = dp[j];
					end[i] = j;
				}
			}
		}
		dp[i] = tmp + 1;
	}
}
void construct(){
	int MAX = 0;
	for(int i = 1; i < n; i++){
		if(dp[i] > dp[MAX])
			MAX = i;
	}
	int i = MAX;
	while (i>=0){
		printf("%d", a[i]);
		i = end[i];
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	compute_maxlen();
	construct();
	return 0;
}
