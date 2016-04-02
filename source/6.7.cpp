// 6.7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

class solution {
public:
	void color_sort(int A[], int n) {   //两边往中间走
		int i = 0;
		int l = 0, h = n - 1;
		for (i = 0; i < n && i <= h; i++) {
			while (A[i] != 1){  
				if (A[i] == 2)  //2
					swap(A[h], A[i]), h--;
				else {  ///0
					if (l == i) {
						l++;
						break;
					}
					swap(A[i], A[l]), l++;
				}
			}
		}
	}
	void count_sort(int A[], int  n) {  //计数排序
		int k = 3;
		int B[3];
		int C[11];
		int i;
		memset(B, 0, sizeof(B));
		memset(C, 0, sizeof(C));
		for (i = 0; i < n; i++) {
			B[A[i]] ++;
		}
		for (i = 1; i < k; i++) {
			B[i] += B[i - 1];
		}
		for (i = n - 1; i > -1; i--) {
			C[B[A[i]] - 1] = A[i];
			B[A[i]] --;
		}
		for (i = 0; i < n; i++) {
			A[i] = C[i];
		}
	}

	void quick_sort(int A[], int n) { //利用快排，第一次从0分割，第二次从1分割
		partition(A, partition(A, 0,n,0),n,1);
	}
private:
	int partition(int A[], int start,int end, int x) {
		int i = start - 1;
		int j;
		for (j = start; j < end;j++) {
			if (A[j] <= x) {
				swap(A[++i], A[j]);
			}
		}
		return i + 1;
	}
};
int main()
{
	int A[] = { 0,1,2,1,2,0,1,2,1,0,1 };
	class solution S;
	S.quick_sort(A, sizeof(A)/sizeof(int));
	for (int i = 0; i < sizeof(A)/sizeof(int); i++) {
		printf("%d  ", A[i]);
	}
	system("pause");
    return 0;
}

