#include <stdio.h>
void swap(int a[], int i, int j){
    int tmp;
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
void Heapify(int a[], int i,int n){
    int left, right, largest;
    left = 2*i+1;
    right = 2*i+2;
    largest = i;
    if(left<n && a[left] > a[largest]){
        largest = left;
    }
    if(right<n&& a[right]> a[largest]){
        largest = right;
    }
    if(largest!=i){
        swap(a,largest,i);
        Heapify(a, largest, n);
    }
}
void buildHeap(int a[], int n){
    int parent;
    parent = (n-2)/2;
    for(int i = parent; i>=0;i--){
        Heapify(a,i,n);
    }
}
int remove_max(int a[], int n){
    int ans = a[0];
    swap(a,0,n-1);
    Heapify(a,0,n-1);
    return ans;
}
void HeapSort(int a[],int n){
    buildHeap(a, n);
    for(int i = n-1;i>=1;i--){
        swap(a,0,i);
        Heapify(a,0,i);
    }

}
int main() {
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i<n;i++)
        scanf("%d",&a[i]);
    buildHeap(a,n);
    HeapSort(a,n);
    for(int i = 0; i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
