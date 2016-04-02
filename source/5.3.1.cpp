// 5.3.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include  <iostream>
#include <vector>
using namespace std;
struct bnode {
	int data;
	struct bnode *left;
	struct bnode *right;

};


vector<struct bnode *> numTree(int start,int end);


int numTree2(int n);


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
				printf("%d ", p->data);
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
int main()
{
	vector<struct bnode *> subtree = numTree(1,5);
	for (auto i : subtree) {
		traversal_postorder(i);
		printf("\n");
	}
	system("pause");
	return 0;
}



/*
这个要使用递归
不能使用动态,因为不涉及到优化，不满足无后效性
*/
vector<struct bnode*> numTree(int start,int end) {
	vector<struct bnode*> f;
	int k;
	if (start > end) {
		f.push_back(nullptr);
		return f;
	}
	for (k = start; k <= end; k++) {
		vector<struct bnode *> subright = numTree(start, k - 1);
		vector<struct bnode *> subleft =  numTree(k + 1, end);
		struct bnode * node = new struct bnode;
		node->data = k;
		for(auto i:subright){
			for (auto j : subleft) {
				node->left = i;
				node->right = j;
				f.push_back(node);
			}
		}
	}
	return f;
}