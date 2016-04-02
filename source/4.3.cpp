// 4.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

int Largest_Rectangle_in_Histogram(int hei[], int len);
int main()
{
	int hei[] = { 2, 1, 5, 6, 2, 3 };
	printf("%d\n",Largest_Rectangle_in_Histogram(hei, 6));
	while (1);
	return 0;
}
//使用一个递增的栈，
int Largest_Rectangle_in_Histogram(int hei[], int len) {
	int top = -1;
	int *stk = new int[len];
	int *wid = new int[len];
	int area;
	int max_area = 0;
	memset(wid, 0, len*sizeof(int));
	int i;
	for (i = 0; i < len; i++) {
		if (-1 == top)stk[++top] = i;
		else {
			if (hei[stk[top]] <= hei[i] ) stk[++top] = i;
			else {
				while (-1 != top && hei[stk[top]] > hei[i]) {
					wid[stk[top]] += (i - stk[top]);
					top--;
				}
				wid[i] = i - top - 1;   //计算i前面的宽度，i本身还没计算，等到i 出栈时再计算自身的宽度
				stk[++top] = i;
			}
		} 
	}
	while (-1 != top) {
		wid[stk[top]] += (i - stk[top]);
		top--;
	}
	for (i = 0; i < len; i++) {
		area = hei[i] * wid[i];
		max_area = max_area < area ? area : max_area;
	}
	return max_area;
}