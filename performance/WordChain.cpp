#include "pch.h"
#include "WordChain.h"
#include "../00.KKICommon/Log.h"
#include "../00.KKICommon/Elapse.h"
#include <functional>

WordChain::WordChain()
	: Problem(), _input(), _result()
{
}

WordChain::~WordChain()
{
}

void WordChain::TestInput() {
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);

	_input.push_back(vector<string>{"dog", "god", "dragon", "need"});
	//Logger->Write(Info, "condition : 50 * (1000, 1000)");
}

void WordChain::MakeGraph(vector<vector<int>>& adj, const vector<string>& vec)
{
	for (int j = 1; j < vec.size(); j++) {
		int i = j - 1;
		int len = min(vec[i].size(), vec[j].size());

		for (int k = 0; k < len; k++) {
			if (vec[i][k] != vec[j][k]) {
				int a = vec[i][k] - 'a';
				int b = vec[j][k] - 'a';
				adj[a][b] = 1;
				break;
			}
		}
	}
}

void WordChain::Input() {
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void WordChain::Solve() {
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);

	Elapse elp;
	elp.Start();

	for (const auto& vec : _input) {
		vector<vector<int>> adj(26, vector<int>(26, 0));
		vector<int> inDegree, outDegree;
		vector<string> graph[ALPHABET][ALPHABET];
		for (int i = 0; i < ALPHABET; i++) {
			for (int j = 0; j < ALPHABET; j++) {
				graph[i][j].clear();
			}
		}
		inDegree = outDegree = vector<int>(ALPHABET, 0);
		
		auto toNumber = [](const char& ch) {
			return ch - 'a';
		};
		
		auto makeGraph = [&]() {
			for (int i = 0; i < vec.size(); i++) {
				int a = toNumber(vec[i][0]);
				int b = toNumber(vec[i][vec[i].size() - 1]);
				graph[a][b].push_back(vec[i]);
				adj[a][b]++;
				inDegree[b]++;
				outDegree[a]++;
			}
		};

		function<void (int, vector<int>&)> getEulerCircuit = [&](int here, vector<int>& circuit) {
			for (int there = 0; there < adj.size(); ++there) {
				while (adj[here][there] > 0) {
					adj[here][there]--;
					getEulerCircuit(there, circuit);
				}
			}
			circuit.push_back(here);
		};

		//MakeGraph(adj, vec);
		//_result.push_back(topologicalSort());
	}

	Logger->Write(Info, "solve elapse : %lf", elp.End());
}

void WordChain::Result() {
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