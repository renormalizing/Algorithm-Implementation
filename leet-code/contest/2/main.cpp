#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
class Solution {
public:
	deque<int> get_digits(int num){
		deque<int>ans;
		ans.push_front(num%10);
		while (num/10 > 0){
			num/=10;
			ans.push_front(num%10);
		}
		return ans;
	}
	int sum(const deque<int>& d){
		int ans=0;
		auto it = d.begin();
		while(it!=d.end()){
			ans = ans*10 + *it;
			it++;
		}
		return ans;
	}
	int maxDiff(int num) {
		deque<int> digit = get_digits(num);
		int a = 0; int b = 0;
		int mark;
		auto it = digit.begin();
		while(it!=digit.end() && *it == 9){
			it++;
		}
		if(it == digit.end())
			a = sum(digit);
		else{
			mark = *it;
			while(it!=digit.end()){
				if(*it == mark)
					*it = 9;
				it++;
			}
			a = sum(digit);
		}
		digit = get_digits(num);
		it = digit.begin();
		if(*digit.begin() == 1){
			while(it!=digit.end() && *it <= 1){
				it++;
			}
			mark = *it;
			while(it!=digit.end()){
				if(*it == mark)
					*it = 0;
				it++;
			}
		}
		else{
			mark = *it;
			while(it!=digit.end()){
				if(*it == mark)
					*it = 1;
				it++;
			}
		}

		b = sum(digit);
		return a-b;
	}
};
int main() {
	cout << Solution().maxDiff(1101057);
	return 0;
}
