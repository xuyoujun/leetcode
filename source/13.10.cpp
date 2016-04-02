// 13.10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include<iostream>
using namespace std;


class Solution {

public:
	int numDecoding(string &password) {
		int m = password.size();
		if (0 == m)return 0;
		vector <int> f(m + 1, 0);
		
		f[0] = 1;
		for (int i = 1; i < m; i++) {
			if (password[i - 1] > '2')
				f[i] = f[i - 1];
			else  if (password[i - 1] == '1') {
					f[i] = f[i - 1] + 1;
				}
			else {
				if (password[i] <= '6')
					f[i] = f[i - 1] + 1;
				else
					f[i] = f[i - 1];
			}	
		}

		return f[m - 1];
	}
private:

};

int main()
{
	Solution S;
	string s = "1234";
	cout << S.numDecoding(s);
	system("pause");
    return 0;
}

