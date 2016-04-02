// 5.1.8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct bnode {
	char data;
	struct bnode *left;
	struct bnode *right;
};

class solution {
public:
	bool is_Same_Tree(struct bnode *p, struct bnode *q) {
		stack<struct bnode *> stk;
		queue<struct bnode *> q;
		stk.push(p);
		stk.push(q);
		while (!stk.empty()) {
			p = stk.top(); stk.pop();
			q = stk.top(); stk.pop();
			if (!p && !q) return true;
			if (!p || !q) return false;
			if (p->data != q->data) return false;
			stk.push(p->left); stk.push(q->left);
			stk.push(p->right); stk.push(q->right);
		
		}
		return true;
	}


};


int main()
{

    return 0;
}

