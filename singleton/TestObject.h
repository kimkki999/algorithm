#pragma once
#include "Singleton.h"
class TestObject : public Singleton<TestObject>
{
public:
	TestObject();
	virtual ~TestObject();
private:
	int _value;
};

