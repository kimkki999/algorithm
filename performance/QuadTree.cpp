#include "pch.h"
#include "QuadTree.h"


QuadTree::QuadTree()
	: Problem(), _input(), _result()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}


QuadTree::~QuadTree()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void QuadTree::Input()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void QuadTree::Solve()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);

	for (const auto& val : _input) {

		function<string(const string&)> quadTreeReverse = [&](const string in)->string {
			int positionX = -1;
			for (int i = 0; i < 4; i++) {
				if (in[i] == 'x') {
					positionX = i;
					break;
				}
			}

			string result = "";
			if (positionX == -1) {
				result.push_back(in[2]);
				result.push_back(in[3]);
				result.push_back(in[0]);
				result.push_back(in[1]);

				return result;
			}

			string sub1 = in.substr(0, positionX + 1);
			string sub2 = in.substr(positionX + 1);
			return sub1 + quadTreeReverse(sub2);
		};

		//string result = quadTreeReverse(val);

		function<string(string::iterator&)> quadTreeReverse2 = [&](string::iterator& it)->string {
			char head = *it;

			++it;
			if (head == 'w' || head == 'b') {
				return string(1, head);
			}
			string ul = quadTreeReverse2(it);
			string ur = quadTreeReverse2(it);
			string ll = quadTreeReverse2(it);
			string lr = quadTreeReverse2(it);

			return string("x") + ll + lr + ul + ur;
		};

		string val2 = val;
		string::iterator iter = val2.begin();
		string result = quadTreeReverse2(iter);
		_result.push_back(result);
	}
}

void QuadTree::Result()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
	for (const auto& val : _result) {
		Logger->Write(Debug, "%s", val.c_str());
	}
}

void QuadTree::TestInput()
{
	_input.push_back("xbwwb");
	_input.push_back("xbwxwbbwb");
}
