// 3.5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int longest_Palindromic_Substring(char * str,int *);
int longest_Palindromic_Substring2(char * str, int *); 
int main()
{
	int begin;
	int len;
	char str[] = "ewwwwwwwjasgf";
	len = longest_Palindromic_Substring2(str, &begin);
	printf("start = %d, len = %d\n", begin, len);
	system("pause");
	return 0;
}


//����1����̬�滮
int longest_Palindromic_Substring(char * str, int * begin) {
	const int n = strlen(str);
	int s[100][100];
	int start = 0;
	int max_len = 1;
	int i, j;
	for (i = 0; i < n; i++) {
		s[i][i] = 1;
		for (j = 0; j < i; j++) {//[j,i]
			s[j][i] = (str[j] == str[i]) && (i - j < 2 || s[j + 1][i - 1]);
			if (s[j][i] && max_len < (i - j + 1)) {
				max_len = (i - j + 1);
				start = j;
			}
		}
	}
	*begin = start;
	return max_len;
}


//����2��Manacher�� s Algorithm  
char * prePrecess(char *,int);
int   find_Longest(char *,int,int *);
int longest_Palindromic_Substring2(char *str, int * begin) {
	char *T;
	int ret;
	int len = strlen(str);
	T = prePrecess(str,len);   //�����ַ� ^*$
	ret = find_Longest(T,len,begin);
	free(T);
	return ret;
}

char * prePrecess(char *str,int len) {
	char *T = (char *)malloc(2 * len + 4);
	int i;
	T[0] = '^';
	for (i = 0; i < len; i++) {
		T[i * 2 + 1] = '*';
		T[i * 2 + 2] = str[i];
	}
	T[2 * len + 1] = '*';
	T[2 * len + 2] = '$';
	return T;
}

int min(int a, int b) {
	return a < b ? a : b;
}

int  find_Longest(char * T, int len,int *pos) {
	int C = 0;  //���ĵ�
	int i = 0;
	int R = 0;  //�ұ߽�
	int n = 2 * len + 3;
	int P[100];
	int i_mirror;   //i����C�ԳƵĵ�
	for (i = 1; i < n - 1; i++) {
		i_mirror = 2 * C - i;       //i ���� C�ԳƵĵ�
  		P[i] = (i < R) ? min(R - i, P[i_mirror]) : 0;   //i���ұ߽����ڣ��Ϳ������öԳ���
		while (T[i - 1 - P[i]] == T[i + 1 + P[i]]) P[i]++;
		if (R < i + P[i]) {  //�ұ߽����
			R = i + P[i];
			C = i;
		}
	}
	int max_len = 0, center_id = 0;
	for (i = 1; i < n - 1; i ++) {
		if (max_len < P[i]) {
			max_len = P[i];
			center_id = i;
		}
	}
	*pos = (center_id - max_len - 1) / 2;   //������ԭ���е�λ��
	return max_len;                         //���س���
}
