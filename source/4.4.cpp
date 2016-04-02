// 4.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


int Evaluate_Reverse_Polish_Notation(char **, int len);
int main()
{
	char *exp[] = { "2","1","+","3","*" };
	printf("%d\n", sizeof(exp)/sizeof(char *));
	//printf("%d\n", Evaluate_Reverse_Polish_Notation(exp, 5));
	while (1);
    return 0;
}


bool is_operator(char *ch) {
	return ('+' == *ch || '-' == *ch || '*' == *ch || '/' == *ch);
}
int comp(int a, int b, char opr) {
	if ('+' == opr)return a + b;
	else if ('-' == opr) return a - b;
	else if ('*' == opr) return a * b;
	else return a / b;
}
int Evaluate_Reverse_Polish_Notation(char **str, int len) {
	int top = -1;
	int *stk = new int[len];
	int i;
	int operand_a;
	int operand_b;
	int temp = 0;
	for (i = 0; i < len; i++) {
		if (is_operator(str[i])) {
			operand_b = stk[top--];
			operand_a = stk[top--];
			stk[++top] = comp(operand_a, operand_b, *str[i]);
		}
		else {
			while (isdigit(*str[i])) {
				temp = temp * 10 + (*str[i] - '0');
				str[i] ++;
			}
			//printf("%d\n", top);
			stk[++top] = temp;
			//i--;
			temp = 0;
		}
	}
	temp = stk[top];
	delete stk;
	return temp;
}
