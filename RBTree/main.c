#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "RBTree.h"

int main() {
	char command[10];
	scanf("%s", command);
	struct node* root = NULL;
	while (strcmp(command,"INSERT")==0){
		int key, val;
		scanf("%d%d", &val, &key);
//		属性值为key
		struct node*p = (struct node*) malloc(sizeof(struct node));
		p->key = key;
		p->val = val;
		RB_Insert(&root, p);
		scanf("%s", command);
	}
	while (strcmp(command,"FIND")==0){
		int key;
		scanf("%d", &key);
		struct node *p = search_btree(root, key);
		if(p)
			printf("%d\n", p->val);
		else
			printf("-1\n");
		scanf("%s", command);
	}
}

void RB_Fix(struct node ** root, struct node *z){
	while (z != *root && z->parent->color==RED){
		if(z->parent==z->parent->parent->left){
			struct node* uncle = z->parent->parent->right;
			if (uncle && uncle->color==RED){
				z->parent->color = BLACK;
				uncle->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			} else{
				if(z == z->parent->right){
					leftRotate(root, z->parent);
					z = z->left;
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				rightRotate(root, z->parent->parent);
			}
		} else{
			struct node* uncle = z->parent->parent->left;
			if(uncle && uncle->color == RED){
				uncle->color = BLACK;
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			} else{
				if(z == z->parent->left){
					rightRotate(root,z->parent);
					z = z->right;
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				leftRotate(root, z->parent->parent);
			}
		}
	}
	(*root)->color = BLACK;
}
void RB_Insert(struct node ** root, struct node *z){
	struct node* y = NULL, *x = *root;
	while(x!=NULL){
		y=x;
		if(z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if(y==NULL)
		*root = z;
	else if(z->key < y->key)
		y->left = z;
	else
		y->right = z;
	z->left = NULL;
	z->right = NULL;
	z->color = RED;
	RB_Fix(root, z);
}
void rightRotate(struct node ** root, struct node* y){
	struct node* parent = y->parent;
	struct node* x = y->left;
	y->left = x->right;
	if(x->right != NULL)
		x->right->parent = y;
	if(parent){
		if(parent->left == y)
			parent->left = x;
		else
			parent->right = x;
	} else
		*root = x;
	x->parent = parent;
	x->right = y;
	y->parent = x;
}
void leftRotate(struct node** root, struct node* x){
	struct node *parent = x->parent, *y = x->right;
	x->right = y->left;
	if(y->left)
		y->left->parent = x;
	if(parent){
		if(parent->left==x)
			parent->left = y;
		else
			parent->right = y;
	} else
		*root = y;
	y->parent = parent;
	y->left = x;
	x->parent = y;
}
struct node* search_btree(struct node* root, int key){
	struct node* walk = root;
	while(walk && walk->key != key){
		if(key < walk->key){
			walk = walk->left;
		} else
			walk = walk->right;
	}
	return walk;
}
struct node* tree_min(struct node* root){
	struct node* walk = root;
	while(walk->left){
		walk = walk->left;
	}
	return walk;
}
struct node* tree_max(struct node* root){
	struct node* walk = root;
	while(walk->right){
		walk = walk->right;
	}
	return walk;
}
struct node* tree_successor(struct node* node){
//	return NULL if the node is at the most right
	if(node->right){
		return tree_min(node->right);
	} else{
		struct node* walk = node, *parent = walk->parent;
		while(parent!=NULL && walk == parent->right){
			walk = parent;
			parent = walk->parent;
		}
		return parent;
	}
}
struct node* tree_predecessor(struct node* node){
	struct node* parent = node->parent;
	if(node->left){
		return tree_max(node->left);
	} else{
		struct node* walk = node;
		while(parent!=NULL && walk == parent->left){
			walk = parent;
			parent = walk->parent;
		}
		return parent;
	}
}
void inorder_walk(struct node* root){
	if(root) {
		inorder_walk(root->left);
		printf("The val is %d\n", root->val);
		printf("The successor is %d\n", tree_successor(root)? tree_successor(root)->val:-1);
		printf("The predecessor is %d\n",tree_predecessor(root)? tree_predecessor(root)->val:-1);
		inorder_walk(root->right);
	}
}
