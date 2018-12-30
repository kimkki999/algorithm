#pragma once
#include "Problem.h"
class BoardCover :
	public Problem
{
public:
	BoardCover();
	~BoardCover();

	// Problem��(��) ���� ��ӵ�
	virtual void Input() override;
	virtual void Solve() override;
	virtual void Result() override;
	virtual void TestInput() override;

private:
	vector<string> _input;
	int _result;
};

