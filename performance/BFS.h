#pragma once
#include "Problem.h"
class BFS :
	public Problem
{
public:
	BFS();
	~BFS();

	virtual void Input();
	virtual void Solve();
	virtual void Result();
	virtual void TestInput();

private:
	vector<vector<string>> _input;
	vector<vector<int>> _result;
};

