#include <iostream>
#include <vector>
#define NUM_CHARS 256
using namespace std;
void preprocess(const string& pattern, vector<int>& alphabet){
	for (int i = 0; i < NUM_CHARS; ++i) {
		alphabet[i] = -1;
	}
	for(int i = 0; i < pattern.size(); i++){
		alphabet[pattern[i]] = i;
	}
}
int Boyer_Moore(const string& text, const string& pattern){
	vector<int> alphabet(NUM_CHARS);
	preprocess(pattern, alphabet);
	int i = pattern.size() - 1, j = pattern.size() - 1;
	while(i<text.size()){
		while (j >= 0 && text[i] == pattern[j])
			i--, j--;
		if(j < 0)
			return i+1;
		else if(alphabet[pattern[j]]!=-1){
			if(alphabet[pattern[j]] < j){
				i += pattern.size() - 1 - alphabet[pattern[j]];
				j = pattern.size() - 1;
			}else{
				i += pattern.size() - 1 - j + 1;
				j = pattern.size() - 1;
			}
		}else{
			j = pattern.size() - 1;
			i += pattern.size();
		}
	}
	return -1;
}
int main() {
	string text = "ABAAAAABCD", pattern = "ABC";
	cout << Boyer_Moore(text, pattern);
	return 0;
}
