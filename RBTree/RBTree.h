//
// Created by hao chen on 2020/3/13.
//

#ifndef RBTREE_RBTREE_H
#define RBTREE_RBTREE_H
#define RED true
#define BLACK false
#include <stdbool.h>

struct node{
	int key;
	int val;
	struct node* parent;
	struct node* left;
	struct node* right;
	bool color;
};
void inorder_walk(struct node*);
struct node* search_btree(struct node*, int);
struct node* tree_min(struct node*);
struct node* tree_max(struct node*);
struct node* tree_successor(struct node*);
struct node* tree_predecessor(struct node*);
void rightRotate(struct node **, struct node*);
void leftRotate(struct node **, struct node*);
void RB_Fix(struct node **, struct node*);
void RB_Insert(struct node **, struct node *);
#endif //RBTREE_RBTREE_H
