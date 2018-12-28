#pragma once
#include "Problem.h"
class Boggle :
	public Problem
{
public:
	Boggle();
	~Boggle();

	// Problem을(를) 통해 상속됨
	virtual void Input() override;
	virtual void Solve() override;
	virtual void Result() override;
	virtual void TestInput() override;
private:
	vector<string> _input;
	bool _result;
};

