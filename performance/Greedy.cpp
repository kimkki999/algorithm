#include "pch.h"
#include "Greedy.h"
#include "../00.KKICommon/Log.h"
#include "../00.KKICommon/Elapse.h"


Greedy::Greedy()
	: Problem(), _input(), _result()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}


Greedy::~Greedy()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void Greedy::Input()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void Greedy::Solve()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);

	for (const auto& val : _input) {
		priority_queue<int> q;
		for (int i = 0; i < val.size(); i++)
			q.push(-val[i]);

		int sum = 0;
		while (q.size() > 1) {
			int min1 = q.top(); q.pop();
			int min2 = q.top(); q.pop();

			int p = min1 + min2;
			q.push(p);
			sum += -p;
		}
		_result.push_back(sum);
	}
}

void Greedy::Result()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);

	for (const auto& val : _result) {
		Logger->Write(Debug, "%d", val);
	}
}

void Greedy::TestInput()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
	_input.push_back(vector<int>{2, 2, 4});
	_input.push_back(vector<int>{3, 1, 3, 4, 1});
	_input.push_back(vector<int>{1, 1, 1, 1, 1, 1, 1, 2});
}
