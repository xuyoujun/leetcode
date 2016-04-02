// 3.13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include<stdlib.h>
//#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
vector<string> Anagrams2(vector<string> strs);
vector<string> Anagrams(vector<string> strs);

//使用hash表 ，每个字母对应一个素数
typedef struct st_value {

	long long int hash_value;
	int index;
	bool operator <(const st_value &b) {
		if (hash_value != b.hash_value)return hash_value < b.hash_value;
		else
			return index < b.index;
	}
} st_value;
class solution {
public:
	vector<string> Anagrams(vector<string> strs) {
		int len;
		int i;
		long long int temp;
		int j = 0;
		vector<string> ret;

		st_value *hash_value = new st_value[strs.size()];
		len = strs.size();

		for (i = 0; i < len; i++) {
			hash_value[i].hash_value = get_hash_value(strs[i]);
			hash_value[i].index = i;
		}
		sort(hash_value, hash_value + len);
		for (i = 0; i < len; i++) {
			temp = hash_value[i].hash_value;
			j = i + 1;
			if (temp == hash_value[j].hash_value) {
				ret.push_back(strs[hash_value[i].index]);
				while (temp == hash_value[j].hash_value && j < len) {
					ret.push_back(strs[hash_value[j++].index]);
				}
				i = j - 1;
			}
		}
		delete hash_value;
		return ret;
	}
	long long int get_hash_value(string str) {
		int len;
		int i;
		int hash_value = 1;
		len = str.length();
		for (i = 0; i < len; i++) {
			hash_value *= prime[str[i] - 'a'];
		}
		return hash_value;
	}
private:
	int prime[26] = {
		2,3,5,7,11,13,17,19,23,29,
		31,37,41,43,47,53,59,61,67,
		71,73,79,83,89,97
	};
};
int main()
{
	vector<string> result;// Anagrams2(vector<string> strs);
	string str1[] = { "tea", "and", "ate", "eat", "den" };
	vector<string> input(str1, str1 + 5);
	solution A;
	result = A.Anagrams(input);
	vector<string>::iterator itr;
	for (itr = result.begin(); itr != result.end(); itr++) {
	
		cout << *itr << " ";
	}
	system("pause");
    return 0;
}







//hash 表  ：把每个字符串hash成一个数字
vector<string> Anagrams2(vector<string> strs) {
	map<string, int> str_int;  //string 作为索引
	vector<string> ret;
	string s;
	int len = strs.size();
	int i;
	for (i = 0; i < len; i++) {
		s = strs[i];
		sort(s.begin(), s.end());  //排序
		if (str_int.find(s) != str_int.end()) {
			if (str_int[s] == -1) {
				ret.push_back(strs[i]);
			}
			else {
				ret.push_back(strs[str_int[s]]);
				str_int[s] = -1;
				ret.push_back(strs[i]);
			}
		}
		else {
			str_int[s] = i;
		};
	}
	return ret;
}