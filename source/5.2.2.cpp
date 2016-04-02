// 5.2.2.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

struct bnode {
	int data;
	struct bnode * left;
	struct bnode *right;
};

struct bnode * create_btree(char *inorder, char *postorder, int len);
void traversal_inorder(struct bnode *root);
int main()
{
	struct bnode *root;
	root = create_btree("ABDCE", "DBACE", 5);
	traversal_inorder(root);
	system("pause");
	return 0;
}


void traversal_inorder(struct bnode *root) {
	struct bnode *stk[100];
	struct bnode *p;
	p = root;
	int top = -1;
	while (nullptr != p || -1 != top) {
		if (nullptr != p) {
			stk[++top] = p;
			p = p->left;
		}
		else {
			p = stk[top--];
			printf("%c\n", p->data);
			p = p->right;
		}
	}
}

int get_index(const char * str, const char target) {
	const char *p = str;
	while (*p != target) p++;
	return p - str;
}
struct bnode *create_btree(char * inorder, char * postorder, int len) {

	if (0 == len) return nullptr;
	struct bnode *root = new struct bnode;
	root->data = postorder[len - 1]; // 建跟
	int pos;
	pos = get_index(inorder, postorder[len - 1]);
	root->left = create_btree(inorder, postorder, pos);  //建左子树
	root->right = create_btree(inorder + pos + 1, postorder + pos, len - pos - 1); //建右子树
	return root;
}

