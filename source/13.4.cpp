// 13.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxprofit(vector <int> &price) {
		const int n = price.size();
		vector <int> f(n, 0);
		vector <int> g(n, 0);
		int min_price = price[0];
		
		for (int i = 1; i < n; i++) {
			min_price = min(min_price, price[i]);
			f[i] = max(f[i - 1], price[i] - min_price);
		}
		int max_price = price[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			max_price = max(max_price, price[i]);
			g[i] = max(g[i + 1 ], max_price - price[i]);
		}
		int max_profit = INT_MIN;
		for (int i = 0; i < n; i++) {
			max_profit = max_profit >= f[i] + g[i] ? max_profit : f[i] + g[i];
		}
		return max_profit;
	}
	int min(int a, int b) {
		return a > b ? b : a;
	}
	int max(int a, int b) {
		return a > b ? a : b;
	}

};

int main()
{
	vector <int> price({1,2,3,4,5,1,2,4,56,7,8});
	Solution S;
	cout << S.maxprofit(price);
	system("pause");
    return 0;
}

