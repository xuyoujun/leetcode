// 9.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include<unordered_set>
#include <map>
using namespace std;

class Solution {
public:
	int ladderLength(const string &start, const string &end, const unordered_set<string> &dict) {
	
		queue<string> current, next;
		unordered_set <string> visited;
		int level = 0;
		bool found = false;
		auto state_is_target = [&](const string &s) {return s == end; };
		auto state_extend = [&](const string &s) {
			vector<string> result;
			for (size_t i = 0; i < s.size(); i++) {
				string new_word(s);
				for (char c = 'a'; c <= 'z'; c++) {
					if (c == new_word[i])continue;
					swap(c, new_word[i]);
					if ((dict.count(new_word) > 0 || new_word == end) && !visited.count(new_word)) {
						result.push_back(new_word);
						visited.insert(new_word);
					}
					swap(c, new_word[i]);
				}
			}
			return result;
		};

		current.push(start);
		while (!current.empty() && !found) {
			++level;
			while (!current.empty() && !found) {
				const string str = current.front();
				current.pop();
				const auto & new_states = state_extend(str);
				for (const auto & state : new_states) {
					next.push(state);
					if (state_is_target(state)) {
						found = true;
						break;
					}
				}
			}
			swap(next, current);
		}
		if (found) return level + 1;
		else return 0;
	}



	int myladderLength(const string &start, const string &end, unordered_set <string> dict) {
		queue <string> current, next;
		bool  found = false;
		current.push(start);
		int level = 0;
		while (!current.empty() && !found) {
			level++;
			while (!current.empty() && !found) {
				string word = current.front();
				current.pop();
				vector <string> next_level = get_Next_Level(word,end,dict);
				for (auto i : next_level) {
					next.push(i);
					if (i == end) {
						found = true;
						break;
					}
				}
			}
			swap(current, next);
		}
		return level + 1;
	}


private:
	vector <string> get_Next_Level(string & word,const string &end ,unordered_set <string> &dict) {
		vector <string> result;
		for (int i = 0; i < word.size(); i++) {
			for (char c = 'a'; c <= 'z'; c++) {
				if (c == word[i])continue;
				swap(c, word[i]);
				if ((dict.count(word) > 0 || word == end)&& visted.find(word) == visted.end()){
					result.push_back(word);
					visted.insert(make_pair(word, true));
				}
				swap(c, word[i]);
			}
		}
		return result;
	}
	map <string, bool> visted;
};



int main()
{
	unordered_set <string> dict;
	dict.insert("hot"); //hot","dot","dog","lot","log"
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	class Solution S;
	cout << S.myladderLength("hit", "cog",dict);
	system("pause");
    return 0;
}

