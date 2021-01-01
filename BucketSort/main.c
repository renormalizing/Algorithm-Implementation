#include <stdio.h>
#include <stdlib.h>
struct Bucket{
    double val;
    struct Bucket *prev;
    struct Bucket *next;
};
struct Bucket *buckets[10000];
void bucket_insert(int len, double val);
void BucketSort(double a[], int n);
void InsertionSort(struct Bucket *head);
void TraverseList(struct Bucket *head);

int main() {
    double a[] = {0.12,0.43,0.4,0.54,0.78,0.12,0.22};
    int n = sizeof(a)/ sizeof(double);
    BucketSort(a, n);
    for (int i = 0; i < n; i++){
        TraverseList(buckets[i]);
    }
    return 0;
}


void bucket_insert(int len, double val){
    struct Bucket *p;
    int index = (int) val * len;
    p = (struct Bucket*) malloc(sizeof(struct Bucket));
    p->val = val, p->next = NULL, p->prev = NULL;
    if(buckets[index]==NULL)
        buckets[index] = p;
    else{
        p->next = buckets[index];
        buckets[index]->prev = p;
        buckets[index]  = p;
    }
}
//[0,1)桶排序
void BucketSort(double a[], int n){
    for(int i = 0; i < n; i++)
        buckets[i] = NULL;
    for(int i=0; i<n; i++){
        bucket_insert(n, a[i]);
    }
    for (int i = 0; i < n; i++){
        InsertionSort(buckets[i]);
    }
}
void InsertionSort(struct Bucket *head){
    if(head==NULL)
        return;
    struct Bucket *p = head->next, *q;
    while(p!=NULL){
        q = p;
        double val = p->val;
        while(q->prev!=NULL && q->prev->val > val){
            q->val = q->prev->val;
            q = q->prev;
        }
        q->val = val;
        p = p->next;
    }
}
void TraverseList(struct Bucket *head){
    struct Bucket *p = head;
    while(p!=NULL) {
        printf("%lf ", p->val);
        p = p->next;
    }
}
