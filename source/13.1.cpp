// 13.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
int min(int a, int b) {
	return a < b ? a : b;
}

class Solution {
public:
	int triangle(vector <vector<int>>& triangle) {
		int n = triangle.size();
		int *f = new int[n];
		for (int i = n - 1; i >= 0; i--)
			for (int j = 0; j < i + 1; j++) {
				f[j] = (i == n - 1 ? triangle[i][j] : (min(f[j], f[j + 1]) + triangle[i][j]));
			}
		n = f[0];
		delete f;
		return n;
	}
};
int main()
{
	vector <vector<int>> triangle;
	triangle.push_back(vector<int>{2});
	triangle.push_back(vector<int>{3,4});
	triangle.push_back(vector<int>{6,5,7});
	triangle.push_back(vector<int>{4,1,8,3});
	Solution S;
	cout << S.triangle(triangle);
	system("pause");
    return 0;
}

