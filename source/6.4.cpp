// 6.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
struct listNode {

	struct listNode * next;
	int data;
};

class solution {
	public:
		struct listNode *insert_Sort(struct listNode * list) {
			if (nullptr == list) return list;
			struct listNode head = {nullptr,-1};
			struct listNode *p; 
			struct listNode *pre;
			
			while (list) {
				p = head.next;
				pre = &head;
				while (p && p->data < list->data) {
				//	list = list->next;
					pre = p;
					p = p->next;
				}
				struct listNode *temp = list;
				list = list->next;
				pre->next = temp;
				temp->next = p;
			}
			return head.next;
		}
private:


};

int main()
{
    return 0;
}

