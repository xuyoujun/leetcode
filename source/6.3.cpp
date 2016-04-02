// 6.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<vector>
using namespace std;
struct listNode {
	struct listNode *next;
	int data;
};
class solution {
public:
	struct listNode * mergerKlist(vector <struct listNode *> klist) {
		struct listNode *p = klist[0];
		for (int i = 1; i < klist.size(); i++) {
			p = mergeList(p, klist[i]);
		}
	}
private:
	struct listNode *mergeList(struct listNode * l1, struct listNode *l2) {
		if (l1 == nullptr) return l2;
		if (nullptr == l2) return l1;
		struct listNode head;
		struct listNode *p = &head;
		while (l1 != nullptr && l2 != nullptr){ 
			if (l1->data < l2->data)p->next = l1;
			else p->next = l2;
			p = p->next;
		}
		return head.next;
	}
};

int main()
{
    return 0;
}
