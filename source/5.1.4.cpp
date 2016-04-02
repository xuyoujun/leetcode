// 5.1.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
struct bnode {
	int data;
	struct bnode * left;
	struct bnode *right;
};
class Binary_tree {
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
	vector<vector<char>> traversal_level(struct bnode *root) {
		vector<vector<char>> result;
		vector<char> level;
		queue<struct bnode *> current, next;
		unsigned int rever = 0;
		current.push(root);
		while (!current.empty()) {
			while (!current.empty()) {
				struct bnode *node = current.front();
				current.pop();
				level.push_back(node->data);
				if (nullptr != node->left)next.push(node->left);
				if (nullptr != node->right)next.push(node->right);
			}
			swap(current, next);
			if ((rever & 0x01) == 0) {
				result.push_back(level);
				level.clear();
			}
			else {
				reverse(level.begin(), level.end());
				result.push_back(level);
				level.clear();
			}
			rever++;
		}
		return result;
	}
	/**********************flatten*********************/
	//�ǵݹ�
	void flatten(struct bnode *root) {
		stack<struct bnode*> stk;
		struct bnode* p;
		stk.push(root);
		while (!stk.empty()) {
			p = stk.top();
			stk.pop();
			if (p->right != nullptr) stk.push(p->right);
			if (p->left != nullptr) stk.push(p->left);
			p->left = nullptr;
			if (!stk.empty()) {
				p->right = stk.top();
			}
		}
	}

	//�ݹ�
	void flatten2(struct bnode *root) {
		if (!root)return;  //�ݹ����
		flatten(root->left);
		flatten(root->right);
		if (root->left == nullptr)return; 
		//������˵��root�����������������flattenת��
		/*
									root
								  /	     \	
								 ()       ()
								  \        \
								  ()        ()
								    \         \
									()         ()
								    
		ֻ��Ҫ��root->left �嵽root��root->right֮��
		*/
		struct bnode *p = root->left;
		while (p->right)p = p->right;
		p->right = root->right;
		root->right = root->left;
		root->left = nullptr;
	}

	void flatten3(struct bnode *root) {
		flatten(root, NULL);
	}
private:
	// �� root ���������������� tail ���ڸ��������
	struct bnode *flatten(struct bnode *root, struct bnode *tail) {
		if (NULL == root) return tail;
		root->right = flatten(root->left, flatten(root->right, tail));
		root->left = NULL;
		return root;
	}
	/**********************flatten end*********************/

};

int main()
{
	Binary_tree btree;
	struct bnode * root;
	root = btree.create_Btree("ABDCE", "DBACE", 5);
	vector<vector<char>> result = btree.traversal_level(root);
	vector<vector<char>>::iterator i;
	vector<char>::iterator j;
	for (i = result.begin(); i != result.end(); i++) {
		for (j = (*i).begin(); j != (*i).end(); j++) {
			printf("%c", *j);
		}
		printf("\n");
	}
	btree.flatten3(root);
	while (root) {
		printf("%c  ", root->data);
		root = root->right;
	}
	system("pause");
	return 0;
}

