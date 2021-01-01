#include <stdio.h>
void swap(int a[], int i, int j){
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
int partition(int a[], int p, int r){
    int i = p-1;
    for(int j=p; j<r; j++){
        if(a[j]<=a[r]){
            i += 1;
            swap(a, i, j);
        }
    }
    swap(a, i+1, r);
    return i+1;
}
void quick_sort(int a[], int p, int r){
    if(p<r) {
        int q = partition(a, p, r);
        quick_sort(a, p, q-1);
        quick_sort(a, q+1, r);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    quick_sort(a,0,n-1);
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }

    return 0;
}
