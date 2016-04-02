// 9.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector <string>> vallterString(const string & start, const string & end, unordered_set <string> dict) {
		map <string, vector <string>>father;
		vector <string> current, next;
		bool found = false;
		unordered_set <string> visited;
		auto is_target = [&end](const string & val) {return val == end; };  //�ж��Ƿ��ҵ�Ŀ��
		auto extend_state = [&]( string & word) {  //��dict ��Ѱ����word���һ����ĸ�ĵ��� 
			vector <string> result;
			for (auto i = 0; i < word.size(); i++) {
				for (auto c = 'a'; c <= 'z'; c++) {
					if (word[i] == c) continue;
					swap(c, word[i]);
					if ((visited.count(word) == 0 )&& (word == end || dict.count(word) >0)) {
						result.push_back(word);
					}
					swap(c, word[i]);
				}
			}
			return result;
		};
		current.push_back(start);
		while (!current.empty() && !found) {
			for (auto i : current) {
				visited.insert(i);
			}
			//string new_word = current.back();
			for (auto j : current) {
				//current.pop_back();  //j �ڱ���current������ɾ��curreng�е�Ԫ�أ�����j��ֵ���������
				for (auto i : extend_state(j)) {
					father[i].push_back(j);
					next.push_back(i);
					if (i == end)found = true;
				}
			}
			current.clear();
			swap(current, next);
		}
		//ǰ��Ĳ����ǹ���һ����������Ĳ������������Ѱ�ҷ���Ҫ���·��
		vector <vector<string>> result;
		vector <string> path;
		
		if (found == true) {
			gen_result(start, end, path,father, result);
		}
		return result;
	}
private:
	void gen_result(const string & start, const string & end, vector <string> &path, map <string,vector<string>> &father,vector<vector<string>> &result) {
		//��������ֻ������Ҷ�ڵ������ڵ����
			path.push_back(end);
		if ( start == end) {
			result.push_back(path);
			reverse(result.back().begin(), result.back().end());
			return;
		}
		for (auto i : father[end]) {
			gen_result(start, i , path, father,result);
			path.pop_back();
		}
	}
};

int main()
{
	unordered_set <string> dict;
	dict.insert("hot"); //hot","dot","dog","lot","log"
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	vector < vector <string >> result;
	class Solution so;
	result = so.vallterString("hit","cog",dict);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
	system("pause");
    return 0;
}

