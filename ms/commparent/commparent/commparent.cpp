// commparent.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

typedef struct node {
	struct node * parent;
	string data;
	int tag;
} node, *pnode;

class solution {

public:
	solution(int a) {
		count = 0;
		A = vector<pnode>(200, NULL);
	}
	void create_tree() {
		int n;
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			string parent;
			string son;
			cin >> parent;
			cin >> son;
			if (mapping.find(parent) == mapping.end()) {
				pnode p = new node;
				p->parent = NULL;
				p->tag = -1;
				p->data = parent;
				mapping[parent] = count;
				A[count++] = p;
			}
			if (mapping.find(son) == mapping.end()) {
				pnode p = new node;
				p->parent = NULL;
				p->tag = -1;
				p->data = son;
				mapping[son] = count;
				A[count++] = p;
			}

			int son_index        = mapping[son];
			int parent_index     = mapping[parent];
			A[son_index]->parent = A[parent_index];

		}
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			string s1;
			string s2;
			cin >> s1;
			cin >> s2;
			if(n == 0)
				cout << -1 << endl;
			else
				findCommParent(s1, s2, i);
		}

	}
private:
	void findCommParent(string s1, string s2,int tag) {
		pnode p1 = A[mapping[s1]];
		pnode p2 = A[mapping[s2]];

		while (p1) {
			//pnode parent = p1->parent;
			p1->tag = tag;
			p1 = p1->parent;
		}
		while (p2) {
			//pnode parent = p2->parent;
			if (p2->tag == tag) {
				cout << p2->data << endl;
				return;
			}
			p2 = p2->parent;
		}
		cout << -1 << endl;
	}

	map<string, int> mapping;
	int count;
	vector <pnode> A;// (100, NULL);
};

int main()
{
	solution S(0);
	S.create_tree();
	system("pause");
    return 0;
}

