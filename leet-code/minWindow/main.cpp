#include <iostream>
#include <map>
#include <queue>
using namespace std;
class Solution {
public:
	string minWindow(string s, string t) {
		map<char, int> count_s, count_t;
		for (char c : t){
			count_t[c] = 0;
			if(count_s.count(c))
				count_s[c]++;
			else
				count_s[c] = 1;
		}

		deque<int> q;
		int ans = 0, start = 0;
		int left, right;
		while(ans < t.size() && start < s.size()){
			if(count_t.count(s[start])){
				if(count_t[s[start]] < count_s[s[start]])
					ans++;
				q.push_back(start);
				count_t[s[start]]++;
			}
			start++;
		}
		if(ans != t.size())
			return "";
		while(!q.empty() && count_t[s[q.front()]]>count_s[s[q.front()]]){
			count_t[s[q.front()]]--;
			q.pop_front();
		}
		left = q.front();
		right = start-1;
		ans = right - left + 1;
		for (int i = start; i < s.size(); ++i) {
			if(count_t.count(s[i])){
				q.push_back(i);
				count_t[s[i]]++;
			}
			while(!q.empty() && count_t[s[q.front()]]>count_s[s[q.front()]]){
				count_t[s[q.front()]]--;
				q.pop_front();
			}
			if(ans > q.back() - q.front() + 1){
				left = q.front();
				right = q.back();
				ans = right-left+1;
			}
		}
		return string(s.begin()+left, s.begin() + right + 1);
	}
};
int main() {
	cout << Solution().minWindow("bba",  "ba");
	return 0;
}
