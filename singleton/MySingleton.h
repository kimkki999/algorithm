#pragma once
#include "Singleton.h"

class MySingleton :	public Singleton<MySingleton>
{
public:
	MySingleton() {};
	virtual ~MySingleton() {};
};

