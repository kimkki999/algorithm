#pragma once

#include <map>
#include <intrin.h>
#include "../00.KKICommon/Elapse.h"
#include "../00.KKICommon/Log.h"

namespace StlFunctionTest {

	void vectorIterator() {
		Logger->Write(Debug, "%s", __func__);

		vector<int> v{ 1,2,3,4,5 };
		auto iter = v.begin();
		iter = std::begin(v);
		int a = *iter;

		for (const auto& iter : v) {
			int a = iter;			
		}		
	}

	void vectorIterator2() {
		Logger->Write(Debug, "%s", __func__);

		vector<int*> v{ new int(1), new int(2) };

		auto iter = v.begin();
		int a = *(*iter);

		for (const auto& iter : v) {
			int a = *iter;
		}

		for (const auto& iter : v) {
			delete iter;
		}

		v.clear();
	}

	void vectorErase() {
		Logger->Write(Debug, "%s", __func__);

		vector<int> v{ 0,2,3,4,3 };
		auto iter = v.begin();
		int a = *iter;

		while (iter != v.end()) {
			if (*iter % 2 == 0) {
				iter = v.erase(iter);
				continue;
			}
			++iter;
		}
		
		/*for (const auto& iter : v) {
			v.erase(&iter);
		}*/
	}
	
	void listErase() {
		Logger->Write(Debug, "%s", __func__);

		list<int> v{ 0,2,3,4,3 };
		auto iter = v.begin();
		int a = *iter;

		while (iter != v.end()) {
			if (*iter % 2 == 0) {
				iter = v.erase(iter);
				continue;
			}
			++iter;
		}

		// if item is 3 then remove all
		v.remove(3);
	}

	template<typename T>
	class EraseFunctionObject : public unary_function<T, bool> {
	public:
		bool operator() (T& val)
		{
			return (val >= 2 && val < 4);
		}
	};
	void listEraseByFunctionObject() {
		Logger->Write(Debug, "%s", __func__);

		list<int> v{ 1,2,3,4,5 };
		v.remove_if(EraseFunctionObject<int>());
	}

	template<typename T>
	class CompareFunctionObject
	{
	public:
		bool operator () (const T& t1, const T& t2) {
			return t1 < t2;
		}
	};
	void listSortByFunctionObject() {
		Logger->Write(Debug, "%s", __func__);

		list<int> v{ 1,3,2,5,4 };
		v.sort(CompareFunctionObject<int>());
	}

	class Polygon {
	public:
		Polygon(int x, int y) : _x(x), _y(y) {

		}
		/*ostream& operator<<(ostream& os, const Polygon& val) {
			return os << "X : " << val._x << "Y : " << val._y;
		}*/
		ostream& operator<<(ostream& os) {
			Logger->Write(Debug, "polygon's %s", __func__);
			return os << "X : " << _x << "Y : " << _y;
		}
		void SetX(int val) { _x = val; }
		void SetY(int val) { _y = val; }
		int GetX() { return _x; }
		int GetY() { return _y; }
	private:
		int _x;
		int _y;
	};

	ostream& operator<<(ostream& os, Polygon& val) {
		Logger->Write(Debug, "function's %s", __func__);
		return val << os;
	}

	void testExample() {
		// a, b, c, d, e ploygon
		list<Polygon*> l;
		Polygon *a, *b, *c, *d, *e, *f;

		l.push_back(a = new Polygon(50, 200));
		l.push_back(b = new Polygon(20, 80));
		l.push_back(c = new Polygon(75, 10));
		l.push_back(d = new Polygon(130, 80));
		l.push_back(e = new Polygon(100, 200));

		
		for (auto iter : l) {
			// below code call function operator<<(ostream, ploygon)
			cout << *iter << endl;
			// below code call polygon's operator<<
			*iter << cout << endl;

			Logger->Write(Debug, "x:%d y:%d", iter->GetX(), iter->GetY());
		}		

		// insert f at front e		
		for (auto iter = l.begin(); iter != l.end(); ++iter) {
			if (*iter == e) {
				l.insert(iter, f = new Polygon(180, 150));
				break;
			}
		}

		// modify d
		
		for (auto iter = l.begin(); iter != l.end(); ++iter) {
			if (*iter == d) {
				(*iter)->SetX(200);
				(*iter)->SetY(100);
				break;
			}
		}
		
		// delete c
		l.remove(c);
	}

	void DynamicTest() {
		vector<int> *pV = new vector<int>;
		vector<int> *pV1 = new vector<int>(100, 0);
		vector<int> *pV2 = new vector<int>{ 1,2,3,4,5 };

		delete pV;
		delete pV1;
		delete pV2;
	}

	void testUnorderedMap() {
		unordered_map<int, float> *pM = new unordered_map<int, float>;

		pM->insert(unordered_map<int, float>::value_type(1, 2.1));
		pM->insert(make_pair(1, 2.1));

		delete pM;
	}

	void testMap() {
		map<int, int> v;

		auto pr = v.insert(make_pair(1, 1));
		pr = v.insert(make_pair(1, 1));
	}

	void testBit() {
		// u , ul, ull
		// gcc __builtin_popcount
		unsigned int full20 = (1ull << 20) - 1;
		auto count = __popcnt(full20);

		unsigned long index;
		// gcc __builtin_ctz
		_BitScanForward(&index, full20);
	}

	void Start() {
		//sequence container
		vectorIterator();
		vectorIterator2();
		vectorErase();
		listErase();
		listEraseByFunctionObject();
		listSortByFunctionObject();
		testExample();
		DynamicTest();

		//node container
		testUnorderedMap();
		testMap();

		//algorithm
		testBit();
	}
}

