// 8.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	void subSet(int A[], int start, int end,int n) {
		cout << "null" << endl;
		for (int i = 1; i <= n; i++) {
			subSet(A, start, end, i, i);
		}
	}
	
	vector <vector<int>> subSet2(vector<int> &s) {
		sort(s.begin(), s.end());
		vector<int> path;
		vector <vector<int>> result;
		subSet_pri2(s, path, result, 0);
		return result;
	}
	vector <vector<int>> subSet3(vector<int> &s) {
		sort(s.begin(), s.end());
		vector <bool> selected(s.size(), false);
		vector<vector<int>> result;
		subSet3_pri(s,0,selected,result);
		return result;
	}
	vector <vector<int>> subSet4(vector<int> &s) {
		int len = s.size();
		int sum = 1 << len;
		vector <vector<int>> result;
		vector <int> v;
		for (int i = 0; i < sum; i++) {
			for (int j = 0; j < len; j++) {
				if (i & 1 << j) v.push_back(s[j]);
			}
			result.push_back(v);
			v.clear();
		}
		return result;
	}
  private:
void subSet(int A[], int start, int end, int num, int n) {
	if (0 == num) {
		for (int i = 0; i < n; i++)
			cout << B[i];
		cout << endl;
	}
	else {
		for (int i = 0; i <= end - start + 1 - num; i++) {
			B[n - num] = A[start + i];
			subSet(A, start + i + 1, end, num - 1, n);
		}
	}
}
	void subSet_pri2(vector <int > &s, vector <int> &path, vector<vector <int>> &result, int step) {
		if (step == s.size()) {
			result.push_back(path);
			return;
		}
		subSet_pri2(s, path, result, step + 1);
		path.push_back(s[step]);
		subSet_pri2(s, path, result, step + 1);
		path.pop_back();
	}
	int B[20];

	void subSet3_pri(vector<int> &s, int step, vector<bool> &selected, vector<vector<int>> &result) {
		if (step == s.size()) {
			vector<int> subset;
			for (int i = 0; i < s.size(); i++) {
				if (selected[i]) subset.push_back(s[i]);
			}
			result.push_back(subset);
			return;
		}
		selected[step] = false;
		subSet3_pri(s, step + 1, selected, result);
		selected[step] = true;
		subSet3_pri(s, step + 1, selected, result);
	}
};
int main()
{
	class Solution S;
	//int A[20] = { 1,2,3,4,5,6,7 };
	//S.subSet(A, 0, 6,7);
	vector <int > s;
	for (int  i = 1; i < 4;i++) {
		s.push_back(i);
	}
	vector <vector<int>> result = S.subSet4(s);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j];
		}
		cout << endl;
	}
	system("pause");
    return 0;
}

