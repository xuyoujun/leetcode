// 7.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class solution {
public:
	vector <int> search_Range(int A[], int n, int target) {
		int low_border;
		int high_border;
		low_border = low_Border(A, n, target);
		high_border = high_Border(A, n, target);
		return A[low_border] != target ? vector<int>{-1, -1} : vector<int>{ low_border,high_border -1};
	}
private:
	int low_Border(int A[], int n,int target) {
		int low = 0;
		int high = n;
		int mid;
		while (low < high) {
			mid = low + (high - low) / 2 + 1;
			if (A[mid] < target) low = mid + 1;     //目标大于中间的A[low]才更新low的值，low最终指向的是第一个等于target的位置或者不存在
			else high = mid;
		}
		return low;
	}

	int high_Border(int A[], int n, int target) {
		int low = 0;
		int high = n;
		int mid;
		while (low < high) {
			mid = low + (high - low) / 2 ;
			if (A[mid] <= target)low = mid + 1;  //目标大于等于A[low] 就更新low ,最终low指向的是一个不等于 target的位置
			else high = mid;
		}
		return low;
	}

};
/*class solution{
public:
	vector<int> search_Range(int A[], int n, int target) {
		const int l = distance(A, lower_bound(A, A + n, target));
		const int u = distance(A, prev(upper_bound(A, A + n, target)));
		if (A[l] != target) // not found
			return vector<int> { -1, -1 };
		else
			return vector<int> { l, u };
	}
};*/


class solution2 {
public:
	vector<int> search_Range(int A[], int n, int target) {
		auto lower = lower_bound(A, A + n, target);
		auto uppper = upper_bound(A, A + n, target);
		if (lower == A + n || *lower != target)
			return vector<int> { -1, -1 };
		else
			return vector<int> {distance(A, lower), distance(A, prev(uppper))};  //distance 求距离就是直接相减
	}
	template<typename ForwardIterator, typename T>
	ForwardIterator lower_bound(ForwardIterator first,
		ForwardIterator last, T value) {
		while (first != last) {
			auto mid = next(first, distance(first, last) / 2);  //first + (last-first)/2;  next(first,n)  意义和 first + n 类似     next(first) 等价于 next(first,1)
			if (value > *mid) first = ++mid;
			else last = mid;
		}
		return first;
	}
	template<typename ForwardIterator, typename T>
	ForwardIterator upper_bound(ForwardIterator first,
		ForwardIterator last, T value) {
		while (first != last) {
			auto mid = next(first, distance(first, last) / 2);
			cout << *mid << " ";
			if (value >= *mid) first = ++mid; // 与 lower_bound 仅此不同
			else last = mid;
		}
		return first;
	}
};
int main()
{
	vector<int> result;
	class solution S;
	int A[] = { 5, 7, 7, 8, 8, 10 };
	result = S.search_Range(A, 6, 8);
	for (auto i : result)
		cout << i;


	vector <int > test;
	test.push_back(1);
	test.push_back(2);
	vector <int>::iterator itor = test.begin();
	itor++;
	cout << "distance(A, A+ 2) " <<distance(A, A+ 2);
	cout <<* next(A, 0);
 	system("pause");
    return 0;
}

