#include "pch.h"
#include "Dynamic.h"
#include "../00.KKICommon/Log.h"
#include "../00.KKICommon/Elapse.h"

Dynamic::Dynamic()
	: Problem()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

Dynamic::~Dynamic()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void Dynamic::Input()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void Dynamic::Solve()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void Dynamic::Result()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void Dynamic::TestInput()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}
