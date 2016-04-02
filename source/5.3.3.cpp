// 5.3.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>


struct bnode {

	struct bnode *right;
	struct bnode *left;
	int data;

};
bool validate_BST(struct bnode *root);
bool validate_BST2(struct bnode *root);
int bmax(struct bnode *root);
int bmin(struct bnode *root);
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
	if (-1 == left_size) {
		printf("Error!\n");
		exit(-1);
	}
	root->left = create_Btree(preorder + 1, inorder, left_size);
	root->right = create_Btree(preorder + left_size + 1, inorder + left_size + 1, len - left_size - 1);
	return root;
}
int main()
{
	struct bnode *root = create_Btree("fdcejik","cdefijk",7);
	printf("%d\n", validate_BST2(root));
	system("pause");

    return 0;
}

bool validate_BST(struct bnode *root) {
	if (nullptr == root) return true;
	else return bmax(root->left) < root->data &&  bmin(root->right) > root->data
		&& validate_BST(root->left) && validate_BST(root->right);
	//f(n) = 2f(n/2) + n;  =>  nlgn
}
bool do_validate_BST(struct bnode *root, int lower, int upper) {
	if (nullptr == root) return true;

	else return lower < root->data && root->data < upper && do_validate_BST(root->left, lower, root->data)
		&& do_validate_BST(root->right, root->data, upper);
	//f(n) = 2f(n/2) + O(1) =>  O(n)
}
bool validate_BST2(struct bnode *root) {
	if (nullptr == root) return true;
	else return bmax(root->left) < root->data &&  bmin(root->right) > root->data
		&& validate_BST(root->left) && validate_BST(root->right);
	//f(n) = 2f(n/2) + n;  =>  O(nlgn)
}

int bmax(struct bnode * root) {
	struct bnode *p = root;
	struct bnode *stk[100];
	int top = -1;
	int max = INT_MIN;
	while (-1 != top || nullptr != p) {
		if (nullptr != p) {
			stk[++top] = p;
			p = p->left;
		}
		else {
			p = stk[top--];
			if (p->data > max) max = p->data;
			p = p->right;
		}
	}
	return max;
}

int bmin(struct bnode * root) {
	struct bnode *p = root;
	struct bnode *stk[100];
	int top = -1;
	int min = INT_MAX;
	while (-1 != top || nullptr != p) {
		if (nullptr != p) {
			stk[++top] = p;
			p = p->left;
		}
		else {
			p = stk[top--];
			if (p->data < min) min = p->data;
			p = p->right;
		}
	}
	return min;
}