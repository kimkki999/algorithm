#include "pch.h"
#include "Boggle.h"
#include <functional>
#include "../00.KKICommon/Log.h"

Boggle::Boggle()
	: Problem(), _input(), _result()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}


Boggle::~Boggle()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void Boggle::Input()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void Boggle::Solve()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
	int max = _input.size();
	
	//string key = "ade";
	vector<int> moveX = { -1, 0, 1, -1, 1, -1, 0, 1 };
	vector<int> moveY = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int moveMax = moveX.size();

	function<bool(const string& key, string, int, int, int)> bo = [&](const string& key, string found, int y, int x, int index)->bool {		
		if (y < 0 || x < 0 || y > max - 1 || x > max - 1) return false;

		found += _input[y][x];

		if (found.size() >= key.size() && key != found) return false;

		//string sub = key.substr(0, found.size());
		if (key == found) return true;

		bool ret = false;
		for (int i = 0; i < moveMax; i++) {
			int newY = y + moveY[i];
			int newX = x + moveX[i];

			if (newX == x && newY == y) continue;

			if (bo(key, found, newY, newX, i)) {
				ret = true;
				break;
			}
		}
		return ret;
	};

	string found = "";
	_result = bo("ade", found, 0, 0, 0);
	_result = bo("aaa", found, 0, 0, 0);
}

void Boggle::Result()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
	Logger->Write(Debug, "result %s", _result ? "true" : "false");
}

void Boggle::TestInput()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
	_input.push_back("abc");
	_input.push_back("adf");
	_input.push_back("iie");
}
