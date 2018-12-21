#include "pch.h"
#include "Dictionary.h"
#include "../00.KKICommon/Log.h"
#include "../00.KKICommon/Elapse.h"


Dictionary::Dictionary() 
	: Problem(), _input(), _result(),
	_adj(26, vector<int>(26,0))
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

Dictionary::~Dictionary()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void Dictionary::TestInput() {
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);

	//_input.push_back(vector<string>{"a", "b", "c"});
	_input.push_back(vector<string>{"ba", "aa", "ab"});
	_input.push_back(vector<string>{"gg", "kia", "lotte", "lg","hanwha"});
	_input.push_back(vector<string>{"dictionary", "english", "is", "ordered", "ordinary", "this"});
	//Logger->Write(Info, "condition : 50 * (1000, 1000)");
}

void Dictionary::MakeGraph(const vector<string>& vec)
{
	for (int j = 1; j < vec.size(); j++) {
		int i = j - 1;
		int len = min(vec[i].size(), vec[j].size());

		for (int k = 0; k < len; k++) {
			if (vec[i][k] != vec[j][k]) {
				int a = vec[i][k] - 'a';
				int b = vec[j][k] - 'a';
				_adj[a][b] = 1;
				break;
			}
		}
	}
}

void Dictionary::Input() {
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);	
}

void Dictionary::dfs(int here) {
	_seen[here] = 1;
	for (int there = 0; there < _adj.size(); ++there) {
		if (_adj[here][there] && !_seen[there]) {
			dfs(there);
		}
	}
	_order.push_back(here);

	//순서와 거꾸로 정렬된다.
}

vector<int> Dictionary::topologicalSort() {
	int n = _adj.size();
	_seen = vector<int>(n, 0);
	_order.clear();

	for (int i = 0; i < n; ++i) if (!_seen[i]) dfs(i);

	reverse(_order.begin(), _order.end());

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (_adj[_order[j]][_order[i]]) {
				return vector<int>();
			}
		}
	}

	return _order;
}

void Dictionary::Solve() {
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);

	Elapse elp;
	elp.Start();
	
	for (const auto& vec : _input) {		
		_adj = vector < vector<int>>(26, vector<int>(26, 0));
		MakeGraph(vec);
		_result.push_back(topologicalSort());
	}

	Logger->Write(Info, "solve elapse : %lf", elp.End());
}

void Dictionary::Result() {
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);

	for (const auto& val : _result) {
		if (val.size() == 0) {
			cout << "Invalid" << endl;
		}
		else {
			for (const auto& v : val) {
				char ch = v + 'a';
				cout << ch;
			}
			cout << endl;
		}
	}
}