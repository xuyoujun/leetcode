// 5.4.7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

struct bnode {
	struct bnode * right;
	struct bnode *left;
	int data;

};
struct bnode * create_Btree(int *preorder, int *inorder, int len);
int sumNumbers(struct bnode *root);
int sumNumbers2(struct bnode *root,int);
int main()
{
	struct bnode *root;
	//int preorder[10] = { 5,4,11,7,2,8,13,4,5,1 };
	//int inorder[10] = { 7,11,2,4,5,13,8,5,4,1 };
	int preorder[10] = { 1,2,3};
	int inorder[10] = { 2,1,3};
	root = create_Btree(preorder, inorder, 3);
	printf("%d\n",sumNumbers2(root,0));
	system("pause");
	return 0;
}

int get_index(int target, int *nest) {
	int * p = nest;
	while (*p != target && *p) p++;
	if (!*p) return -1;
	return p - nest;
}

struct bnode * create_Btree(int *preorder, int *inorder, int len) {

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


//会把树的原来值破坏掉
int sumNumbers(struct bnode *root) {
	if (root == nullptr) return 0;

	if (root->left == nullptr && root->right == nullptr) {
		return root->data;
	}
	if (root->left != nullptr) root->left->data += root->data * 10;
	if (root->right != nullptr) root->right->data += root->data * 10;

	return sumNumbers(root->left) + sumNumbers(root->right);
}

//不会破坏原来的值
int sumNumbers2(struct bnode *root,int sum) {
	if (root == nullptr) return 0;

	if (root->left == nullptr && root->right == nullptr) {
		return sum * 10 + root->data;
	}
	//if (root->left != nullptr) root->left->data += root->data * 10;
	//if (root->right != nullptr) root->right->data += root->data * 10;

	return sumNumbers2(root->left ,sum * 10 + root->data) + sumNumbers2(root->right, sum * 10 + root->data);
}