#pragma once
#include "Problem.h"
class WildCard :
	public Problem
{
public:
	WildCard();
	~WildCard();

	// Problem��(��) ���� ��ӵ�
	virtual void Input() override;
	virtual void Solve() override;
	virtual void Result() override;
	virtual void TestInput() override;
};

