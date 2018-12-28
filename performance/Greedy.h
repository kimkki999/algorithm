#pragma once
#include "Problem.h"
class Greedy :
	public Problem
{
public:
	Greedy();
	~Greedy();

	// Problem을(를) 통해 상속됨
	virtual void Input() override;
	virtual void Solve() override;
	virtual void Result() override;
	virtual void TestInput() override;

private:
	vector<vector<int>> _input;
	vector<int> _result;
};

