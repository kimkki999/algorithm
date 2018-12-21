// easy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>

using namespace std;


class SortedMap {
private:
	map<char, SortedMap*> dic;
public:

	void Add(char ch, SortedMap* pMap) {
		dic[ch] = pMap;
	}

	SortedMap* Find(char val) {
		SortedMap* sortedMap = nullptr;
		auto iter = dic.find(val);
		if (iter != dic.end())
			sortedMap = iter->second;

		return sortedMap;
	}

	//void AddAll(const int& max, string prefix, vector<string>& result) {
	void AddAll(const int& max, string prefix, unordered_set<string>& result) {
		if (result.size() >= max)
			return;

		for (auto iter : dic) {
			if (iter.first == 'E') {
				//if (result)
				//if not include result then add result
				//result.push_back(prefix);
				result.insert(prefix);
				continue;
			}
			iter.second->AddAll(max, prefix + iter.first, result);
		}
	}

	~SortedMap() {
		for (auto &iter : dic) {
			delete iter.second;
		}
		dic.clear();
	}
};


//scanf, printf
class Manager {
private:
	SortedMap sortedMap;
	SortedMap recommendedMap;
public:
	void Add(const string& str) {
		Add(0, str, &sortedMap);
	}
	void Add(int index, const string& str, SortedMap *pMap) {
		SortedMap *p = nullptr;

		if (index >= str.size()) {
			pMap->Add('E', p);
			return;
		}

		p = pMap->Find(str[index]);
		if (p == nullptr) {
			p = new SortedMap();
			pMap->Add(str[index], p);
		}
		Add(++index, str, p);
	}
	void AddRecommended(const string& str) {
		Add(0, str, &recommendedMap);
	}

	unordered_set<string> Find(const string& str, const int& max) {
		//vector<string> result;
		unordered_set<string> result;
		Find(0, str, max, &recommendedMap, result);
		Find(0, str, max, &sortedMap, result);
		return result;
	}

	//void Find(int index, const string& str, const int& max, SortedMap *pMap, vector<string>& result) {
	void Find(int index, const string& str, const int& max, SortedMap *pMap, unordered_set<string>& result) {
		if (index >= str.size() || result.size() >= max) {
			return;
		}

		SortedMap *p = pMap->Find(str[index]);
		if (p == nullptr) {
			return;
		}
		if (index == str.size() - 1) {
			p->AddAll(max, str, result);
		}
		else {
			Find(++index, str, max, p, result);
		}
	}

	~Manager() {

	}
};

int main() {
	int numKeyword, numQuery;
	numKeyword = numQuery = 0;
	cin >> numKeyword;

	// search list
	Manager manager;
	int index = 0;
	while (numKeyword--) {
		string keyword;
		cin >> keyword;

		manager.Add(keyword);
	}

	cin >> numQuery;
	while (numQuery--) {
		int type = 0;
		cin >> type;
		if (type == 1) {
			string input;
			int k = 0;
			cin >> input >> k;

			//vector<string> result = manager.Find(input, k);
			unordered_set<string> result = manager.Find(input, k);

			for (auto iter : result) {
				cout << "result : " << iter << endl;
				manager.AddRecommended(iter);
			}
		}
		else if (type == 2) {
			string input;
			cin >> input;
			manager.Add(input);
		}
		else {
			// exception
		}
	}
	return 0;
}

#include <ctime>
#include <random>

int getRandomNumber(int min, int max) {
	random_device rn;
	mt19937 rnd(rn());

	uniform_int_distribution<int> range(min, max);
	return range(rnd);
}

string makeKeyword() {
	int length = getRandomNumber(1, 100);
	string str(length, ' ');

	for (int i = 0; i < length; i++) {
		int val = getRandomNumber('a', 'z');
		str[i] = val;
	}

	return str;
}

vector<string> makeKeyword(int numKeyword) {
	vector<string> result;

	for (int count = 0; count < numKeyword; count++) {
		int length = getRandomNumber(1, 100);
		string str(length, ' ');

		for (int i = 0; i < length; i++) {
			int val = getRandomNumber('a', 'z');
			str[i] = val;
		}

		result.push_back(str);
	}

	return result;
}

vector<pair<int, pair<string, int>>> makeQuery(int numQuery) {
	vector<pair<int, pair<string, int>>> result;

	for (int i = 0; i < numQuery; i++) {
		int type = getRandomNumber(1, 2);
		string str = makeKeyword();
		int length = getRandomNumber(1, 10);

		result.push_back(make_pair(type, make_pair(str, length)));
	}

	return result;
}

int CalcElapseTime(const clock_t& start, const clock_t& end) {
	return ((double)(end - start));
}

void WriteLog(string msg, const clock_t& start) {
	int t = CalcElapseTime(start, clock());

	cout << t << " : " << msg << endl;
}
/*
int main() {
	int numKeyword, numQuery;
	numKeyword = numQuery = 0;

	clock_t start = clock();

	WriteLog("start", start);

	//numKeyword = getRandomNumber(1, 2 * pow(10, 4));
	//numQuery = getRandomNumber(1, 2 * pow(10, 4));
	numKeyword = 10;
	numQuery = 10;

	cout << "condition : keyword[" << numKeyword << "] query[" << numQuery << "]" << endl;

	// search list
	Manager manager;
	vector<string> keywords = makeKeyword(numKeyword);

	WriteLog("make query start", start);

	vector<pair<int, pair<string, int>>> querys = makeQuery(numQuery);

	WriteLog("start add", start);

	for (auto iter : keywords) {
		cout << "keyword : " << iter << endl;
		manager.Add(iter);
	}
	WriteLog("start query", start);

	for (auto query : querys) {
		int type = query.first;
		cout << "query : " << type << " ";
		if (type == 1) {
			string input;
			int k = 0;
			input = query.second.first;
			k = query.second.second;
			cout << input << " " << k << endl;
			vector<string> result = manager.Find(input, k);

			for (auto iter : result) {
				cout << iter << endl;
				manager.AddRecommended(iter);
			}
		}
		else if (type == 2) {
			string input = query.second.first;
			cout << input << endl;

			manager.Add(input);
		}
		else {
			// exception
		}
	}
	WriteLog("end query", start);
	return 0;
}
*/