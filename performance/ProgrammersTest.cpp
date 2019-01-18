#include "pch.h"
#include "ProgrammersTest.h"

ProgrammersTest::ProgrammersTest()
	: Problem()
{
}


ProgrammersTest::~ProgrammersTest()
{
}

void ProgrammersTest::Input()
{
}

void ProgrammersTest::MaxPath()
{
	vector<vector<int>> triangle{ {7},{3, 8},{8, 1, 0},{2, 7, 4, 4},{4, 5, 2, 6, 5} };

	int cache[500][500];
	memset(cache, -1, sizeof(cache));

	function<int(int, int)> maxPath = [&](int y, int x)->int {
		if (y == triangle.size() - 1) {
			return triangle[y][x];
		}

		int& ret = cache[y][x];
		if (ret != -1) return ret;

		ret = max(maxPath(y + 1, x), maxPath(y + 1, x + 1)) + triangle[y][x];
		return ret;
	};

	int result = maxPath(0, 0);
}

void ProgrammersTest::ShortestPath(int m, int n, const vector<vector<int>>& puddles, int& shortest, int& cnt)
{	
	int cache[101][101];
	memset(cache, -1, sizeof(cache));

	for (const auto& val : puddles) {
		// because puddles position is x, y so reverse 0, 1
		cache[val[1]][val[0]] = INT32_MAX;
	}
	
	function<int (int, int)> shortestPath = [&](int y, int x)->int {
		if (y == n && x == m) {
			return 1;
		}		
		
		int& ret = cache[y][x];
		if (ret != -1) return ret;
				
		if (y == n) {
			int val = shortestPath(y, x + 1);
			if (val == INT32_MAX) {
				ret = val;
			}
			else 
				ret = val + 1;			
		}
		else if (x == m) {
			int val = shortestPath(y + 1, x);
			if (val == INT32_MAX) {
				ret = val;
			}
			else
				ret = val + 1;
			//}
		}
		else {
			int val1 = shortestPath(y + 1, x);
			int val2 = shortestPath(y, x + 1);

			if (val1 == INT32_MAX && val2 == INT32_MAX) {
				ret = INT32_MAX;
			}
			else {
				ret = min(val1, val2) + 1;
			}
		}

		return ret;
	};

	shortest = shortestPath(1, 1);

	int countCache[101][101];
	memset(countCache, -1, sizeof(countCache));
	const int MOD = 1000000007;
	
	function<int(int, int)> count = [&](int y, int x)->int {
		if (y == n && x == m) {
			return 1;
		}
		if (shortestPath(y, x) == INT32_MAX)
			return 0;

		int& ret = countCache[y][x];
		if (ret != -1) return ret;

		ret = 0;
		if (y == n) {
			ret += count(y, x + 1)%MOD;
		}
		else if (x == m) {
			ret += count(y + 1, x)%MOD;
		}
		else {
			if (shortestPath(y + 1, x) <= shortestPath(y, x + 1)) {
				ret += count(y + 1, x)%MOD;
			}
			if (shortestPath(y + 1, x) >= shortestPath(y, x + 1)) {
				ret += count(y, x + 1)%MOD;
			}
		}
		
		return ret%MOD;
	};

	cnt = count(1, 1);	
}

int ProgrammersTest::MaxCardSum(vector<int> left, vector<int> right)
{
	const int Size = 2000;
	int **cache;
	cache = new int*[Size];
	for (int i = 0; i < Size; i++) {
		cache[i] = new int[Size];
		memset(cache[i], -1, Size);
	}
	
	/*int cache[(const int)left.size()][(const int)right.size()];
	memset(cache, -1, sizeof(cache));*/

	function<int(int, int)> maxCardSum = [&](int startL, int startR)->int {
		if (startL == left.size() || startR == right.size()) {
			return 0;
		}

		int& ret = cache[startL][startR];
		if (ret != -1) return ret;

		ret = 0;
		if (left[startL] > right[startR]) {
			ret =  right[startR];
			ret += maxCardSum(startL, startR + 1);
		}
		else {
			int val1 = maxCardSum(startL + 1, startR);
			int val2 = maxCardSum(startL + 1, startR + 1);
			ret += max(val1, val2);
		}

		return ret;
	};

	int result =  maxCardSum(0, 0);
	for (int i = 0; i < Size; i++) {
		delete[] cache[i];
	}
	delete[]cache;

	return result;
}

