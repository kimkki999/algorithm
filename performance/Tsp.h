#pragma once
#include "Problem.h"
class Tsp :
	public Problem
{
public:
	Tsp();
	~Tsp();

	// Problem��(��) ���� ��ӵ�
	virtual void Input() override;
	virtual void Solve() override;
	virtual void Result() override;
	virtual void TestInput() override;
};

