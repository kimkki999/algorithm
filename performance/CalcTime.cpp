#include "pch.h"
#include "CalcTime.h"
#include "../00.KKICommon/Log.h"
#include "../00.KKICommon/Elapse.h"

CalcTime::CalcTime()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

CalcTime::~CalcTime()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void CalcTime::Input()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

#include <Windows.h>
void CalcTime::Solve()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);

	Elapse elp;
	elp.Start();
	
	for (long long i = 0; i < 1000000000; i++) {
		for (long long j = 0; j < 1; j++) {
			long long k = i;
		}
	}

	Logger->Write(Info, "solve elapse : %lf", elp.End());
}

void CalcTime::Result()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void CalcTime::TestInput()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}
