#include "pch.h"
#include "Tsp.h"


Tsp::Tsp()
{
}


Tsp::~Tsp()
{
}

void Tsp::Input()
{
}

void Tsp::Solve()
{
	int n = 10;
	vector<int> taken(n, 0);
	vector<vector<int>> distMap(n, vector<int>(n, 0));

	function<bool()> allTaken = [&]()->bool {
		bool ret = true;
		for (const auto& val : taken) {
			if (!val) {
				ret = false;
				break;
			}
		}
		return ret;
	};

	function<int(int, int)> shortestPath = [&](int dist, int pos)->int {
		// if all taken
		if (allTaken()) {
			return dist + distMap[pos][0];
		}
		//
		int ret = INT32_MAX;
		for (int i = 0; i < n; i++) {
			if (taken[i] == 0) {
				taken[i] = 1;
				ret = min(ret, shortestPath(dist + distMap[pos][i], i));
				taken[i] = 0;
			}
		}
		return ret;
	};
}

void Tsp::Result()
{
}

void Tsp::TestInput()
{
}
