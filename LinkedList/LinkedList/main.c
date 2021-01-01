//
//  main.c
//  LinkedList
//
//  Created by hao chen on 2020/2/24.
//  Copyright © 2020 hao chen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct list{
    int num;
    struct list *next;
};

struct list *CreateList(void){
    struct list *head = NULL;
    struct list *p;
    int no;
    printf("Input number(0 to end):");
    scanf("%d",&no);
    while(no!=0){
        p = (struct list*) malloc(sizeof(struct list));
        p->num = no;
        p->next = head;
        head = p;
        printf("Input number(0 to end):");
        scanf("%d",&no);
    }
    return head;
}
struct list *CreateListR(void){
    struct list *head,*rear,*p;
    int no;
    head = NULL;
    rear = NULL;
    printf("Input number(0 to end):");
    scanf("%d",&no);
    while(no!=0){
        p = (struct list*)malloc(sizeof(struct list));
        p->num = no;
        if(head==NULL)
            head = p;
        else rear->next = p;
        rear = p;
        printf("Input number(0 to end):");
        scanf("%d",&no);
    }
    if(rear != NULL){
        rear->next = NULL;
    }
    return head;
}
void PrintList(struct list *head){
    struct list *p = head;
    while(p!=NULL){
        printf("num = %d\n",p->num);
        p = p->next;
    }
}
struct list *ListInsert(struct list *head, struct list *p){
    struct list *tmp1, *tmp2;
    if (head==NULL){
        head = p;
        return head;
    }
    if(head->num>p->num){
        p->next = head;
        head = p;
        return head;
    }
    tmp1 = head;
    tmp2 = head->next;
    while(tmp2!=NULL && p->num > tmp2->num){
        tmp1 = tmp2;
        tmp2 = tmp2->next;
    }
    tmp1->next = p;
    p->next = tmp2;
    return head;
}
struct list *ListDelete(struct list *head, int num){
    struct list *tmp1, *tmp2;
    if(head->num == num){
        tmp1 = head;
        head = head->next;
        free(tmp1);
        return head;
    }
    tmp1 = tmp2 = head;
    while(tmp2!=NULL && tmp2->num != num){
        tmp1 = tmp2;
        tmp2 = tmp2->next;
    }
    if(tmp2!=NULL){
        tmp1->next = tmp2->next;
        free(tmp2);
        return head;
    }
    printf("not found\n");
    return head;
        
}
int main(int argc, const char * argv[]) {
    // insert code here...
    struct list *head1, *head2, *p;
    int no;
    head1 = CreateList();
    head2 = CreateListR();
    printf("Head Insert:\n");
    PrintList(head1);
    printf("Rear Insert:\n");
    PrintList(head2);
    
    printf("Input Insert Node(0 to end):");
    scanf("%d",&no);
    while(no!=0){
        p = (struct list*) malloc(sizeof(struct list));
        p->num = no;
        ListInsert(head2, p);
        printf("Input Insert Node(0 to end):");
        scanf("%d",&no);
    }
    PrintList(head2);
    printf("Input Delete Node(0 to end):");
    scanf("%d",&no);
    while(no!=0){
        ListDelete(head2, no);
        printf("Input Delete Node(0 to end):");
        scanf("%d",&no);
    }
    PrintList(head2);
    return 0;
}
