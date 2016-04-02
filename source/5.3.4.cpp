// 5.3.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
struct bnode {
	int data;
	struct bnode * left;
	struct bnode *right;
};

struct bnode * sortedArrayToBST(int num[], int start, int end);

void traversal_preorder(struct bnode *root) {
	struct bnode *stk[100];
	struct bnode *p;
	p = root;
	int top = -1;
	while (nullptr != p || -1 != top) {
		if (nullptr != p) {
			printf("%d", p->data);
			stk[++top] = p;
			p = p->left;
		}
		else {
			p = stk[top--];
			p = p->right;
		}
	}
}
int main()
{
	int num[5] = { 1,2,3,4,5 };
	struct bnode * root = sortedArrayToBST(num, 0, 4);
	traversal_preorder(root);
	system("pause");
    return 0;
}


struct bnode * sortedArrayToBST(int num[],int start,int end) {

	if (start > end) return nullptr;
	struct bnode * root = new struct bnode;
	int mid = (start + end) / 2;
	root->data = num[mid];
	root->left = sortedArrayToBST(num, start, mid - 1);
	root->right = sortedArrayToBST(num, mid + 1, end);
	return root;
}