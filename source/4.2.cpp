// 4.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
int Longest_Valid_Parentheses2(char * str, int len);
int Longest_Valid_Parentheses(char * str, int len);
int main()
{
	printf("%d\n",Longest_Valid_Parentheses("))()())))(((())))(((((", 22));
	system("pause");
    return 0;
}

/*
    扫描两遍
	用一个额外的数组，数组与字符串对应，已匹配的字符对应的数组元素为1，未匹配的为0
*/
int Longest_Valid_Parentheses(char * str, int len) {
	int *str_int = new int[len];
	int *stk = new int[len];
	int top = -1;
	int i;
	memset(str_int, 0, len * sizeof(int));
	for (i = 0; i < len; i++) {
		if (str[i] == '(') {
			stk[++top] = i;
		}
		else {
			if (top == -1 || str[stk[top]] == ')') {
				stk[++top] = i;
			}
			else {
				str_int[stk[top--]] = 1;
				str_int[i] = 1;
			}
		}
	}
	int max_len = 0;
	int curr_len = 0;
	for (i = 0; i < len; i++) {
		if (str_int[i] == 0) {
			max_len = max_len < curr_len ? curr_len : max_len;
			curr_len = 0;
		}
		else {
			curr_len++;
		}
	}
	delete stk;
	return max_len < curr_len ? curr_len : max_len;
}

//使用栈
//用last 记住未匹配的 "）"的位置，，栈中保存的是未匹配的"（"的位置。
//如果当前取到的是"("则入栈其位置，不会和栈中的"("匹配
//如果是")", <1>,如果栈中是空的，则用last记住未其位置，因为“）”是未匹配的
//<2>如果栈中不空，说明栈中必有"(",则弹出栈，
//<2.1>如果这时栈为空，则此时匹配的长度为i - last  max_len = max(max_len,i -last)
//<2.2>如果栈不空，则此时匹配的最大长度为i - stack[top]  max_len = max(max_len , i - stack[top])

/*经常用栈存储的是元素的位置，而不是元素本身，因为通过位置肯定可以找到元素，，使用位置的一个最大好处就是
*可以计算一些字符串的长度
*/

int Longest_Valid_Parentheses2(char * str, int len) {
	int *stack = new int[len];
	int top = -1;
	int i;
	int last = -1;
	int max = 0;
	for (i = 0; i < len; i++) {
		if ('(' == str[i]) {    //(
			stack[++top] = i;
		}
		else {                 //）
			if (-1 == top) {
				last = i;      // 存储未匹配的）位置
			}
			else {
				top--;   //出栈(
				if (-1 == top) {  //栈为空，已匹配的范围 last ~i, 不包含last
					max = max < i - last ? i - last : max;
				}
				else {            //栈不空，已匹配的范围 stack[top]  ~ i ，不包含stack[top]
					max = max < i- stack[top] ? i - stack[top] : max;
				}
			}
		}
	}
	return max;
	delete stack;
	return 0;
}