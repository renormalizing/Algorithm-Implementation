#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
struct Node{
	char data;
	unsigned frequency;
	Node* left = nullptr;
	Node* right = nullptr;
	Node(char data, unsigned frequency){
		this->data = data;
		this->frequency = frequency;
	}
//	bool operator < (Node node) const {
//		return frequency > node.frequency;
//	}
};
struct compare{
	bool operator()(Node* l, Node* r){
		return l->frequency > r->frequency;
	}
};

priority_queue<Node*, vector<Node*>, compare> Q;
Node* construct_btree(char data[], unsigned freq[], int size){
	for (int i = 0; i < size; ++i) {
		Q.push(new Node(data[i], freq[i]));
	}
	for (int i = 0; i < size-1; ++i) {
		Node* x = Q.top();
		Q.pop();
		Node* y = Q.top();
		Q.pop();
		Node* z = new Node('$', x->frequency + y->frequency);
		z->left = x;
		z->right = y;
		Q.push(z);
	}
	return Q.top();
}

void print_codes(Node* root, string str){
	if(!root)
		return;
	if(root->data != '$')
		cout << root->data << ':' << str << '\n';
	print_codes(root->left, str+'0');
	print_codes(root->right, str + '1');
}
int main() {

	char arr[] = { 'f', 'e', 'c', 'b', 'd', 'a' };
	unsigned freq[] = { 5, 9, 12, 13, 16, 45 };

	int size = sizeof(arr) / sizeof(arr[0]);

	Node *root = construct_btree(arr, freq, size);
	print_codes(root, "");
	return 0;
}
