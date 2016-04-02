// 5.2.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
struct btree {
	char data;
	struct btree *left;
	struct btree *right;
};


struct btree * create_Tree(char *preorder, char * inorder, int len);
void binali(struct btree *root);
int main()
{
	struct btree *root = create_Tree("ABDCE", "DBACE", 5);
	binali(root);
	while (1);
    return 0;
}

void binali(struct btree *root) {

	if (NULL == root) return;
	printf("%c", root->data);
	binali(root->left);
	binali(root->right);
}

int get_posRoot(char *inorder, char root) {
	char *p = inorder;
	while (*p &&*p != root)p++;
	if (*p == NULL)return -1;
	return p - inorder;
}

/*����һ�Ŷ���������֪����ǰ����������
ǰ�򣺸�|������|������
����������|��|������
�ݹ齨��
*/
struct btree * create_Tree(char *preorder, char * inorder, int len) {
	if (0 == len)return nullptr;
	int posRoot;
	struct btree * Root = new struct btree;
	posRoot = get_posRoot(inorder, *preorder); //�����ڵ�λ��
	Root->data  = *preorder;
	Root->left  = create_Tree( preorder + 1,inorder,posRoot); //����������
	Root->right = create_Tree(preorder + 1 + posRoot,inorder + 1 + posRoot,len - posRoot - 1);
	return Root;
}