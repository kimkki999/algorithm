#pragma once

#include <vector>
using namespace std;

class SuffixComparator {
public:
	SuffixComparator(const string& s) : _s(s) {}
	bool operator () (int i, int j) {
		return strcmp(_s.c_str() + i, _s.c_str() + j) < 0;
	}
private:
	const string& _s;
};

class StringUtil
{
public:
	StringUtil();
	~StringUtil();

	vector<int> getSuffixArrayNaive(const string& s);
};