int ProgrammersTest::MaxSteal(vector<int> money1) {
	
	vector<int> money = money1;
	priority_queue<int> pQeueu;

	int **cache = new int*[2];
	for (int i = 0; i < 2; i++) {
		cache[i] = new int[1000000];
		memset(cache[i], -1, sizeof(int) * 1000000);
	}
	
	function<int(int, int)> maxSteal = [&](int pos, int type)->int {
		if (pos >= money.size() - type)
			return 0;
		
		int &ret = cache[type][pos];
		if (ret != -1) return ret;

		ret = 0;		
		ret = max(maxSteal(pos + 2, type), maxSteal(pos + 3, type)) + money[pos];
		
		return ret;
	};

	//int result1 = maxSteal(0, money[0] == 0 ? 0 : 1); // 원형으로 마지막거 제외하기 위해
	//int result2 = maxSteal(1, 0);
	int result = 0;
	for (int i = 0; i < money.size(); i++) {
		int type = 0;
		if (i == 0 && money[0] != 0)
			type = 1;
		result = max(result, maxSteal(i, type));
	}

	for (int i = 0; i < 2; i++) {
		delete[] cache[i];		
	}
	delete[]cache;

	//return max(result1, result2);
	return result;
}

int ProgrammersTest::MaxGive(int limit, vector<vector<int>> travel) {

	function<pair<int, int>(pair<int, int>&, pair<int, int>&, int)> addPair = 
		[](pair<int, int>& fir, pair<int,int>& sec, int limit)->pair<int, int> {
		int first = fir.first + sec.first;
		int second = fir.second + sec.second;

		if (second > limit)
			first = 0;
		return pair<int, int>(first, second);
	};

	reverse(travel.begin(), travel.end());

	function<pair<int, int> (int, int)> maxGive = [&](int start, int type)->pair<int,int> {
		if (start == travel.size())
			return make_pair(0, 0);
		
		// cache

		// calc
		pair<int, int> ret(0, 0);

		pair<int, int> curVal;
		if (type == 0) {
			curVal.first = (travel[start][1]);
			curVal.second = (travel[start][0]);
		}
		else {
			curVal.first = (travel[start][3]);
			curVal.second = (travel[start][2]);
		}
		
		//type 0:walk 1:bycle
		auto val1 = maxGive(start + 1, 0);
		auto val2 = maxGive(start + 1, 1);
		val1 = addPair(val1, curVal, limit);
		val2 = addPair(val2, curVal, limit);

		ret = max(val1, val2);
		
		return ret;
	};

	auto result1 = maxGive(0, 0);
	auto result2 = maxGive(0, 1);
	
	auto result = max(result1, result2);
	return result.first;
}

int ProgrammersTest::MaxOrderCount(int K, vector<int> box) {

	vector<int> partialSum;
	int sum = 0;
	for (const auto& val : box) {
		sum += val;
		partialSum.push_back(sum);
	}

	function<int(int)> maxOrderCount = [&](int start)->int {
		if (start == box.size()) {
			return 0;
		}

		int ret = 0;
		int stand = start == 0 ? 0 : box[start - 1];

		for (int i = start; i < box.size(); i++) {
			int val = box[start] - stand;
			if (val%K == 0) {
				ret += 1;
			}
		}		
		
		return ret;
	};

	return 0;
}

