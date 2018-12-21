#include "stdafx.h"
#include "StringUtil.h"
#include <algorithm>

StringUtil::StringUtil()
{
}


StringUtil::~StringUtil()
{
}

vector<int> StringUtil::getSuffixArrayNaive(const string& s)
{
	vector<int> perm;
	for (int i = 0; i < s.size(); ++i) perm.push_back(i);
	sort(perm.begin(), perm.end(), SuffixComparator(s));
	return perm;
}

