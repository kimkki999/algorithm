#pragma once

#include <random>
using namespace std;

class Random
{
public:
	Random();
	~Random();

	int getRandomNumber(int min, int max) {
		random_device rn;
		mt19937 rnd(rn());

		uniform_int_distribution<int> range(min, max);
		return range(rnd);
	}
};

