#include <stdio.h>
#include <limits.h>
int findMaximumSubarray(int a[], int left, int right){
    int mid, sum = 0, left_max, right_max, left_sum, right_sum;
    if(left<right){
        mid = (left + right)/2;
        left_max = findMaximumSubarray(a, left, mid);
        right_max = findMaximumSubarray(a, mid+1, right);
        left_sum = INT_MIN;
        right_sum = INT_MIN;
        for(int i = mid; i>=0;i--){
            sum += a[i];
            if(sum > left_sum)
                left_sum = sum;
        }
        sum = 0;
        for(int i = mid+1; i<=right; i++){
            sum += a[i];
            if(sum > right_sum)
                right_sum = sum;
        }
        sum = left_sum + right_sum;
        if(sum > left_max && sum > right_max)
            return sum;
        else if(left_max > sum && left_max > right_max)
            return left_max;
        else
            return right_max;
    }
    else return a[left];
}
int main() {
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    printf("%d",findMaximumSubarray(a,0,n-1));
    return 0;
}
