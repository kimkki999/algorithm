#include "stdafx.h"
#include "Elapse.h"

Elapse::Elapse()
{
	_start = clock();
}

Elapse::~Elapse()
{
}

void Elapse::Start() {
	_start = clock();
}

double Elapse::End() {
	_end = clock();
	return GetElapse(_start, _end);
}
