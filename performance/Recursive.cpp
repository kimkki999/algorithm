#include "pch.h"
#include "Recursive.h"
#include <functional>
#include "../00.KKICommon/Log.h"
#include "../00.KKICommon/Elapse.h"
#include <string>
#include <sstream>

Recursive::Recursive()
	:Problem(), _h(0), _w(0), _input(), _result()
{
}


Recursive::~Recursive()
{
}

void Recursive::Input()
{
}

int Recursive::Sum(int n) {
	if (n == 1) return 1;
	return n + Sum(n - 1);
}

string Recursive::Print(vector<int> input) {
	string str = "";
	/*for (int i = 0; i < input.size(); i++) {
		str += " ";
		str += itoa(input[i]);
	}
	Logger->Write(Debug, "inputs %s", str.c_str());*/
	return str;
}

void Recursive::Solve()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
	//recursive test
	// 1. sum
	long sum = 0;

	function<void (int)> sumFunc = [&](int n)->int {
		
		if (n < 1) return 0;
		sum += n;
		sumFunc(n - 1);

		//return sum;
		
		/*if (n == 1) return 1;
		return n + sumFunc(n - 1);*/
	};

	function<int (int)> sumFunc2 = [&sumFunc2](int n)->int {
		if (n < 1) return 0;
		return n + sumFunc2(n - 1);
	};

	sumFunc(100);
	Logger->Write(Debug, "sumFunc : %ld", sum);

	sum = sumFunc2(100);
	Logger->Write(Debug, "sumFunc2 : %ld", sum);

	sum = Sum(100);
	Logger->Write(Debug, "Sum : %ld", sum);


	// sum
	function<int(int)> sumFunc3 = [&sumFunc3](int n)->int {
		if (n == 1) return 1;
		if (n % 2 != 0) return sumFunc3(n - 1) + n;
		return 2*sumFunc3(n / 2) + (n*n) / 4;
	};

	sum = sumFunc3(100);
	Logger->Write(Debug, "sumFunc3 : %ld", sum);

	//merge sort
	vector<int> testInputs{ 7,8,9,1,2,3,5,6,4,0 };
	Print(testInputs);

	function<string (vector<int>)> makeString = [](vector<int> input)->string {
		string str = "";
		stringstream ss;
		for (int i = 0; i < input.size(); i++) {
			ss << " " << input[i];
		}
		str = ss.str();
		return str;
	};

	function<vector<int>(vector<int>)> mergeSort = [&](vector<int> inputs)->vector<int> {
		Logger->Write(Debug, "mergeSort %d", inputs.size());
		Logger->Write(Debug, "inputs %s", makeString(inputs).c_str());
		
		if (inputs.size() == 1) return vector<int>(1, inputs[0]);

		int mid = inputs.size() / 2;
		vector<int> low, high;
		for (int i = 0; i < mid; i++) {
			low.push_back(inputs[i]);			
		}
		for (int i = mid; i < inputs.size(); i++) {
			high.push_back(inputs[i]);
		}
		low = mergeSort(low);
		high = mergeSort(high);

		vector<int> result;
		int i, j;
		i = j = 0;
		while (true) {
			if (i == low.size()) {
				for (int k = j; k < high.size(); k++) {
					result.push_back(high[k]);
				}
				break;
			}
			if (j == high.size()) {
				for (int k = i; k < low.size(); k++) {
					result.push_back(low[k]);
				}
				break;
			}

			if (low[i] < high[j]) {
				result.push_back(low[i++]);
			}
			else {
				result.push_back(high[j++]);
			}
		}

		Logger->Write(Debug, "partial result %s", makeString(result).c_str());
		return result;
	};

	vector<int> result = mergeSort(testInputs);

	Logger->Write(Debug, "merge sort final result %s", makeString(result).c_str());	

	// quick sort
	function<vector<int> (vector<int>)> quickSort = [&quickSort, &makeString](vector<int> inputs)->vector<int> {
		if (inputs.size() <= 1) return vector<int>(1, inputs[9]);

		int pivot = inputs[0];
		int low = 1;
		int high = inputs.size();

		//function<void (vector<int>&, int, int)> swap = [](vector<int>& in, int x, int y) {
		auto swap = [](vector<int>& in, int x, int y) {
			int temp = in[x];
			in[x] = in[y];
			in[y] = temp;
		};

		while (low < high) {
			do {
				low++;
			} while (inputs[low] < pivot);

			do {
				high--;
			} while (inputs[high] > pivot);

			if (low < high) {
				swap(inputs, low, high);
			}
		}
		//change pivot with low
		swap(inputs, low, 0);
		quickSort(inputs);
	};
}

int Recursive::Partitioning(int list[], int left, int right) {
	int pivot = list[left];
	int low = left + 1;
	int high = right;

	do {
		do {
			low++;
		} while (list[low] < pivot);

		do {
			high--;
		} while (list[high] > pivot);

		if (low < high) {
			int temp = list[high];
			list[high] = list[low];
			list[low] = temp;
		}
	} while (low < high);

	list[left] = list[high];
	list[high] = pivot;
	return low;
}

void Recursive::QuickSort(int list[], int left, int right) {
	if (left < right) {
		// partitioning
		// return pivot position
		int p = Partitioning(list, left, right);

		// left sort
		// right sort
		QuickSort(list, left, p - 1);
		QuickSort(list, p + 1, right);		
	}
}

void Recursive::Result()
{
}

void Recursive::TestInput()
{
	Logger->Write(Debug, "%s::%s", typeid(this).name(), __func__);
	_h = 3;
	_w = 7;

	_input.push_back("#.....#");
	_input.push_back("#.....#");
	_input.push_back("##...##");
}
