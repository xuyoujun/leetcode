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
	struct bnode *p, *q;   //q,�������Ǽ�ס�ոշ��ʹ��Ľڵ㣬p��ǰ���ڷ��ʵĽڵ�
	p = root;
	int top = -1;
	do {
		while (nullptr != p) {
			stk[++top] = p;
			p = p->left;
		}
		q = nullptr;      //������˵��p��������Ϊ�գ��Ϳ��������ˣ���һֱ���������������ģ�ǰһ�����ʹ���Ϊnull
		while (-1 != top) {
			p = stk[top--];
			if (p->right == q) {  //p���������ѷ���
				printf("%d ", p->data);
				q = p;
			}
			else {//p��������û�з��ʣ���Ҫ��p��ջ������p��������
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
���Ҫʹ�õݹ�
����ʹ�ö�̬,��Ϊ���漰���Ż����������޺�Ч��
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