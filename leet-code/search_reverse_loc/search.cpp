#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left = 0, right = nums.size() - 1;
        int mid;
        int min = -1;
        if(nums.size() == 0)
            return -1;
        while(left<=right){
            mid = left + (right-left)/2;
            if(nums[mid] >= nums[0]){
                min = mid;
                left = mid+1;
            }
            else
                right = mid - 1;
        }
        if(min == nums.size() - 1){
            left = 0;
            right = nums.size() - 1;
        }
        else if(target < nums[0]){
            left = min + 1;
            right = nums.size() - 1;
        }else if(target > nums[0]){
            left = 1;
            right = min;
        }else
            return 0;
        mid = left + (right - left)/2;
        while(left<=right){
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
            mid = left + (right - left)/2;
        }

        return -1;

    }
};
int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++)
        cin >> a[i];
    int target;
    cin >> target;
    cout << Solution().search(a, target);
}
