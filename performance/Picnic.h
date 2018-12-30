#pragma once
#include "Problem.h"
class Picnic :
	public Problem
{
public:
	Picnic();
	~Picnic();

	// Problem��(��) ���� ��ӵ�
	virtual void Input() override;
	virtual void Solve() override;
	virtual void Result() override;
	virtual void TestInput() override;

private:
	vector<pair<int, int>> _condition;
	vector<vector<int>> _input;
	vector<int> _result;
};

