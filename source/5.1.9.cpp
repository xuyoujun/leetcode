// 5.1.9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct bnode {
	char data;
	struct bnode *left;
	struct bnode *right;
};
class solution {
public:
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
	int get_index(char target, char *nest) {
		char * p = nest;
		while (*p != target && *p) p++;
		if (!*p) return -1;
		return p - nest;
	}
	bool symmetric_Tree(struct bnode *root) {
		struct bnode * p, *q;
		p = root->left;
		q = root->right;
		stack<struct bnode *> s;
		s.push(p); s.push(q);
		while (!s.empty()) {
			p = s.top(); s.pop();
			q = s.top(); s.pop();
			if (!p && !q)continue;
			if (!p || !q)return false;
			if (p->data != q->data)return false;
			s.push(p->left); s.push(q->left);
			s.push(p->right); s.push(q->right);
		}
		return true;
	}

};
int main()
{
	solution btree;
	struct bnode * root;
	root = btree.create_Btree("ABCBC", "CBACB", 5);
	int result = btree.symmetric_Tree(root);
	printf("%d\n", result);
	system("pause");
	return 0;
}

