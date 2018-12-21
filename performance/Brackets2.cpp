#include "pch.h"
#include "Brackets2.h"
#include "../00.KKICommon/Log.h"
#include "../00.KKICommon/Elapse.h"
#include "../00.KKICommon/Random.h"
#include <unordered_set>
#include <stack>

Brackets2::Brackets2()
	: Problem(), _input(), _result()
{
	Logger->Write(Debug, "%s", __func__);

}

Brackets2::~Brackets2()
{
	Logger->Write(Debug, "%s", __func__);
}

void Brackets2::TestInput() {
	Logger->Write(Debug, "%s", __func__);

	vector<char> brace{ '(',')', '[', ']', '{','}' };

	Random rnd;
	for (int i = 0; i < 100; i++) {
		// make string
		string str(10000, ' ');
		for (int index = 0; index < 10000; index++) {
			int n = rnd.getRandomNumber(0, brace.size() - 1);
			str[index] = brace[n];
		}
		_input.push_back(str);
	}
	
	Logger->Write(Info, "condition : 100 * (10000)");

	/*for (const auto &val : _input) {
		cout << val << endl;
	}*/
}

void Brackets2::Input() {
	Logger->Write(Debug, "%s", __func__);	
}

void Brackets2::Solve() {
	Logger->Write(Debug, "%s", __func__);

	Elapse elp;
	elp.Start();
	//unordered_set<char> open_char{ '(','{','[' };
	//unordered_set<char> close_char{ ')','}',']' };
	char open_char[3]{ '(','{','[' };
	char close_char[3]{ ')','}',']' };

	stack<char> stk;
	for (const auto &val : _input) {
		bool result = true;

		for (int i = 0; i < val.size(); i++) {
			char c = val[i];

			if (c == ')' || c == ']' || c == '}') {
				if (stk.size() == 0) {
					result = false;
					break;
				}

				const char& p = stk.top();
				result = (p == '(' && c == ')') ||
					(p == '{' && c == '}') ||
					(p == '[' && c == ']');

				if (result == false) {
					break;
				}
				stk.pop();
			}
			else {
				stk.push(c);
			}
		}

		// must be container is empty
		result = stk.empty();

		_result.push_back(result ? "YES" : "NO");
	}
	
	Logger->Write(Info, "solve elapse : %lf", elp.End());
}

void Brackets2::Result() {
	Logger->Write(Debug, "%s", __func__);

	for (const auto &val : _result) {
		cout << val << endl;
	}
}