#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class Problem
{
public:
	Problem() {};
	virtual ~Problem() {};

	virtual void Input() = 0;
	virtual void Solve() = 0;
	virtual void Result() = 0;

	virtual void TestInput() = 0;
};
