// 13.9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	int editDistance(string word1, string word2) {
		int m = word1.size();
		int n = word2.size();
		vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i <= m;i++) {
			f[i][0] = i;		
		}
		for (int i = 0; i <= n; i++) {
			f[0][i] = i;
		}
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				if (word1[i - 1] == word2[j - 1]) {
					f[i][j] = f[i - 1][j - 1];
				}
				else {
					int temp = min(f[i - 1][j - 1], f[i - 1][j]);
					temp = min(f[i][j - 1], temp);
					f[i][j] = temp + 1;
				}
			
			}
		return f[m][n];
		
	}
private:
	int min(int a, int b) {
		return a > b ? b : a;
	}

};
int main()
{
    return 0;
}

