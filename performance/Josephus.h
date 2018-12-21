#pragma once

#include <vector>
#include "Problem.h"

class Josephus :
	public Problem
{
public:
	Josephus();
	~Josephus();

	virtual void Input();
	virtual void Solve();
	virtual void Result();

	virtual void TestInput();

private:
	vector<pair<int, int>> _input;
	vector<pair<int, int>> _result;	
};

// result

//[2018 - 12 - 14.15:21 : 21][Debug] : TestInput
//[2018 - 12 - 14.15:21 : 21][Info] : condition : 50 * (1000, 1000)
//[2018 - 12 - 14.15:21 : 21][Debug] : Solve
//[2018 - 12 - 14.15:21 : 21][Info] : solve elapse : 0.066000
//[2018 - 12 - 14.15:21 : 21][Debug] : Result
//[2018 - 12 - 14.15:21 : 21][Info] : solve & result elapse : 0.098000

