#include <iostream>
class Solution {
private:
	bool grid[102][102]{};
	int digit_sum[102]{}, ans = 1;
public:
	int movingCount(int m, int n, int k) {
		return searching(m,n,k,0,0);
	}
	int searching(int m, int n, int k, int x, int y){
		grid[x][y] = true;
		if(x + 1 < n && !grid[x+1][y] && cal_digit_sum(x+1, y) <= k){
			ans++;
			searching(m,n,k, x+1, y);
		}
		if(y + 1 < m && !grid[x][y+1] && cal_digit_sum(x,y+1) <= k){
			ans++;
			searching(m,n,k,x,y+1);
		}
		return ans;
	}
	int cal_digit_sum(int x, int y){
		int sum  = 0;
		if(digit_sum[x] != 0 || x==0)
			sum += x;
		else{
			while (x>0){
				sum += x%10;
				x /= 10;
			}
		}
		if(digit_sum[y]!=0 || y==0)
			sum += y;
		else{
			while (y>0){
				sum += y%10;
				y /= 10;
			}
		}
		return sum;
	}
};
int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
