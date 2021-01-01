#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> floyd_warshall(vector<vector<int>>& adj){
	vector<vector<int>> c(adj);
	int n = adj.size();
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
			}
		}
	}
	return c;
}
int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
