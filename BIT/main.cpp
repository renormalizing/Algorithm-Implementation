#include <iostream>
using namespace std;
int tree[21]{};
int MaxId = 20;
void update(int idx, int val){
	while(idx <= MaxId) {
		tree[idx] += val;
		idx += (idx & -idx);
	}
}
int prefix_sum(int idx){
	int sum = 0;
	while(idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}
int find_Ksmallest(int k){
	// using binary search
	int left = 0, right = MaxId, mid;
	int ans = -1;
	while(left <= right){
		mid = left + (right-left)/2;
		if(prefix_sum(mid) >= k){
			ans = mid;
			right = mid - 1;
		} else
			left = mid + 1;
	}
	return ans;
}
int main() {

	return 0;
}
