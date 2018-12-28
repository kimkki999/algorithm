#pragma once
#include "Problem.h"
class Recursive :
	public Problem
{
public:
	Recursive();
	~Recursive();

	// Problem��(��) ���� ��ӵ�
	virtual void Input() override;
	int Sum(int n);
	string Print(vector<int> input);
	virtual void Solve() override;
	int Partitioning(int list[], int left, int right);
	void QuickSort(int list[], int left, int right);
	virtual void Result() override;
	virtual void TestInput() override;

private:
	int _h, _w;
	vector<string> _input;
	vector<int> _result;
};
