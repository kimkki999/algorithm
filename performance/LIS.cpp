#include "pch.h"
#include "LIS.h"


LIS::LIS()
	: Problem()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}


LIS::~LIS()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void LIS::Input()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void LIS::Solve()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);

	int cache[100];
	memset(cache, -1, sizeof(cache));

	function<int(int)> lis = [&](int start)->int {
		if (start == _input.size()) return 0;
		
		int &ret = cache[start];
		if (ret != -1) {
			return ret;
		}

		ret = 1;
		for (int i = start + 1; i < _input.size(); i++) {
			if (_input[start] < _input[i]) {
				ret = max(ret, lis(i) + 1);
			}
		}
		return ret;
	};
}

void LIS::Result()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void LIS::TestInput()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}
