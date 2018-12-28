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

	//bit test
	Elapse elp;

	unsigned long long max = 1000000000;//10¾ï
	elp.Start();
	for (unsigned long long i = 0; i < 1000000000; i++) {
		;
	}
	Logger->Write(Info, "solve elapse : %lf", elp.End());

	elp.Start();		
	for (unsigned long long i = 0; i < 1000000000; i++) {
		int n = 1 << 30;
	}

	Logger->Write(Info, "solve elapse : %lf", elp.End());

	elp.Start();
	for (unsigned long long i = 0; i < 1000000000; i++) {
		int n = 1 << 1;
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
