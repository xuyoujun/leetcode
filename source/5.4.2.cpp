// 5.4.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
struct bnode {
	struct bnode *right;
	struct bnode *left;
	int data;

};

int maxDepth(struct bnode * root);
struct bnode * create_Btree(char *preorder, char *inorder, int len);
void traversal_postorder(struct bnode *root);
int main()
{
	struct bnode *root;
	root = create_Btree("ABDC", "DBAC",4);
	traversal_postorder(root);
	printf("The max deoth is %d\n", maxDepth(root));
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
				printf("%c\n", p->data);
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



int max(int a, int b) {
	return a < b ? b : a;
}
int maxDepth(struct bnode * root) {
	if (nullptr == root) return 0;
	else return max(maxDepth(root->right), maxDepth(root->left)) + 1;
}