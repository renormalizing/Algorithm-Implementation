#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct cmp{
	bool operator () (const ListNode* a, const ListNode* b)const {
		return a->val > b->val;
	}
};
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
		ListNode* ans = NULL;
		for(auto i : lists) {
			if(i)
				pq.push(i);
		}
		ListNode* walk;
		while(!pq.empty()){
			ListNode* p = pq.top();
			pq.pop();
			if(!ans){
				ans = p;
				walk = ans;
			}
			else {
				walk->next = p;
				walk = walk->next;
			}
			if(p->next!=NULL)
				pq.push(p->next);
		}
		return ans;
	}
};
int main() {
	vector<ListNode*> a(2);
	ListNode* p = new ListNode(1);
	p->next = new ListNode(4);
	p->next->next = new ListNode(5);
	ListNode* q = new ListNode(1);
	q->next = new ListNode(3);
	q->next->next = new ListNode(4);
	a[0]= p;
	a[1] = q;
	Solution().mergeKLists(a);
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
