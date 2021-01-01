#include <iostream>
#include <stack>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<int> s1, s2;
		ListNode* walk1 = l1, *walk2 = l2;
		while (walk1!=NULL){
			s1.push(walk1->val);
			walk1 = walk1->next;
		}
		while (walk2!=NULL){
			s2.push(walk2->val);
			walk2 = walk2->next;
		}
		ListNode* ans = NULL;
		int prev = 0;
		while(!s1.empty() && !s2.empty()){
			ListNode* p = new ListNode((s1.top()+s2.top() + prev)%10);
			p->next = ans;
			ans = p;
			prev = (s1.top()+s2.top()+prev)/10;
			s1.pop();s2.pop();
		}
		if(!s1.empty()){
			while (!s1.empty()) {
				ListNode *p = new ListNode((s1.top() + prev) % 10);
				p->next = ans;
				ans = p;
				prev = (s1.top() + prev) / 10;
				s1.pop();
			}
		}
		else if(!s2.empty()){
			while (!s2.empty()) {
				ListNode *p = new ListNode((s2.top() + prev) % 10);
				p->next = ans;
				ans = p;
				prev = (s2.top() + prev) / 10;
				s2.pop();
			}
		}
		if(prev!=0){
			ListNode *p = new ListNode(prev);
			p->next = ans;
			ans = p;
		}
		return ans;
	}
};
int main() {
	return 0;
}
