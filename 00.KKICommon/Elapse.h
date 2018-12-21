#pragma once

#include <ctime>

class Elapse
{
public:
	Elapse();
	~Elapse();
	
	void Start();
	double End();
private:
	clock_t _start;
	clock_t _end;

	double GetElapse(const clock_t& start, const clock_t& end) {
		// divide 1000 for conversion milli to sec
		return ((double)(end - start)/1000);
	}
};
