// 6.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

struct listNode {
	struct listNode * next;
	int data;
};
int main()
{
    return 0;
}


struct listNode * merge_Sorted_List(struct listNode *l1, struct listNode *l2) {

	if (nullptr == l1) return l2;
	if (nullptr == l2) return l1;
	struct listNode head;// = new struct listNode;
	struct listNode *p = &head;
	while (nullptr != l1 && nullptr != l2) {
		if (l1->data < l2->data)p->next = l1, l1 = l1->next;
		else p->next = l2, l2 = l2->next;
		p = p->next;
	}
	if (nullptr != l1) p->next = l1;
	else p->next = l2;      //p->next = (nullptr != l1) ?l1 : l2;
	return head.next;
}