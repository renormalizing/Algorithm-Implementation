#include <iostream>
#include <list>
#include <queue>
using namespace std;
struct Node{
	int val;
	int depth = -1;
	Node* parent;
	list<Node*> children;
};
//int dfs(Node* root){
//	if(root->children.empty()) {
//		root->depth = 0;
//		return 0;
//	}
//	for (auto child : root->children) {
//		root->depth = max(root->depth,dfs(child)+1);
//	}
//	return root->depth;
//}
Node* bfs(Node* root){
	queue<Node*> q;
	Node* u;
	root->depth = 0;
	q.push(root);
	while(!q.empty()){
		u = q.front();
		q.pop();
		for(auto child:u->children){
			child->depth = u->depth + 1;
			q.push(child);
		}
	}
	return u;
}
int Diameter(Node* root){
	Node* endpoint1 = bfs(root);
	Node* endpoint2 = bfs(endpoint1);
	return endpoint2->depth;
	// if root is nor a node in the diameter
	// then its deepest subtree contains the diameter
}
Node* find_center(Node* nodes[], int n){
	// the node minimizes the remoteness
	int num_children[n];
	queue<Node*> q;
	memset(num_children, 0, sizeof(int)*n);
	bool selected[n];
	for (int i = 0; i < n; ++i) {
		num_children[i] = nodes[i]->children.size();
		if(num_children[i] == 0) {
			q.push(nodes[i]);
			selected[i] = true;
		}
	}
	while(!q.empty()){
		Node* u = q.front();
		q.pop();
		num_children[u->parent->val]--;
		if(num_children[u->parent->val] == 0)
			q.push(u->parent);
		selected[u->parent->val] = true;
	}
	for(int i = 0; i < n; i++){
		if(!selected[i])
			return nodes[i];
	}
}
int dfs(Node *root, int max_component[], int n){
	if(root->children.empty()) {
		max_component[root->val] = n-1;
		return 1;
	}
	int size = 1;
	for(auto child : root->children){
		int tmp = dfs(child, max_component, n);
		max_component[root->val] = max(tmp , max_component[root->val]);
		size += tmp;
	}
	max_component[root->val] = max( n - size , max_component[root->val]);
	return size;
}
Node* find_centroid(Node* nodes[], int n){
	// the nodes minimizes the size of max_component from cutting edge of it
	int* max_componet = new int[n];
	memset(max_componet, 0, n*sizeof(n));
	dfs(nodes[0], max_componet, n);
	int minimum = 0;
	for (int i = 1; i < n; ++i) {
		minimum = min(max_componet[i], minimum);
	}
	return nodes[minimum];
}
int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
