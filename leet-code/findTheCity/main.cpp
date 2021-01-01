#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
		vector<vector<int>> dis(n, vector<int>(n, distanceThreshold+1));
		for(auto e : edges){
			dis[e[0]][e[1]] = e[2];
//			dis[e[1]][e[0]] = e[2];
		}
		vector<int> count(n);
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = i+1; j < n; ++j) {
					if(dis[i][j] > dis[min(i,k)][max(i,k)] + dis[min(k,j)][max(k,j)]) {
						dis[i][j] = dis[min(i,k)][max(i,k)] + dis[min(k,j)][max(k,j)];
					}
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j) {
				if(dis[i][j] <= distanceThreshold){
					count[i]++;
					count[j]++;
				}
			}
		}
		int ans = 0;
		for (int i = 1; i < n; ++i) {
			if(count[ans] >= count[i])
				ans = i;
		}
		return ans;
	}
};
int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
