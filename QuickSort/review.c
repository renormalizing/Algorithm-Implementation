#include <stdio.h>
void swap(int* a, int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
//int partition(int* a, int l, int r){
//    int i = l-1, j = r+1;
//    while(i < j){
//        while(a[--j] > a[l]);
//        while(a[++i] <= a[l]);
//        if(i < j)
//            swap(a, i, j);
//    }
//    swap(a, j, l);
//    return j;
//}
int partition(int* a, int l, int r){
    int i = l;
    for(int j = l+1; j <= r; j++){
        if(a[j] < a[l]){
            swap(a, ++i, j);
        }
    }
    swap(a, l, i);
    return i;
}
void quicksort(int* a, int l, int r){
    if(l >= r)
        return;
    int p = partition(a, l, r);
    quicksort(a, l, p-1);
    quicksort(a, p+1,r);

}
int main(){
    int a[] = {3,-1,2,4,5,6,2};
    quicksort(a, 0, 4);
    for(int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    return 0;
}
