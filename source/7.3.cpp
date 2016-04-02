// 7.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public :
	bool search_2D_Matrix(vector <vector<int>> matrix , int target){
		int lower;
		int upper;
		int mid;
		int len;
		int value;
		if (matrix.empty()) return false;
		lower = 0;
		len = matrix[0].size();
		upper = len * matrix.size();
		while (lower < upper) {
			mid = lower + (upper - lower) / 2;
			value = matrix[mid / len][mid %len];
			if (value < target) lower = mid + 1;
			else if (value > target) upper = mid;
			else return true;
		}
		return false;
	}

};
int main()
{

    return 0;
}

