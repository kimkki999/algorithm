#include "pch.h"
#include "Josephus.h"
#include "../00.KKICommon/Log.h"
#include "../00.KKICommon/Elapse.h"
#include <string>
#include <list>

Josephus::Josephus() 
	: Problem(), _input(), _result()
{
	Logger->Write(Debug, "%s", __func__);

}


Josephus::~Josephus()
{
	Logger->Write(Debug, "%s", __func__);
}

void Josephus::TestInput() {
	Logger->Write(Debug, "%s", __func__);
	for (int i = 0; i < 50; i++) {
		_input.push_back(make_pair(1000, 1000));
	}

	Logger->Write(Info, "condition : 50 * (1000, 1000)");
}

void Josephus::Input() {
	Logger->Write(Debug, "%s", __func__);
	// 1. case C <= 50
	// 2. N, K
	int c;
	cin >> c;

	while (c--) {
		int m, k;
		cin >> m >> k;
		_input.push_back(make_pair(m, k));
	}
}

void Josephus::Solve() {
	Logger->Write(Debug, "%s", __func__);
	
	Elapse elp;
	elp.Start();
	for (auto val : _input) {
		list<int> sl;
		int n = val.first;
		for (int i = 1; i <= n; i++) {
			sl.push_back(i);
		}

		auto kill = sl.begin();
		int count = val.second;
		while (n > 2) {
			kill = sl.erase(kill);

			if (kill == sl.end())
				kill = sl.begin();

			n--;
			for (int i = 0; i < count - 1; i++) {
				++kill;
				if (kill == sl.end()) kill = sl.begin();
			}
		}

		_result.push_back(make_pair(sl.front(), sl.back()));
	}

	Logger->Write(Info, "solve elapse : %lf", elp.End());
}

void Josephus::Result() {
	Logger->Write(Debug, "%s", __func__);

	for (auto val : _result) {
		cout << val.first << " " << val.second << endl;
	}
}