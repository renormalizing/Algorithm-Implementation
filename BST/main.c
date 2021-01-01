#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binaryTree.h"

int main() {
	char command[10];
	scanf("%s", command);
	struct node* root = NULL;
	while (strcmp(command,"INSERT")==0){
		int key, val;
		scanf("%d%d", &val, &key);
//		属性值为key
//		struct node*p = (struct node*) malloc(sizeof(struct node));
//		p->key = key;
//		p->val = val;
		insert_btree(&root, key, val);
		scanf("%s", command);
	}
//	inorder_walk(root);
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
//	struct node* root = NULL;
//	int a[] = {9,3,2,4,6,5,7,8,1};
//	for(int i = 0; i < 9; i++)
//		insert_btree(&root, a[i]);
//	inorder_walk(root);
//	printf("\n Minimum is %d. Maximum is %d.\n", tree_min(root)->key, tree_max(root)->key);
//	struct node* p = search_btree(root, 4);
//	delete_btree(&root, p);
//	inorder_walk(root);
//	int e = 9;
//	struct node* find = search_btree(root, e);
//	if(find)
//		printf("\n%d is in the tree", find->key);
//	else
//		printf("%\nd isn't in the tree", e);
	return 0;
}

void insert_btree(struct node** root_link, int key, int val){
	struct node*p;
	p = (struct node*)malloc(sizeof(struct node));
	p->key = key, p->val = val, p->parent = NULL, p->left = NULL, p->right = NULL;
	if(!*root_link){
		*root_link = p;
	}
	else{
		struct node *walk = *root_link, *parent = *root_link;
		while(walk){
			parent = walk;
			if(walk->key >= key){
				walk = walk->left;
			}
			else{
				walk = walk->right;
			}
		}
		if(key <= parent->key){
			parent->left = p;
			p->parent = parent;
		}
		else{
			parent->right = p;
			p->parent = parent;
		}
	}
}
void inorder_walk(struct node* root){
	if(root) {
		inorder_walk(root->left);
		printf("The key is %d\n", root->key);
		printf("The successor is %d\n", tree_successor(root) ? tree_successor(root)->key : -1);
		printf("The predecessor is %d\n", tree_predecessor(root) ? tree_predecessor(root)->key : -1);
		inorder_walk(root->right);
	}
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
void transplant(struct node** root, struct node* u, struct node* v){
	if(u->parent==NULL){
//		改变树的根
		*root = v;
	} else if(u == u->parent->left){
		u->parent->left = v;
	} else{
		u->parent->right = v;
	}
//	有可能v是NULL
	if(v!=NULL)
		v->parent = u->parent;
}
void delete_btree(struct node **root, struct node* z){
	if(z->left==NULL)
		transplant(root, z, z->right);
	else if(z->right==NULL)
		transplant(root, z, z->left);
	else{
		struct node* successor = tree_successor(z);
		if (successor->parent != z){
			transplant(root, successor, successor->right);
			successor->right = z->right;
			z->right->parent = successor;
		}
		transplant(root, successor, z);
		successor->left = z->left;
		z->left->parent = successor;
	}
}