int ProgrammersTest::NetworkFlow(int vertex, vector<vector<int>> c)
{
	const int MAX_V = 100;
	// capacity[u][v] = u에서 v로 보낼 수 있는 용량
	// flow[u][v] = u에서 v로 흘러가는 유량 (반대 방향인 경우 음수)
	int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];

	for (int i = 0; i < c.size(); i++) {
		for (int j = 0; j < c[i].size(); j++) {
			capacity[i][j] = c[i][j];
		}
	}

	// flow[][]를 계산하고 총 유량을 반환한다
	function<int (int,int)> networkFlow = [&](int source, int sink)->int {
		// flow 를 0으로 초기화한다
		memset(flow, 0, sizeof(flow));
		int totalFlow = 0;

		while (true) {
			// 너비 우선 탐색으로 증가 경로를 찾는다
			vector<int> parent(MAX_V, -1);
			queue<int> q;
			parent[source] = source;
			q.push(source);
			while (!q.empty()) {
				int here = q.front(); q.pop();
				for (int there = 0; there < vertex; ++there) {
					// 잔여 용량이 남아 있는 간선을 따라 탐색한다
					if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
						q.push(there);
						parent[there] = here;
					}
				}

				// 조기 종료 조건 추가
				if (parent[sink] != -1) break;
			}
			// 증가 경로가 없으면 종료한다
			if (parent[sink] == -1) break;
			// 증가 경로를 통해 유량을 얼마나 보낼지 결정한다
			int amount = 987654321;
			for (int p = sink; p != source; p = parent[p])
				amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
			// 증가 경로를 통해 유량을 보낸다
			for (int p = sink; p != source; p = parent[p]) {
				flow[parent[p]][p] += amount;
				flow[p][parent[p]] -= amount;
			}
			totalFlow += amount;
		}

		return totalFlow;
	};

	int result = networkFlow(0, vertex - 1);
	return result;
}

void ProgrammersTest::Solve()
{
	MaxPath();
	int length, count;
	//vector<vector<int>> puddles{ {2,2},{3,3} };
	ShortestPath(1, 1, {}, length, count);
	_ASSERT(length == 1 && count == 1);
	ShortestPath(2, 2, {}, length, count);
	_ASSERT(length == 3 && count == 2);
	ShortestPath(2, 2, { {2, 1} }, length, count);
	_ASSERT(length == 3 && count == 1);
	ShortestPath(2, 2, { {2, 1},{1,2} }, length, count);
	_ASSERT(length == INT32_MAX && count == 0);
	ShortestPath(3, 3, {}, length, count);
	_ASSERT(length == 5 && count == 6);
	ShortestPath(3, 3, { {2,2} }, length, count);
	_ASSERT(length == 5 && count == 2);

	_ASSERT(MaxCardSum({ 3,2,5 }, { 2,4,1 }) == 7);

	_ASSERT(MaxSteal({ 1,2,3 }) == 3);
	_ASSERT(MaxSteal({ 1,2,3,1 }) == 4);
	_ASSERT(MaxSteal({ 5,1,1,2 }) == 6);//원형이어서 마지막거는 안 된다.
	_ASSERT(MaxSteal({ 5,1,1,2,3 }) == 7);//원형이어서
	_ASSERT(MaxSteal({ 0,0,0 }) == 0);
	_ASSERT(MaxSteal({ 0,0,1,0,2 }) == 3);

	_ASSERT(MaxGive(6, { {1,1,2,2}, {2,2,3,3}}) == 5);
	_ASSERT(MaxGive(7, { {1,1,2,2}, {3,3,4,4} }) == 6);
	_ASSERT(MaxGive(5, { {1,1,2,2}, {5,5,3,3} }) == 5);
//	_ASSERT(MaxGive(1650, { {500, 200, 200, 100}, {800, 370, 300, 120}, {700, 250, 300, 90} }) == 660);
//	_ASSERT(MaxGive(3000, { {1000, 2000, 300, 700}, {1100, 1900, 400, 900}, {900, 1800, 400, 700}, {1200, 2300, 500, 1200} }) == 5900);

	// 양방향
	_ASSERT(NetworkFlow(4, { {0,1,3,0},{1,0,0,2},{3,0,0,1},{0,2,1,0} }) == 2);
	// 한방향
	_ASSERT(NetworkFlow(4, { {0,1,3,0},{0,0,0,2},{0,0,0,1},{0,0,0,0} }) == 2);
	// cross 한방향
	_ASSERT(NetworkFlow(4, { {0,1,3,0},{0,0,1,2},{0,0,0,1},{0,0,0,0} }) == 2);
	//        a
	//     10     1
	//  s     10      t
	//    1       10
	//        b    
	_ASSERT(NetworkFlow(4, { {0,10,1,0},{0,0,10,1},{0,0,0,10},{0,0,0,0} }) == 11);

}

void ProgrammersTest::Result()
{
}

void ProgrammersTest::TestInput()
{
}
