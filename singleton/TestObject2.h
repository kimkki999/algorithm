#pragma once
#include "Singleton.h"
class TestObject2 :	public Singleton<TestObject2>
{
public:
	TestObject2() {}
	virtual ~TestObject2() {}
};

