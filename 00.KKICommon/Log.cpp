#include "stdafx.h"
#include "Log.h"

//const string Log::_fileName = "kkolog.log";

// if do not below
// then when during compile exe this library included will occur link error
ofstream Log::_log;

Log::Log()
	: _fileName(""), _level(LogLevel::Debug)	
	, _pLevelName(nullptr)
{
	//_log.open(_fileName.c_str(), ios::out | ios::app);	
	_pLevelName = new unordered_map<LogLevel, string>{
					{LogLevel::Debug, "Debug"},
					{LogLevel::Info, "Info"},
					{ LogLevel::Warning, "Warning" },	
					{LogLevel::Error, "Error"} };
}

Log::~Log()
{
	if (_log.is_open()) {
		_log.close();
	}

	if (_pLevelName != nullptr)
		delete _pLevelName;
}

bool Log::Init(const string& path, const LogLevel& level)
{
	bool result = true;
	if (path.empty()) {
		result = false;
	}
	else {

		try {
			if (_log.is_open()) {
				_log.close();
			}

			_fileName = path;
			_level = level;

			_log.open(path.c_str(), ios::out | ios::app);
		}
		catch (exception ex) {
			result = false;
		}
	}
	return result;
}

//Log& Log::operator<<(const string& msg)
//{
//	_log << msg << endl;
//}
const string Log::GetLevel(const LogLevel& level) const {
	char buf[16];
	snprintf(buf, sizeof(buf)/sizeof(char), "[%s] : ", (*_pLevelName)[level].c_str());
	return buf;
}

const string Log::GetCurrTime() const
{
	time_t     now = time(NULL);
	struct tm  tstruct;
	char       buf[80];
	localtime_s(&tstruct, &now);
	strftime(buf, sizeof(buf), "[%Y-%m-%d.%X]", &tstruct);

	return buf;
}

void Log::Write(const LogLevel& level, const char* format, ...) const
{
	if (!_log.is_open() || _level < level)
		return;

	va_list args;
	va_start(args, format);

	int length = _vscprintf(format, args) + 1;
	char* msg = new char[length];
	vsprintf_s(msg, length, format, args);

	_log << GetCurrTime() << GetLevel(level) << msg << endl;

	delete[] msg;
}
