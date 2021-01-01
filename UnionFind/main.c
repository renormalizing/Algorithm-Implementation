#include <stdio.h>
#include <stdbool.h>

int n, k;
int a[1000000], size[1000000];
int count;

int find_root(int i){
	while(a[i]!=i){
		i = a[i];
	}
	int root = a[i];
	while(a[i]!=root){
		int parent = a[i];
		a[i] = root;
		i = parent;
	}
	return root;
}
bool is_connected(int i, int j){
	int root1 = find_root(i), root2 = find_root(j);
	return root1==root2;
}
void weighted_union(int i, int j){
	int root1 = find_root(i), root2 = find_root(j);
	if(size[root1]>=size[root2]){
		a[root2] = root1;
		size[root1] += size[root2];
		count--;
	} else{
		a[root1] = root2;
		size[root2] += size[root1];
		count--;
	}
}
int main() {
	int tmp1, tmp2;
	scanf("%d%d", &n, &k);
	count = n;
	for (int i = 0; i < n; i++) {
		a[i] = i;
		size[i] = 1;
	}
	for (int i = 0; i < k; i++){
		scanf("%d%d", &tmp1, &tmp2);
		if(is_connected(tmp1,tmp2)) {
			printf("Already connected!\n");
			continue;
		}
		weighted_union(tmp1, tmp2);
	}
	printf("Components = %d", count);

	return 0;
}
