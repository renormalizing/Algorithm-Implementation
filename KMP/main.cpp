#include <iostream>
#include <vector>
using namespace std;
class KMP{
private:
	vector<vector<int>> dp;
public:
	KMP(const string& pat){
		dp.resize(pat.size()+1, vector<int>(256,0));
		dp[0][pat[0]] = 1;
		int X = 0;
		for (int j = 1; j < pat.size(); ++j) {
			for (int c = 0; c < 256; ++c) {
				if(c == pat[j])
					dp[j][c] = j+1;
				else
					dp[j][c] = dp[X][c];
			}
			X = dp[X][pat[j]];
		}
	}
	int search(const string& txt){
		int j = 0;
		for (int i = 0; i < txt.size(); ++i) {
			j = dp[j][txt[i]];
			if(j == dp.size())
				return i - dp.size() +1;
		}
		return -1;
	}

};

void preprocess(const string& pat, int*next){
	int m = pat.size();
	int i = 1, j = 0;
	next[0] = next[1] = 0;
	for (; i < m-1; ++i) {
		while(j > 0 && pat[i]!=pat[j])
			j = next[j];
		if(pat[i] == pat[j])
			next[i+1] = ++j;
		else
			next[i+1] = 0;
	}
}
int kmp(const string& txt, const string& pat){
	int *next = new int[pat.size()];
	preprocess(pat, next);
	int j = 0;
	for (int i = 0; i < txt.size(); ++i) {
		while(j > 0 && txt[i]!=pat[j])
			j = next[j];
		if(txt[i] == pat[j])
			j++;
		if(j >= pat.size())
			return i - pat.size() + 1;
	}
	return -1;
}
int main() {
	cout << kmp("BABAC", "BABA");
	return 0;
}
