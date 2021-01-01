#include <stdio.h>

char string1[1000], string2[1000];
int dp[1000][1000], len1, len2;
int max(int a, int b){
	return a>b?a:b;
}
void findLongestSubstring(){
	for(int i = 0; i <= len1; i++)
		dp[i][0] = 0;
	for (int i = 0; i <= len2; ++i)
		dp[0][i] = 0;
	for(int i = 1; i <= len1; i++){
		for (int j = 1; j <= len2; ++j) {
			if(string1[i - 1] == string2[j - 1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
}
int construct_string(char *string){
	int i = len1, j = len2, len = 0;
	while(i>0 && j>0){
		if(string1[i-1] == string2[j-1]){
			string[len] = string1[i-1];
			len++, i--, j--;
		} else{
			if(dp[i-1][j] > dp[i][j-1])
				i--;
			else
				j--;
		}
	}
	return len;
}
int main() {
	scanf("%d%d", &len1, &len2);
	scanf("%s%s", string1, string2);
	char string[1000];
	findLongestSubstring();
	int len = construct_string(string);
	printf("%d\n", dp[len1][len2]);
	for(int i = len - 1; i >=0; i--)
		printf("%c", string[i]);
	return 0;
}

