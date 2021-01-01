#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
private:
	struct node{
		int count, val, loc;
	};
	unordered_map<int, node*> m;
	int len = 0;
	node** heap;
	void swap(int a, int b){
		heap[a]->loc = b;
		heap[b]->loc = a;
		node* tmp = heap[a];
		heap[a] = heap[b];
		heap[b] = tmp;
	}
	void heap_insert(node* n, int k){

		heap[len] = n;
		int walk = len, parent = walk/2;
		while(parent>= 1 && heap[walk]->count > heap[parent]->count){
			swap(walk, parent);
			walk = parent;
			parent = walk/2;
		}
	}
	void heap_update(node* n){
		int walk = n->loc, parent = walk/2;
		while(parent>= 1 && heap[walk]->count > heap[parent]->count){
			swap(walk, parent);
			walk = parent;
			parent = walk/2;
		}
	}
	void heapify(int i){
		int left = 2*i, right = 2*i+1;
		int largest = i;
		if(left <= len && heap[left]->count > heap[largest]->count)
			largest = left;
		if(right<= len && heap[right]->count > heap[largest]->count)
			largest = right;
		if(largest!=i){
			swap(i, largest);
			heapify(largest);
		}
	}
	int remove_max(){
		int ans = heap[1]->val;
		swap(1, len);
		len--;
		heapify(1);
		return ans;
	}
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		heap = new node*[nums.size()+1];
		int count = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if(m.count(nums[i]) == 0) {
				m[nums[i]] = new node{1, nums[i], len == nums.size() ? len : ++len};
				heap_insert(m[nums[i]], k);
			}
			else {
				m[nums[i]]->count++;
				heap_update(m[nums[i]]);
			}
		}
		vector<int> ans(k);
		for (int i = 0; i < k; ++i) {
			ans[i] = remove_max();
		}
		return ans;
	}
};

int main() {
	vector<int> a{3,0,1, 0};
	auto b = Solution().topKFrequent(a, 1);
	return 0;
}
