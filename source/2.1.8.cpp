// 2.1.8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution {
public:
	vector<vector<int>> ThreeSum(vector<int> &num,int target) {
		vector<vector<int>> result;
		vector<int>::iterator i; //= num.begin();
		vector<int>::iterator j; //= num.end() - 1;
		vector<int>::iterator k;
		int temp;
		if (num.size() < 3) return result;
		sort(num.begin(), num.end());
		i = num.begin();
		k = num.end() - 1;
		while (i < k) {
			temp = *i + *k;
			if (temp > target) {
				j = i + 1;
				if (temp  + *j > target) {
					k--;
				}
				else {
					while (temp + *j < target && j < k)j++;
					if (temp + *j == target && j < k) {
						result.push_back({ *i,*j,*k, });
						i++;
						k--;
					};
				}
			}
			else if (temp < target) {
				j = k - 1;
				if (temp + *j < target) {
					i++;
				}
				else {
					while (temp + *j > target && i > j) j--;
					if (temp + *j == target && i > j) {
						result.push_back({ *i, *j, *k });
						i++;
						k--;
					}
				}
			}
			else {//temp == target
				j = i + 1;
				while (*j != target && j < k) j++;
				if (target == *j && j < k) {
					result.push_back({ *i, *j, *k });
					i++;
					k--;
				}
			}
		}
		return result;
	}
};

int main()
{
	solution S;
	vector<int> num = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> result;
	result = S.ThreeSum(num,0);

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {

			cout << result[i][j]<<' ';
		}
		cout << endl;
	}
	system("pause");
    return 0;
}

