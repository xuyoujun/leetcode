// 5.4.6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>


struct bnode {
	struct bnode *right;
	struct bnode *left;
	struct bnode * next;
	int data;
};
struct bnode * create_Btree(int *preorder, int *inorder, int len);
void contact(struct bnode *root);

int main()
{
	struct bnode *root;
	int preorder[10] = {1,2,4,5,3,6,7 };
	int inorder[10] = { 4,2,5,1,6,3,7};
	root = create_Btree(preorder, inorder, 7);
	
	contact(root);
	while (root->left != nullptr) root = root->left;
	while (root != nullptr) {
		printf("%d ", root->data);
		root = root->next;
	}
	//printf("%d\n", isSum2(root, 22));
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
	root->next = nullptr;
	left_size = get_index(*preorder, inorder);
	if (-1 == left_size) {
		printf("Error!\n");
		exit(-1);
	}
	root->left = create_Btree(preorder + 1, inorder, left_size);
	root->right = create_Btree(preorder + left_size + 1, inorder + left_size + 1, len - left_size - 1);
	return root;
}


void contact(struct bnode *root) {
	if (nullptr == root) return;
	if(root->left != nullptr)
		root->left->next = root->right;
	if (root->right != nullptr) {
		if (nullptr != root->next)
			root->right->next = root->next->left;
		else
			root->right->next = nullptr;
	}
	contact(root->left);
	contact(root->right);

}

void contact2(struct bnode *root, struct bnode * brother) {
	if (nullptr == root) return;
	root->next = brother;
	contact2(root->left, root->right);
	if (brother)
		contact2(root->right, brother->right);
	else
		contact2(root->right, nullptr);
}