#pragma once

#include "../00.KKICommon/Elapse.h"
#include "../00.KKICommon/Log.h"

using namespace std;

// performance test
// result 
// input 10000
/*
[2018 - 12 - 12.14:50 : 36][Debug] : listInsertVal
[2018 - 12 - 12.14:50 : 36][Info] : elapse : 0.488000
[2018 - 12 - 12.14:50 : 37][Info] : elapse(return by val) : 0.511000
[2018 - 12 - 12.14:50 : 37][Info] : elapse(return by ref) : 0.266000
[2018 - 12 - 12.14:50 : 37][Info] : clear elapse : 0.155000
[2018 - 12 - 12.14:50 : 37][Debug] : listInsertPoint
[2018 - 12 - 12.14:50 : 38][Info] : elapse : 0.306000
[2018 - 12 - 12.14:50 : 38][Info] : clear elapse : 0.180000
*/

namespace Performance {
	
	void listInsertVal(const int& count) {
		Logger->Write(Debug, "%s", __func__);

		Elapse elp;
		list<string> lst;
		for (int i = 0; i < count; i++) {
			lst.push_back("aaaaaaaaaaaaaaaa");
		}

		Logger->Write(Info, "elapse : %lf", elp.End());

		// access
		elp.Start();
		for (auto i : lst) {
			auto a = i;
		}
		Logger->Write(Info, "elapse(return by val) : %lf", elp.End());

		elp.Start();
		for (auto& i : lst) {
			auto a = i;
		}
		Logger->Write(Info, "elapse(return by ref) : %lf", elp.End());

		// clear
		elp.Start();
		lst.clear();
		Logger->Write(Info, "clear elapse : %lf", elp.End());
	}
	void listInsertPoint(const int& count) {
		Logger->Write(Debug, "%s", __func__);

		Elapse elp;
		list<string*> lst;
		for (int i = 0; i < count; i++) {
			lst.push_back(new string("aaaaaaaaaaaaaaaa"));
		}
		Logger->Write(Info, "elapse : %lf", elp.End());

		elp.Start();
		for (auto& i : lst) {
			delete i;
		}
		lst.clear();
		Logger->Write(Info, "clear elapse : %lf", elp.End());
	}

	void Start() {
		int count;
		cout << "input test count : ";
		cin >> count;
	}
}