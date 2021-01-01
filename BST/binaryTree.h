//
// Created by hao chen on 2020/3/9.
//

#ifndef BST_BINARYTREE_H
#define BST_BINARYTREE_H
struct node{
	int key;
	int val;
	struct node* parent;
	struct node* left;
	struct node* right;
};
void insert_btree(struct node**, int, int);
void inorder_walk(struct node*);
struct node* search_btree(struct node*, int);
struct node* tree_min(struct node*);
struct node* tree_max(struct node*);
struct node* tree_successor(struct node*);
struct node* tree_predecessor(struct node*);
void delete_btree(struct node**, struct node*);
void transplant(struct node**, struct node*, struct node*);
#endif //BST_BINARYTREE_H
