#include "pch.h"
#include "SoLong.h"
#include "../00.KKICommon/Log.h"
#include "../00.KKICommon/Elapse.h"

SoLong::SoLong() 
	: Problem(), _input(), _find(), _result(), _root()
{
}

SoLong::~SoLong()
{
}

void SoLong::TestInput() {
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
	
	_input.push_back("AAA");
	_input.push_back("ABC");
	_input.push_back("A");
	_input.push_back("B");
	_input.push_back("BBC");
	_input.push_back("BCD");

	_find.push_back("A");
	//Logger->Write(Info, "condition : 50 * (1000, 1000)");
}

void SoLong::Input() {
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void SoLong::Solve() {
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);

	Elapse elp;
	elp.Start();
	for (const auto& val : _input) {
		_root.insert(val.c_str());
	}

	for (const auto& val : _find) {
		TrieNode *foundNode = _root.find(val.c_str());
		if (foundNode) {
			string str = val;
			foundNode->addChildren(_result, str);
		}
	}
	Logger->Write(Info, "solve elapse : %lf", elp.End());
}

void SoLong::Result() {
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);

	for (auto val : _result) {
		cout << val << endl;
	}
}