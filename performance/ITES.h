#pragma once
#include "Problem.h"
#include <vector>

class RNG {
public:
	RNG() : _seed(1983) {}
	unsigned next() {
		unsigned ret = _seed;
		_seed = ((_seed * 214013u) + 2531011u);
		return ret % 10000 + 1;
	}
private:
	unsigned _seed;	
};
class ITES :
	public Problem
{
public:
	ITES();
	~ITES();

	virtual void Input();
	virtual void Solve();
	virtual void Result();

	virtual void TestInput();

private:
	vector<pair<int, int>> _input;
	vector<int> _result;
};

