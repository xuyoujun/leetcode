// 2.1.11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//c language
/*#include<stdio.h>
#include<stdlib.h>

int remove_element(int A[], int len, int target);
int main()
{

	int A[8] = { 0,0,0,1,1,3,4,5 };
	int size;
	size = remove_element(A, 8, 0);
	for (int i = 0; i < size; i++) {
		printf("%d  ", A[i]);
	
	}
	system("pause");
    return 0;
}


int remove_element(int A[],int len, int target)
{
	int i ,index;

	index = 0;
	for (i = 0; i < len; i++) {
		if (A[i] != target)
			A[index++] = A[i];
	}
	return index;
}*/



//C++
#include<iostream>
#include<algorithm>

using namespace std;


//int remove_element(int A[], int len, int target);
class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		return distance(A, remove(A, A + n, elem));
	}
};
int main()
{

	int A[8] = { 0,0,0,1,1,3,4,5 };
	int size;
	int in;
	cin >> in;
	cout << in << endl;
	Solution S;
	size = S.removeElement(A, 8, 0);
	for (int i = 0; i < size; i++) {
		printf("%d  ", A[i]);

	}
	system("pause");
	return 0;
}