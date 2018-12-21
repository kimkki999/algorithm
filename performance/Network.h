#pragma once
#include "Problem.h"
class Network :
	public Problem
{
public:
	Network();
	~Network();

	// Problem을(를) 통해 상속됨
	virtual void Input() override;
	virtual void Solve() override;
	virtual void Result() override;
	virtual void TestInput() override;
};

