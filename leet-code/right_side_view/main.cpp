#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		queue<TreeNode*> q;
		vector<int> ans;
		if(root) {
			q.push(root);
			bfs(q, ans);
		}
		return ans;
	}
	void bfs(queue<TreeNode*>& q, vector<int>& ans){
		// queue<TreeNode*> tmp;
		TreeNode* s;
		if(q.empty())
			return;
		s = q.back();
		ans.push_back(s->val);
		int size = q.size();
		for(int i = 0; i < size; i++){
			s = q.front();
			q.pop();
			if(s->left)
				q.push(s->left);
			if(s->right)
				q.push(s->right);
		}
		// ans.push_back(s->val);
		bfs(q, ans);
	}
};
int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
