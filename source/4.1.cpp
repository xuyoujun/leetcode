// 4.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
bool is_valid(char *, int len);
int main()
{
	char stack[100];
	char *str = "()[]";
	printf("%d\n",is_valid(str ,strlen(str)));
	while (1);
	return 0;
}


bool is_valid(char *str, int len) {
	char *stk = (char *)malloc(len + 1);
	int top = -1;
	int i = 0;
	for (i = 0; i < len; i++) {
		if ('(' == str[i] || '[' == str[i] || '{' == str[i]) {       //ги[{
			stk[++top] = str[i];
		}
		else {                                                       //)]}
		
			if (-1 == top && (')' == str[i] || ']' == str[i] || '}' == str[i]))
				return  false;
			else {
				if ((stk[top] == '(' && str[i] == ')') || (stk[top] == '[' && str[i] == ']') || (stk[top] == '{' && str[i] == '}'))
					top--;
			}
		}
	}
	free(stk);
	return -1 == top;
}
