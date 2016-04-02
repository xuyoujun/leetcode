// 8.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {

public:
	vector <vector <int>> permutaUniqe(vector <int> s) {
		unordered_map<int, int> count_map;
		n = s.size();
		sort(s.begin(), s.end());
		for_each(s.begin(), s.end(), [&count_map](int e) {
			if (count_map.find(e) != count_map.end()) {
				count_map[e]++;
			}
			else {
				count_map[e] = 1;
			}
		});
		//cout << "hh";
		vector <pair <int, int>> element;
		for_each(count_map.begin(), count_map.end(), [&element](pair<int,int> e) {
			element.push_back(e);
		});
		
		vector <vector <int>> result;
		vector <int> path;
		permutation(element.begin(), element.end(), path, result);
		return result;
		//void permutaUniqu(vector);
	}
private:
	size_t n;
	typedef vector<pair <int,int>>::iterator itor;
	void permutation(itor first, itor last, vector <int> &path,vector <vector <int>> &result) {
		if (path.size() == n) {
			result.push_back(path);
			return;
		}
		for (auto i = first; i != last; i++) {
			int count = 0;
			for (auto j = path.begin(); j != path.end(); j++) {
				if (i->first == *j)count++;
			}
			if (count < i->second) {
				path.push_back(i->first);
				//cout << i->first;
				permutation(first, last, path, result);
				path.pop_back();
			}
		}
	}

};

int main()
{
	vector <int> S;
	for (int i = 0; i < 2; i++) {
		S.push_back(i + 1);
	}
	S.push_back(2);
	vector < vector <int >> result;
	class Solution so;
	result = so.permutaUniqe(S);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j];
		cout << endl;
	}
	system("pause");
	return 0;
}
