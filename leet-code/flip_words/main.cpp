#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	string reverseWords(string s) {
		reverse(s.begin(), s.end());
		int pos = 0;
		int n = s.size();
		for (int i = 0; i < n; ++i) {
			if(s[i] != ' '){
				if(pos != 0)
					s[pos++] = ' ';
				int j = i;
				while(i < n && s[i] != ' '){
					s[pos] = s[i];
					i++, pos++;
				}
				reverse(s.begin() + pos - (i-j), s.begin() + pos);
			}
		}
		s.erase(s.begin() + pos, s.end());
		return s;
	}
};
int main() {
	string s;
	getline(cin,s);
	cout << Solution().reverseWords(s);
	return 0;
}
