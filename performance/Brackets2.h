#pragma once
#include <vector>
#include "Problem.h"

class Brackets2 :
	public Problem
{
public:
	Brackets2();
	~Brackets2();

	virtual void Input();
	virtual void Solve();
	virtual void Result();

	virtual void TestInput();

private:
	vector<string> _input;
	vector<string> _result;
};

