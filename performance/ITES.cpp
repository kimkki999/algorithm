#include "pch.h"
#include "ITES.h"
#include "../00.KKICommon/Random.h"
#include "../00.KKICommon/Log.h"
#include "../00.KKICommon/Elapse.h"

ITES::ITES()
	: Problem(), _input(), _result()
{
	Logger->Write(Debug, "%s", __func__);
}

ITES::~ITES()
{
	Logger->Write(Debug, "%s", __func__);

}

void ITES::Input() {
	
}

void ITES::Solve() {
	Logger->Write(Debug, "%s", __func__);

	Elapse elp;
	elp.Start();

	RNG rng;
	queue<int> range;
	for (const auto &input : _input) {
		int n = input.first;
		int k = input.second;
		int rangeSum = 0;
		int result = 0;

		for (int i = 0; i < n; i++) {
			int val = rng.next();
			rangeSum += val;
			range.push(val);

			while (rangeSum > k) {
				rangeSum -= range.front();
				range.pop();
			}

			if (rangeSum == k) result++;
		}

		_result.push_back(result);
	}
	Logger->Write(Info, "solve elapse : %lf", elp.End());
}

void ITES::Result() {
	for (const auto& val : _result) {
		cout << val << endl;
	}
}

void ITES::TestInput() {
	Random r;
	for (int i = 0; i < 20; i++) {
		_input.push_back(make_pair(r.getRandomNumber(1, 5000000), r.getRandomNumber(1, 5000000)));
	}
}