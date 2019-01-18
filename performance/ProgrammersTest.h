#pragma once
#include "Problem.h"
class ProgrammersTest :
	public Problem
{
public:
	ProgrammersTest();
	~ProgrammersTest();

	// Problem을(를) 통해 상속됨
	virtual void Input() override;
	void MaxPath();
	void ShortestPath(int m, int n, const vector<vector<int>>& puddles, int& shortest, int& cnt);
	int MaxCardSum(vector<int> left, vector<int> right);
	int MaxSteal(vector<int> money1);
	int MaxGive(int limit, vector<vector<int>> travel);
	int MaxOrderCount(int K, vector<int> box);
	int NetworkFlow(int vertex, vector<vector<int>> c);
	virtual void Solve() override;
	virtual void Result() override;
	virtual void TestInput() override;
};

