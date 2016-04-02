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
    ɨ������
	��һ����������飬�������ַ�����Ӧ����ƥ����ַ���Ӧ������Ԫ��Ϊ1��δƥ���Ϊ0
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

//ʹ��ջ
//��last ��סδƥ��� "��"��λ�ã���ջ�б������δƥ���"��"��λ�á�
//�����ǰȡ������"("����ջ��λ�ã������ջ�е�"("ƥ��
//�����")", <1>,���ջ���ǿյģ�����last��סδ��λ�ã���Ϊ��������δƥ���
//<2>���ջ�в��գ�˵��ջ�б���"(",�򵯳�ջ��
//<2.1>�����ʱջΪ�գ����ʱƥ��ĳ���Ϊi - last  max_len = max(max_len,i -last)
//<2.2>���ջ���գ����ʱƥ�����󳤶�Ϊi - stack[top]  max_len = max(max_len , i - stack[top])

/*������ջ�洢����Ԫ�ص�λ�ã�������Ԫ�ر�����Ϊͨ��λ�ÿ϶������ҵ�Ԫ�أ���ʹ��λ�õ�һ�����ô�����
*���Լ���һЩ�ַ����ĳ���
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
		else {                 //��
			if (-1 == top) {
				last = i;      // �洢δƥ��ģ�λ��
			}
			else {
				top--;   //��ջ(
				if (-1 == top) {  //ջΪ�գ���ƥ��ķ�Χ last ~i, ������last
					max = max < i - last ? i - last : max;
				}
				else {            //ջ���գ���ƥ��ķ�Χ stack[top]  ~ i ��������stack[top]
					max = max < i- stack[top] ? i - stack[top] : max;
				}
			}
		}
	}
	return max;
	delete stack;
	return 0;
}