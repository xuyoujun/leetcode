// 5.4.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <queue>
using namespace std;
struct bnode {
	struct bnode * right;
	struct bnode * left;
	int data;
};
struct bnode * create_Btree(int *preorder, int *inorder, int len);
void isSum(struct bnode * root, int sum,vector <int> &curr, vector<vector<int>> &result);
//bool isSum2(struct bnode * root, int sum);
int main()
{
	struct bnode *root;
	int preorder[10] = { 5,4,11,7,2,8,13,4,5,1 };
	int inorder[10] = { 7,11,2,4,5,13,8,5,4,1 };
	root = create_Btree(preorder, inorder, 10);
	vector <vector<int>> result;
	vector <int> curr;
	isSum(root, 22, curr, result);
	int i, j;
	for (i = 0; i < result.size(); i++) {
		for (j = 0; j < result[i].size(); j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
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
	left_size = get_index(*preorder, inorder);
	if (-1 == left_size) {
		printf("Error!\n");
		exit(-1);
	}
	root->left = create_Btree(preorder + 1, inorder, left_size);
	root->right = create_Btree(preorder + left_size + 1, inorder + left_size + 1, len - left_size - 1);
	return root;
}




void isSum(struct bnode *root, int sum, vector <int> &curr, vector<vector<int>> &result){

	if (root == nullptr)return;
	curr.push_back(root->data);
	if (root->left == nullptr && root->right == nullptr) {
		if (sum == root->data)
			result.push_back(curr);
	}
	//	return sum == root->data;
	isSum(root->left, sum - root->data, curr, result);
	isSum(root->right, sum - root->data,curr,result);
	curr.pop_back();           //这一句的目的是删除访问过的一些节点，这些节点如果满足和为sum 则已加入result。
	//删除节点的左右子树都已经访问过了，如果子树上的路径有满足条件的，已经加入到result里面过了。。
	//删除节点是遍历树时，随着回退路径进行的。
}


