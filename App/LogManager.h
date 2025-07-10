#pragma once
#include "stdafx.h"

#include <fstream>
#include <cmath>
#include <float.h>
#include "boost/math/special_functions/fpclassify.hpp"

#define isnan(x) _isnan(x) // readable code be like:

namespace RBX
{
	enum Severity
	{
		Information,
		Warning,
		Error
	};

	// sadly, this is just nothing
	class RBXBaseClass ILogProvider {};

	class Log
	{
	public:
		Log(char *LogFilename);
		~Log();

		void Log::timeStamp(std::ofstream &stream);
		std::string &Log::formatMem(std::string &returnStr, unsigned int memUsage);
		std::string &Log::formatTime(std::string &returnStr, double timeDouble);
		void Log::setLogProvider(ILogProvider *logProvider);
		void RBX::Log::writeEntry(Severity severity, char *message);

		Severity worstSeverity;
		std::string logFile;
		std::ofstream stream;
		ILogProvider *provider;
	};
}

class LogManager
{
private:
	RBX::Log *log;
public:
	LogManager();
	~LogManager();

	RBX::Log *LogManager::getLog();
};
