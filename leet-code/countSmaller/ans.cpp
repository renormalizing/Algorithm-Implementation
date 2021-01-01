#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> bits;
    int N;
    void add(int i, int x) {
        while (i <= N) {
            bits[i] += x;
            i += i & -i;
        }
    }
    int query(int i) {
        int res = 0;
        while (i > 0) {
            res += bits[i];
            i -= i & -i;
        }
        return res;
    }
    int reversePairs(vector<int>& nums) {
        // 离散化为排名
        set<int> s(nums.begin(), nums.end());
        map<int, int> m;
        for (auto x : s) {
            m[x] = m.size() + 1;
        }
        vector<int> ranks(nums.size(), 0);
        for (int i = 0; i < ranks.size(); ++i) {
            ranks[i] = m[nums[i]];
        }
        // 初始化树状数组
        N = ranks.size() + 1;
        bits = vector<int>(N + 1, 0);
        // 从后向前遍历查询更新，并获取结果
        int res = 0;
        for (int i = ranks.size() - 1; i >= 0; --i) {
            int t = (nums[i] > 0) ? ((nums[i] - 1) / 2) : (nums[i] / 2 - 1);
            auto it = m.lower_bound(t + 1);
            if (it != m.begin()) {
                res += query((--it)->second);
            }
            add(ranks[i], 1);
        }
        return res;
    }
};
int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++)
      cin >> a[i];
    cout << Solution().reversePairs(a) << endl;
}

