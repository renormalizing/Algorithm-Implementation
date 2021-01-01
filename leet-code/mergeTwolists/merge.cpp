using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1, *p2 = l2;
        ListNode* ans = NULL, *walk = new ListNode(0);
        walk->next = ans;
        while(p1 && p2){ 
            if(p1->val < p2->val){
                walk->next =  p1;
                p1 = p1->next;
            }else{
                walk->next = p2;
                p2 = p2->next;
            }
            walk = walk->next;
        }
        if(p1){
            walk->next = p1;
        }
        if(p2){
            walk->next = p2;
        }
        return ans;
    }
};
