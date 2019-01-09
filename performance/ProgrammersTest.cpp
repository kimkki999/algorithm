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
}

void ProgrammersTest::Result()
{
}

void ProgrammersTest::TestInput()
{
}
