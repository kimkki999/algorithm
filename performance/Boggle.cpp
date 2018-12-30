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
	string key = "";

	function<bool(string, int, int, set<pair<int,int>>&, int)> hasWord1 = [&](string found, int y, int x, set<pair<int,int>>& pos, int index)->bool {		
		if (y < 0 || x < 0 || y > max - 1 || x > max - 1) return false;

		auto iter = pos.insert(make_pair(y, x));
		if (iter.second == false) {
			return false;
		}

		found += _input[y][x];

		if (found.size() > key.size()) return false;

		string sub = key.substr(0, found.size());
		if (sub != found) return false;

		if (key == found) return true;		

		bool ret = false;
		for (int i = 0; i < moveMax; i++) {
			int newY = y + moveY[i];
			int newX = x + moveX[i];			

			if (hasWord1(found, newY, newX, pos, i)) {
				ret = true;
				break;
			}						
		}

		pos.erase(iter.first);
		return ret;
	};

	set<pair<int, int>> pos;
	key = "ade";	
	_result = hasWord1("", 0, 0, pos, 0);
	key = "aga";	
	pos.clear();
	_result = hasWord1("", 0, 0, pos, 0);

	function<bool(const string&, int, int, int)> hasWord2 = [&](const string& key, int index, int y, int x)->bool {
		if (y < 0 || x < 0 || y > max - 1 || x > max - 1) return false;
		if (index > key.size() - 1) return false;
		if (key[index] != _input[y][x]) return false;		
		
		if (index == key.size() - 1) return true;

		bool ret = false;
		for (int i = 0; i < moveMax; i++) {
			int newY = y + moveY[i];
			int newX = x + moveX[i];

			if (hasWord2(key, index + 1, newY, newX)) {
				ret = true;
				break;
			}
		}

		return ret;
	};

	string key2 = "ade";
	_result = hasWord2(key2, 0, 0, 0);
	key2 = "aga";
	_result = hasWord2(key2, 0, 0, 0);	
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
	_input.push_back("gdf");
	_input.push_back("iie");
}
