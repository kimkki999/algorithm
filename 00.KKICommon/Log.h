#pragma once

#include <string>
#include <ctime>
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include "Singleton.h"

using namespace std;

enum LogLevel {
	Error,
	Warning,
	Info,
	Debug
};

class Log : public Singleton<Log>
{
public:	
	Log();
	virtual ~Log();	
	void Write(const LogLevel& level, const char* format, ...) const;
	bool Init(const string& path, const LogLevel& level = LogLevel::Debug);
	//void Output(const ofstream& val);

	//Log& operator<<(const string& msg);
private:	
	const string GetCurrTime() const;
	const string GetLevel(const LogLevel& level) const;

	static ofstream _log;
	string _fileName;
	LogLevel _level;
	unordered_map<LogLevel, string> *_pLevelName;
};

#define Logger Log::GetSingleton()
