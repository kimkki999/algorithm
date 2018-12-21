#pragma once
#include "Problem.h"

const int ALPHABET = 26;
class WordChain :
	public Problem
{
public:
	WordChain();
	~WordChain();

	virtual void Input();
	virtual void Solve();
	virtual void Result();

	virtual void TestInput();

	void MakeGraph(vector<vector<int>>& adj, const vector<string>& vec);

private:
	vector<vector<string>> _input;
	vector<vector<int>> _result;	
};

