#include "pch.h"
#include "BFS.h"
#include "../00.KKICommon/Log.h"
#include "../00.KKICommon/Elapse.h"

BFS::BFS()
	: Problem(), _input(), _result()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

BFS::~BFS()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void BFS::Input()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
}

void BFS::Solve()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);

	Elapse elp;
	elp.Start();
	vector<vector<int>> adj;

	auto bfs = [&adj](int start)->vector<int> {
		vector<bool> discovered(adj.size(), false);
		queue<int> q;

		vector<int> order;
		discovered[start] = true;
		q.push(start);

		while (!q.empty()) {
			int here = q.front();
			q.pop();
			order.push_back(here);

			for (int i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i];
				if (!discovered[there]) {
					q.push(there);
					discovered[there] = true;
				}
			}
		}

		return order;
	};

	vector<int> distance;
	vector<int> parent;

	auto bfs2 = [&adj, &distance, &parent](int start) {
		distance = vector<int>(adj.size(), -1);
		parent = vector<int>(adj.size(), -1);

		queue<int> q;
		distance[start] = 0;
		parent[start] = start;

		q.push(start);
		while (!q.empty()) {
			int here = q.front();
			q.pop();

			for (int i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i];
				if (distance[there] == -1) {
					q.push(there);
					distance[there] = distance[here] + 1;
					parent[there] = here;
				}
			}
		}
	};

	auto shortestPath = [&parent](int v)->vector<int> {
		vector<int> path(1, v);

		while (parent[v] != v) {
			v = parent[v];
			path.push_back(v);
		}

		reverse(path.begin(), path.end());

		return path;
	};

	Logger->Write(Info, "solve elapse : %lf", elp.End());
}

void BFS::Result()
{
}

void BFS::TestInput()
{
}
