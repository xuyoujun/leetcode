// 6.5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

struct listNode {

	struct listNode * next;
	int data;
};
class solution {
public:
	//单链表的归并排序
	struct listNode *Recusise_Sort(struct listNode *head) {
		if (nullptr == head || nullptr == head->next) return head;  //0 或1 个节点
		struct listNode *first, *second;
		first = head;  
		second = head; 
		while (second->next != nullptr && second->next->next != nullptr) {//判断要根据second来
			first = first->next;
			second = second->next->next;
		}
		second = first->next;     //断开
		first->next = nullptr;
		first = second;
		struct listNode *l1 = Recusise_Sort(head);  //sort
		struct listNode *l2 = Recusise_Sort(first); //sort
		return meger_Sort(l1, l2);                 //combination
	}
	struct listNode *create_List(int A[],int n) {
		struct listNode head;
		struct listNode *p = &head;
		for (int i = 0; i < n; i++) {
			p->next = new struct listNode;
			p->next->data = A[i];
			p->next->next = nullptr;
			p = p->next;
		}
		return head.next;
	}
private:
	struct listNode *meger_Sort(struct listNode *first, struct listNode *second) {
		if (nullptr == first)return second;
		if (nullptr == second) return first;
		struct listNode head;
		struct listNode *p = &head;
		while (first && second) {
			if (first->data < second->data)p->next = first,first = first->next;
			else p->next = second, second = second->next;
			p = p->next;
		}
		p->next = first ? first : second;
		return head.next;
	}
};

int main()
{
	int data[10] = { 21,34,56,6,2,5,7,-1,3344,566 };
	class solution S;
	struct listNode * head = S.create_List(data, 10);
	for (struct listNode *p = head; p; p = p->next) {
		printf("%d  ", p->data);
	}
	printf("\n");
	head = S.Recusise_Sort(head);
	for (struct listNode *p = head; p; p = p->next) {
		printf("%d  ", p->data);
	}
	printf("\n");
	system("pause");
    return 0;
}

