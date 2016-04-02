// 5.4.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include<queue>
using namespace std;
struct bnode {
	int data;
	struct bnode * left;
	struct bnode *right;
};
struct bnode * create_Btree(char *preorder, char *inorder, int len);
void traversal_postorder(struct bnode *root);
unsigned int minDepth(struct bnode *root);
unsigned int minDepth2(struct bnode *root);
int main()
{
	struct bnode *root;
	root = create_Btree("ABDC", "DBAC", 4);
	traversal_postorder(root);
	printf("depth is %d\n", minDepth2(root));
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
	if (-1 == left_size) {
		printf("Error!\n");
		exit(-1);
	}
	root->left = create_Btree(preorder + 1, inorder, left_size);
	root->right = create_Btree(preorder + left_size + 1, inorder + left_size + 1, len - left_size - 1);
	return root;
}

void traversal_postorder(struct bnode *root) {
	struct bnode *stk[100];
	struct bnode *p, *q;   //q,的作用是记住刚刚访问过的节点，p当前正在访问的节点
	p = root;
	int top = -1;
	do {
		while (nullptr != p) {
			stk[++top] = p;
			p = p->left;
		}
		q = nullptr;      //到这里说明p的左子树为空，就看右子树了；是一直沿着左子树下来的，前一个访问过的为null
		while (-1 != top) {
			p = stk[top--];
			if (p->right == q) {  //p的右子树已访问
				printf("%c\n", p->data);
				q = p;
			}
			else {//p的右子树没有访问，需要把p入栈，访问p的右子树
				stk[++top] = p;
				p = p->right;
				break;
			}
		}
	} while (-1 != top);
}


unsigned int min(unsigned int a, unsigned b) {
	if (a < b)return a;
	else return b;
}

//递归的主要思想是，当兄弟节点为空时，这时应该把兄弟节点设置为INT_MAX
unsigned int minDepth(struct bnode *root) {
	if (nullptr == root) return 0;
	if (root->left == nullptr && root->right == nullptr) return 1;
	else if (root->left == nullptr && nullptr != root->right)return minDepth(root->right) + 1;
	
	else 
		if(root->left != nullptr && nullptr == root->right)return minDepth(root->left) + 1;
	else 
		return min(minDepth(root->left), minDepth(root->right)) + 1;
	//f(n) = 2f(n/2) + O(1) => O(n)
}

//非递归，层次遍历，记下每个节点所在的层数，

unsigned int minDepth2(struct bnode *root) {
	int result;
	int level;
	struct bnode * temp;
	queue<pair<struct bnode *, int>> q;
	q.push(make_pair(root, 1));
	while (!q.empty()) {
		temp = q.front().first;
		level = q.front().second;
		q.pop();
		if (temp->left == nullptr && temp->right == nullptr)
			return level;
		if(temp->left)
			q.push(make_pair(temp->left, level + 1));  //左右孩子的层数要增加
		if (temp->right)
			q.push(make_pair(temp->right, level + 1));
	}

}