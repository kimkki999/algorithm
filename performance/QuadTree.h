#pragma once
#include "Problem.h"
class QuadTree :
	public Problem
{
public:
	QuadTree();
	~QuadTree();

	// Problem��(��) ���� ��ӵ�
	virtual void Input() override;
	virtual void Solve() override;
	virtual void Result() override;
	virtual void TestInput() override;

private:
	vector<string> _input;
	vector<string> _result;
};

