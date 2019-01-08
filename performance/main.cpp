// performance.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <list>
#include "../00.KKICommon/Log.h"
#include "Performance.h"
#include "StlFunctionTest.h"
#include "Algorithm.h"
#include "Josephus.h"
#include "Brackets2.h"
#include "ITES.h"
#include "SoLong.h"
#include "Dictionary.h"
#include "CalcTime.h"
#include "Recursive.h"
#include "Greedy.h"
#include "Boggle.h"
#include "BoardCover.h"
#include "QuadTree.h"

int main()
{
	//logger set
	Logger->Init("test.log");
	Logger->Write(LogLevel::Info, "==============================");
	Logger->Write(LogLevel::Info, "==============================");
	Logger->Write(LogLevel::Info, "==  Program is going on!!!  ==");
	Logger->Write(LogLevel::Info, "==============================");
	Logger->Write(LogLevel::Info, "==============================");

	//Performance::Start();	
	//StlFunctionTest::Start();
	//Algorithm::Start();
	//list<Problem*> problems{ new Josephus(), new Brackets2(), new ITES(), new SoLong() };
	list<Problem*> problems{ //new SoLong(), new Dictionary(), new CalcTime(),
							//new Recursive(), new Greedy(), new CalcTime(),
							//new BoardCover()};
		new QuadTree() };
	
	for (auto val : problems) {
		//val->Input();
		val->TestInput();
		Elapse elp;
		val->Solve();
		val->Result();
		Logger->Write(Info, "solve&result elapse : %lf", elp.End());
	}

	for (auto val : problems) {
		delete val;
	}
}