#include <iostream>
#include <unordered_map>
using namespace std;
struct Node{
	int key, val;
	Node* prev, *next;
	Node(){
		val = 0;
		prev = NULL;
		next = NULL;
	}
	Node(int key_val, int value, Node* p, Node* q){
		key = key_val;
		val = value;
		prev = p;
		next = q;
	}
};
class LRUCache {
private:
	int cap, size = 0;
	unordered_map<int, Node*> m;
	Node* head, *tail; // head and end are boundaries
	void update(Node* p){
		p->prev->next = p->next;
		p->next->prev = p->prev;
		p->next = head->next;
		p->prev = head;
		head->next->prev = p;
		head->next = p;
	}
public:
	LRUCache(int capacity) {
		cap = capacity;
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->prev = head;
	}

	int get(int key) {
		auto it = m.find(key);
		if(it != m.end()) {
			update(it->second);
			return it->second->val;
		}
		else
			return -1;
	}

	void put(int key, int value) {
		auto it = m.find(key);
		if(it!=m.end()){
			it->second->val = value;
			update(it->second);
			return;
		}
		Node* p = new Node(key, value, head, head->next);
		head->next->prev = p;
		head->next = p;
		m[key] = p;
		size++;
		if(size > cap){
			Node* remove_node = tail->prev;
			remove_node->prev->next = tail;
			tail->prev = remove_node->prev;
			m.erase(remove_node->key);
			delete remove_node;
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main() {
	LRUCache cache = *new LRUCache( 2 /* 缓存容量 */ );
	cache.put(1, 1);
	cache.put(2, 2);
	cache.get(1);       // 返回  1
	cache.put(3, 3);    // 该操作会使得密钥 2 作废
	cache.get(2);       // 返回 -1 (未找到)
	cache.put(4, 4);    // 该操作会使得密钥 1 作废
	cache.get(1);       // 返回 -1 (未找到)
	cache.get(3);       // 返回  3
	cache.get(4);       // 返回  4

	return 0;
}
