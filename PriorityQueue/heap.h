//
// Created by hao chen on 2020/2/29.
//

#ifndef PRIORITYQUEUE_HEAP_H
#define PRIORITYQUEUE_HEAP_H
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
#endif //PRIORITYQUEUE_HEAP_H
