#pragma once
#include "Problem.h"

class Dictionary :
	public Problem
{
public:
	Dictionary();
	~Dictionary();

	virtual void Input();
	void dfs(int here);
	vector<int> topologicalSort();
	virtual void Solve();
	virtual void Result();

	virtual void TestInput();

	void MakeGraph(const vector<string>& vec);

private:
	vector<vector<string>> _input;
	vector<vector<int>> _result;
	vector<vector<int>> _adj;
	vector<int> _seen, _order;
};

