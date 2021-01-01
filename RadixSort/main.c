#include <stdio.h>
#include <math.h>
void  counting_sort(int a[], int n, int k, int dig, int factor){
//    inplace
    int c[k+1], b[n];
    for(int i = 0; i <= k; i++)
        c[i] = 0;
    for(int i = 0; i < n; i++)
        c[(a[i]/dig)%factor]++;
    for(int i = 1; i <= k; i++)
        c[i] = c[i-1] + c[i];
    for(int j = n - 1; j >= 0; j--){
        b[c[(a[j]/dig)%factor]-1] = a[j];  // 注意是在b的c[(a[j]/dig%10] - 1处插入
        c[(a[j]/dig)%factor] -= 1;
    }
    for(int i = 0; i < n; i++)
        a[i] = b[i];
}
int getMax(int a[], int n){
    int max = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] > max)
            max = a[i];
    }
    return max;
}
void radix_sort(int a[], int n){
    int max = getMax(a, n);
//    基于n的大小对数字的位数进行分割
    int r = (int)log10(n) > 1 ? (int) log10(n) : 1;
    int factor = (int) pow(10, r);
    int dig = factor;
    for(; max / dig > 0; dig *= factor){
        counting_sort(a, n, (int)(pow(10, r+1) - 1), dig, factor);
    }
}
int main() {
    int arr[] = {99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999, 23123, 123345 , 43543, 45345345};
    int n = sizeof(arr)/sizeof(arr[0]);
    radix_sort(arr, n);
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
