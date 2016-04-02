// 5.1.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

struct bnode {
	int data;
	struct bnode * left;
	struct bnode *right;
};

struct bnode * create_Btree(char *preorder,char *inorder, int len);
void travel_preorder(struct bnode *);
void traversal_preorder(struct bnode *root);
int main()
{
	struct bnode *root;
	root = create_Btree("ABDCE", "DBACE",5);
	traversal_preorder(root);
	system("pause");
    return 0;
}

int get_index(char target, char *nest) {
	char * p = nest;
	while (*p != target && *p) p++;
	if (!*p) return -1;
	return p - nest;
}

struct bnode * create_Btree(char *preorder, char *inorder, int len) {
	
	if (0 == len)return nullptr;
	struct bnode *root = new struct bnode;
	int left_size;
	root->data = *preorder;
	left_size = get_index(*preorder, inorder);
	root->left = create_Btree(preorder + 1, inorder, left_size);
	root->right = create_Btree(preorder + left_size + 1, inorder + left_size + 1, len - left_size - 1);
	return root;
}

void travel_preorder(struct bnode *root) {
	struct bnode * stk[100];
	struct bnode *p;
	int top = -1;
	stk[++top] = root;
	while (top != -1) {
		p = stk[top--];
		printf("%c\n", p->data);
		if (nullptr != p->right)stk[++top] = p->right;  //栈中先放右子树
		if (nullptr != p->left)stk[++top]  = p->left;   //再放左子树
	}
}

void traversal_preorder(struct bnode *root) {
	struct bnode *stk[100];
	struct bnode *p;
	p = root;
	int top = -1;
	while (nullptr != p || -1 != top) {
		if(nullptr != p) {
			printf("%c ", p->data);
			stk[++top] = p;
			p = p->left;
		}
		else {
			p = stk[top--];
			p = p->right;
		}
	}
}