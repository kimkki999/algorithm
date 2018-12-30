#include "pch.h"
#include "Picnic.h"
#include "../00.KKICommon/Log.h"

Picnic::Picnic()
	: Problem(), _input(), _result()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}


Picnic::~Picnic()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void Picnic::Input()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void Picnic::Solve()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);

	for (int index = 0; index < _condition.size(); index++) {
		int n = _condition[index].first;
		int p = _condition[index].second;
		auto val = _input[index];

		// make frient set;
		vector<vector<int>> f(n, vector<int>(n, 0));
		for (int i = 0; i < p; i++) {
			f[val[i * 2]][val[i * 2 + 1]] = 1;
		}
		vector<bool> meet(n, false);

		function<bool()> allMeet = [&]() {
			bool ret = true;
			for (int i = 0; i < n; i++) {
				if (!meet[i]) {
					ret = false;
					break;
				}
			}
			return ret;
		};

		function<int()> find = [&]()->int {
			if (allMeet()) return 1;

			int ret = 0;
			for (int i = 0; i < n; i++) {
				for (int k = 0; k < n; k++) {
					if (!meet[i] && !meet[k] && f[i][k]) {
						meet[i] = meet[k] = true;
						ret += find();
						meet[i] = meet[k] = false;
					}
				}
			}			
			return ret;
		};	

		vector<bool> meet2(n, false);		
		function<int()> find2 = [&]()->int {
			int first = -1;
			for (int i = 0; i < n; i++) {
				if (!meet2[i]) {
					first = i;
				}
			}

			if (first == -1) return 1;

			int ret = 0;
			for (int i = first + 1; i < n; i++) {
				if (!meet2[i] && f[first][i]) {
					meet2[i] = meet[first] = true;
					ret += find2();
					meet2[i] = meet[first] = false;
				}
			}
			return ret;
		};
	}
}

void Picnic::Result()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void Picnic::TestInput()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
	_condition.push_back(make_pair(2, 1));
	_input.push_back({ 0, 1 });
	_condition.push_back(make_pair(4, 6));
	_input.push_back({ 0,1,1,2,2,3,3,0,0,2,1,3 });
	_condition.push_back(make_pair(6, 10));
	_input.push_back({ 0,1,0,2,1,2,1,3,1,4,2,3,2,4,3,4,3,5,4,5 });
}
