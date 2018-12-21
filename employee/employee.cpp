// employee.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Employee {
private:
	
	int id;
	unordered_set<int> resources;
	Employee* super;
	//unordered_map<int, Employee*> subs;

public:
	Employee(int id, Employee* p) : id(id), super(p) {}

	void AddResource(const int& val) {
		resources.insert(val);
	}
	void AddResource(const vector<int>& vals) {
		for (const auto& r : vals) {
			resources.insert(r);
		}
	}
	bool IsMe(int id) {
		return this->id == id;
	}
	Employee* GetSuper() {
		return super;
	}
};

class Manager {
private:
	//Employee emp;
	unordered_map<int, Employee*> allEmp;
	unordered_map<int, int> resourceMap;
public:
	void AddEmp(int id, int superId, vector<int>& resourceIds) {

		for (const auto& i : resourceIds) {
			resourceMap.insert(make_pair(i, id));
		}

		Employee* pSuper = nullptr;
		auto iter = allEmp.find(superId);
		if (iter != allEmp.end()) {
			pSuper = iter->second;
		}

		AddEmp(id, pSuper, resourceIds);
	}	
	void AddEmp(int id, Employee *pSuper, vector<int>& resourceIds) {
		auto iter = allEmp.find(id);
		if (iter == allEmp.end()) {
			Employee *pEmp = new Employee(id, pSuper);
			allEmp.insert(make_pair(id, pEmp));			
		}
		allEmp[id]->AddResource(resourceIds);
	}

	bool HasResource(int id, int resourceId) {
		bool result = false;
		auto iter = resourceMap.find(resourceId);
		if (iter != resourceMap.end()) {
			// search for id to super
			auto emp = allEmp.find(iter->second);
			if (emp != allEmp.end()) {
				Employee *p = emp->second;
				result = HasResource(id, p);
			}
		}
		return result;
	}

	bool HasResource(int id, Employee* p) {
		bool result = false;
		if (p == nullptr) {
			return result;
		}

		if (p->IsMe(id)) {
			result = true;
		}
		else {
			result = HasResource(id, p->GetSuper());
		}

		return result;
	}
};

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	Manager manager;
	int numEmployee, numQuery;
	cin >> numEmployee >> numQuery;
	
	while (numEmployee--) {
		int id, superId, resourceCount;
		cin >> id >> superId >> resourceCount;

		vector<int> resources;
		while (resourceCount--) {
			int resourceId;
			cin >> resourceId;
			resources.push_back(resourceId);			
		}
		manager.AddEmp(id, superId, resources);
	}

	while (numQuery--) {
		int id, resourceId;
		cin >> id >> resourceId;

		string result = "false";
		if (manager.HasResource(id, resourceId)){
			result = "true";
		}

		cout << result << endl;
	}

	return 0;
}


#include <ctime>
#include <random>

int getRandomNumber(int min, int max) {
	random_device rn;
	mt19937 rnd(rn());

	uniform_int_distribution<int> range(min, max);
	return range(rnd);
}

vector<int> makeResource(int num, vector<int>& leftResources) {
	vector<int> result;

	for (int i = 0; i < num; i++) {
		int index = getRandomNumber(1, leftResources.size()) - 1;
		int resourceId = leftResources[index];

		result.push_back(resourceId);
		leftResources.erase(leftResources.begin() + index);
	}

	return result;
}

vector<pair<int, int>> makeQuery(int numQuery) {
	vector<pair<int, int>> result;

	for (int i = 0; i < numQuery; i++) {
		int id = getRandomNumber(1, 2);
		//string str = makeKeyword();
		int length = getRandomNumber(1, 10);

		//result.push_back(make_pair(type, make_pair(str, length)));
	}

	return result;
}

int CalcElapseTime(const clock_t& start, const clock_t& end) {
	return ((double)(end - start));
}

void WriteLog(string msg, const clock_t& start) {
	int t = CalcElapseTime(start, clock());

	cout << t << " : " << msg << endl;
}


//int main() {
//	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
//	Manager manager;
//	int numEmployee, numQuery;
//	cin >> numEmployee >> numQuery;
//
//	while (numEmployee--) {
//		int id, superId, resourceCount;
//		cin >> id >> superId >> resourceCount;
//
//		vector<int> resources;
//		while (resourceCount--) {
//			int resourceId;
//			cin >> resourceId;
//			resources.push_back(resourceId);
//		}
//		manager.AddEmp(id, superId, resources);
//	}
//
//	while (numQuery--) {
//		int id, resourceId;
//		cin >> id >> resourceId;
//
//		string result = "false";
//		if (manager.HasResource(id, resourceId)) {
//			result = "true";
//		}
//
//		cout << result << endl;
//	}
//
//	return 0;
//}