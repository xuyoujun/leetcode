// 123.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>
#include <string>
#include <iostream>
using namespace std;
/*#define n 100
int main()
{
	double a[n], d, x, y, c;
	int i;
	a[0] =- 10;
	a[1]= 10;
	a[2]= 0;
	for (i = 0; i < n; i++) {
		d = 2 * a[i + 2] * a[i + 2] * a[i + 2] - 4 * a[i + 2] * a[i + 2] + 3 * a[i + 2] - 6;
		x = 2 * a[i + 1] * a[i + 1] * a[i + 1] - 4 * a[i + 1] * a[i + 1] + 3 * a[i + 1] - 6;
		y = 2 * a[i] * a[i] * a[i] - 4 * a[i] * a[i] + 3 * a[i] - 6;
		if (d*x < 0){
			a[i + 3] = (a[i + 2] + a[i + 1])*0.5;
			c = a[i + 2] - a[i + 1];
		}
		else {
			a[i + 3] = (a[i + 2] + a[i])*0.5;
			c = a[i + 2] - a[i];
		}

		//c= 2 * a[i + 3] * a[i + 3] * a[i + 3] - 4 * a[i + 3] * a[i + 3] + 3 * a[i + 3] - 6;
		if (c < 0.001 && c > - 0.001) break;
	}
	printf("%1f", a[i + 3]);
	system("pause");
}
*/


/*main()
{
	int a[10];
	int max, i, j, k, b, c;
	c = 0;
	printf("please input 1o numbers:\n");
	for (i = 0; i<10; i++)
		scanf("%d", &a[i]);
	for (i = 0; i<9; i++)
	{
		for (j = 0; j<9 - i; j++)
		{
			max = a[0];
			if (a[j + 1]>max)
				max = a[j + 1];
		}
		//printf("j+ 1 =%d\n", j + 1);  这里j的 值 为 9 - i
		k = j + 1;   //k = 10 - i
		if (k == 9 - i)   //这里的条件不会成立
			continue;
		else        //执行else里的语句
		{
			// i的第一次循环,i = 0 ==> a[j + 1] = a[9 - i + 1] = a[10] ==>数组越界; a[j + 1] = b,这里对越界的数组赋值 是导致程序崩溃的原因
			b = a[9 - i]; a[9 - i] = a[j + 1]; a[j + 1] = b; c += 1;
		}
	}
	printf("The result of sort:\n");
	for (i = 0; i<10; i++)
		printf("%d\n", a[i]);
	printf("c=%d\n", c); 
}*/

void permute(string prefix, string str) {
	int i;
	if (str.length() == 0) {
		cout << prefix;
		return;
	}
	for (i = 0; i < str.length(); i++) {
		permute(prefix + str[i], str.substr(0, i) + str.substr(i + 1, str.length()));
	
	}

}

int mian()
{
	string l;
	string h = "Hello";
	permute(l, h);
	system("pause");
	return 0;
}



