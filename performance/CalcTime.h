#pragma once
#include "Problem.h"
class CalcTime :
	public Problem
{
public:
	CalcTime();
	~CalcTime();



	// Problem��(��) ���� ��ӵ�
	virtual void Input() override;

	virtual void Solve() override;

	virtual void Result() override;

	virtual void TestInput() override;

};

