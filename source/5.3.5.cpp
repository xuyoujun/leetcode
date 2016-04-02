// 5.3.5.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

struct bnode {
	struct bnode * left;
	struct bnode * right;
	int data;
};
struct ListNode {
//	struct ListNode *pre;
	struct ListNode *next;
	int data;
};
struct bnode * sortedListToBST(struct ListNode * head, int len);
struct bnode * sortedListToBST(struct ListNode *head);
void traversal_inorder(struct bnode *root) {
	struct bnode *stk[100];
	struct bnode *p;
	p = root;
	int top = -1;
	while (nullptr != p || -1 != top) {
		if (nullptr != p) {
			stk[++top] = p;
			p = p->left;
		}
		else {
			p = stk[top--];
			printf("%d\n", p->data);
			p = p->right;
		}
	}
}
int main()
{
	struct ListNode *head = new struct ListNode,*temp;
	head->data = 1;
	head->next = new struct ListNode;
	temp = head->next;
	temp->data = 2;
	temp->next = new struct ListNode;
	temp = temp->next;
	temp->data = 3;
	temp->next = nullptr;
	struct bnode * root;
	root = sortedListToBST(head);
	traversal_inorder(root);
	system("pause");
    return 0;
}

//方法1 ： O(nlgn)
int get_data(struct ListNode *head, int len) {
	while(--len)
		head = head->next;
	return head->data;
}
struct ListNode * get_head(struct ListNode *head, int len) {
	while (--len)head = head->next;
	return head;
}
struct bnode * sortedListToBST(struct ListNode  *head, int len) {
	if (len == 0) return nullptr;
	struct bnode * root = new struct bnode;
	int mid = (len + 1) / 2;
	root->data = get_data(head, mid);
	root->left = sortedListToBST(head, mid - 1);
	root->right = sortedListToBST(get_head(head, mid + 1),len - mid);
	return root;
}



//方法2 O(n)
struct bnode * sortedListToBST2(struct ListNode  *&head,int start, int end) {
	if (start > end) return nullptr;
	int mid = start + (end - start) / 2; //mid = (end + start)/2 is ok，but may lead to overflow
	struct bnode * left = sortedListToBST2(head, start, mid - 1);
	struct bnode * root = new struct bnode;
	root->data = head->data;
	root->left = left;
	head = head->next;
	root->right = sortedListToBST2(head,mid + 1, end);
	return root;
}

struct bnode * sortedListToBST(struct ListNode *head) {
	int n = 0;
	struct ListNode *p = head;
	while (p) {
		n++;
		p = p->next;
	}
	return sortedListToBST2(head, 0, n - 1);
}
