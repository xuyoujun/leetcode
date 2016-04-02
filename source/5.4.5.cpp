// 5.4.5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>


struct bnode {
	struct bnode *right;
	struct bnode *left;
	int data;
};
struct bnode * create_Btree(int *preorder, int *inorder, int len);
int dfs(struct bnode * root);
int sum_max = INT_MIN;
int main()
{
	struct bnode *root;
	int preorder[10] = { 5,4,11,7,2,8,13,4,5,1 };
	int inorder[10] = { 7,11,2,4,5,13,8,5,4,1 };
	root = create_Btree(preorder, inorder, 10);
	dfs(root);
	printf("the max path sum is %d\n", sum_max);
	//printf("%d\n", isSum2(root, 22));
	system("pause");
	return 0;
}

int max(int a, int b) {

	return a < b ? b : a;
}
int dfs(struct bnode * root) {
	if (nullptr == root) return 0;
	int L;
	int R;
	int sum = root->data;
	L = dfs(root->left);  //左子树最大的路径数值
	R = dfs(root->right); //右子树最大的路径数值
	if (L > 0) sum += L;
	if (R > 0) sum += R;
	sum_max = max(sum,sum_max);
	return max(L, R)> 0 ? max(L, R) + root->data : root->data; //返回本棵树的最大路径值
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


