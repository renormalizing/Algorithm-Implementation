#include <stdio.h>
#include "heap.h"
void insert(int pq[], int length, int x){
    int walk = length;
    int parent = (walk - 1)/2;
    pq[length] = x;
//    注意插入法进行优先队列插入时，while停止条件时walk==0不能是parent<0，不然会死循环，因为(0-1)/2 = 0
    while(walk>0 && pq[parent] < x){
        pq[walk] = pq[parent];
        walk = parent;
        parent = (walk - 1)/2;
    }
    pq[walk] = x;
}
int maximum(int pq[]){
    return pq[0];
}
int extract_max(int pq[], int *length){
    int len = *length;
    int max = pq[0];
    swap(pq, 0, len-1);
    Heapify(pq, 0, len-1);
    *length = *length - 1;
    return max;
}
void increase_key(int pq[], int i, int val) {
    if (pq[i] > val)
        printf("Error!");
    else {
        pq[i] = val;
        int walk = i;
        int parent = (walk-1)/2;
        while(walk>0 && pq[parent] < pq[walk]){
            swap(pq, walk, parent);
            walk = parent;
            parent = (walk-1)/2;
        }
    }
}
//**************************
void heap_delete(int pq[], int *length, int i){
//    有可能需要交换的元素和最后一个元素在同一层，且值比最后一个元素小，交换后可能比其父节点大
    int len = *length;
    if(pq[i] > pq[len]){
        swap(pq, i, len-1);
        Heapify(pq, i, len-1);
    } else{
        increase_key(pq, i, pq[len-1]);
    }
    *length = *length - 1;
}
//**************************
int main() {
    int n, length = 0, tmp;
    scanf("%d", &n);
    int pq[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &tmp);
        insert(pq, length,tmp);
        length++;
    }
    increase_key(pq,n-1,maximum(pq)+1);
    for(int i=0; i<n; i++)
        printf("%d",pq[i]);
    return 0;
}
