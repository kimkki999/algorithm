// stl test.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <map>
#include <list>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

void test1() {
	map<int, map<int, int>> *pMap2 = new map<int, map<int, int>>();

	for (int i = 0; i < 10000; i++) {
		map<int, int> temp;// = new map<int, int>();
		auto p = make_pair(i, temp);
		pMap2->insert(p);
		pMap2->insert(make_pair(i, temp));
		pMap2->insert(make_pair(i, map<int, int>()));
	}

	delete pMap2;
}
void test2() {
	map<int, map<int, int>*> *pMap2 = new map<int, map<int, int>*>();

	for (int i = 0; i < 10000; i++) {
		map<int, int> *pTemp = new map<int, int>();
		auto p = make_pair(i, pTemp);
		pMap2->insert(p);
		pMap2->insert(make_pair(i, pTemp));
		pMap2->insert(make_pair(i, new map<int, int>()));
	}

	for (auto iter : *pMap2) {
		delete iter.second;
	}
	delete pMap2;
}

void test3() {
	int i = 100 / 1000;
	int j = 100 % 11;

	int test[100];
	cout << "sizeof : int test[100] : " << sizeof(test) << endl;
	cout << "sizeof(long) : " << sizeof(long) << endl;
	cout << "sizeof(long long) : " << sizeof(long long) << endl;
	// => result 400
}

void test4() {
	vector<string*> test;
	test.push_back(new string("1"));

	for (const auto& val : test) {
		cout << *val << endl;
	}

	vector<string> test2;
	test2.push_back(string("2"));

	for (const auto& val : test2) {
		cout << val << endl;
	}
}

void test5() {
	auto comp = [](const shared_ptr<string>& l, const shared_ptr<string>& r) {return *l < *r; };

	vector<shared_ptr<string>> init{ make_shared<string>("one"), make_shared<string>("two") };
	priority_queue < shared_ptr<string>, vector<shared_ptr<string>>, decltype(comp)> words(comp, init);

	make_heap(begin(init), end(init),
		[](const shared_ptr<string>& l, const shared_ptr<string>& r) {return *l < *r; });
}

void testLambda() {
	[]() {cout << "test1" << endl; }();
	[]() {cout << "test2" << endl; }();

	[](string name) {cout << name << endl; }("test3");

	//implicit return
	auto fool = [] {return 3.14; }();
	//explicit
	auto bar = []()->float {return 3.14; }();

	//capture by ref
	int sum = 0;
	int num = 10;
	[&sum](int& number) {sum += number; }(num);

	//capture by val
	[sum](int number = 0) {number = sum;}();
}

int main()
{
	// map test 1
	//test1();
	//// map test 2
	//test2();

	//test3();
	//test4();
	testLambda();
}
