#include "pch.h"
#include "Recursive.h"
#include <functional>
#include "../00.KKICommon/Log.h"
#include "../00.KKICommon/Elapse.h"

Recursive::Recursive()
	:Problem(), _h(0), _w(0), _input(), _result()
{
}


Recursive::~Recursive()
{
}

void Recursive::Input()
{
}

int Recursive::Sum(int n) {
	if (n == 1) return 1;
	return n + Sum(n - 1);
}

void Recursive::Solve()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
	//recursive test
	// 1. sum
	long sum = 0;

	function<void (int)> sumFunc = [&](int n)->int {
		
		if (n < 1) return 0;
		sum += n;
		sumFunc(n - 1);

		//return sum;
		
		/*if (n == 1) return 1;
		return n + sumFunc(n - 1);*/
	};

	function<int (int)> sumFunc2 = [&sumFunc2](int n)->int {
		if (n < 1) return 0;
		return n + sumFunc2(n - 1);
	};

	sumFunc(100);
	Logger->Write(Debug, "sumFunc : %ld", sum);

	sum = sumFunc2(100);
	Logger->Write(Debug, "sumFunc2 : %ld", sum);

	sum = Sum(100);
	Logger->Write(Debug, "Sum : %ld", sum);


	// game ÆÇ
}

void Recursive::Result()
{
}

void Recursive::TestInput()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
	_h = 3;
	_w = 7;

	_input.push_back("#.....#");
	_input.push_back("#.....#");
	_input.push_back("##...##");
}
