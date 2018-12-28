#pragma once
#include "Problem.h"
class Greedy :
	public Problem
{
public:
	Greedy();
	~Greedy();

	// Problem��(��) ���� ��ӵ�
	virtual void Input() override;
	virtual void Solve() override;
	virtual void Result() override;
	virtual void TestInput() override;

private:
	vector<vector<int>> _input;
	vector<int> _result;
};

