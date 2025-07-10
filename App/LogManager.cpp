#include "stdafx.h"
#include "LogManager.h"

namespace RBX
{
	Log::Log(char *LogFilename)
	{
		this->worstSeverity = Information;
		this->logFile = LogFilename;

		this->stream.open(LogFilename, std::ios::out | std::ios::app);
		timeStamp(this->stream);
		this->stream << "Log \"" << LogFilename << "\"\n";
		this->stream.flush();
	}

	Log::~Log()
	{
		this->stream << "Log End\n";
		//delete this->stream;
		//delete this->logFile;
	}

	void Log::timeStamp(std::ofstream &stream) // there was a boolean but it was unused
	{
		SYSTEMTIME sysTime;
		char dateString[100];

		GetLocalTime(&sysTime);
		if (stream) // (char)stream != '\0'
		{
			sprintf(dateString, "%02u.%02u.%u ", sysTime.wDay, sysTime.wMonth, sysTime.wYear);
			stream << dateString;
		}
		sprintf(dateString, "%02u.%02u.%u ", sysTime.wHour, sysTime.wMinute, sysTime.wMilliseconds);
		stream << dateString;
		stream.flush();
	}

	std::string &Log::formatMem(std::string &returnStr, unsigned int memUsage)
	{
		char *sprintFormat;
		char memString[64];
	
		if (memUsage < 1000)
			sprintFormat = "%dB";
		else if (memUsage < 1000000) 
		{
			memUsage = memUsage / 1000;
			sprintFormat = "%dKB";
		}
		else if (memUsage < 1000000000) 
		{
			memUsage = memUsage / 1000000;
			sprintFormat = "%dMB";
		}
		else 
		{
			memUsage = memUsage / 1000000000;
			sprintFormat = "%dGB";
		}

		sprintf(memString, sprintFormat, memUsage, 0);
		returnStr.assign(memString);
		return returnStr;
	}

	std::string &Log::formatTime(std::string &returnStr, double timeDouble)
	{
		char *sprintFormat;
		char timeString[64];
	
		if (isnan(timeDouble))
			sprintf(timeString, "0s");

		if (0.0 <= timeDouble)
		{
			if (0.1 < timeDouble) // NAN(timeDouble) || 0.1 < timeDouble == (timeDouble == 0.1)
			{
				timeDouble = timeDouble * 1000.0;
				sprintFormat = "%.3gms";
			}
			else
				sprintFormat = "%.3gs";
		}
		else
			sprintFormat = "%.3gs";
			

		sprintf(timeString, sprintFormat, timeDouble);
		returnStr.assign(timeString);
		return returnStr;
	}

	void Log::setLogProvider(ILogProvider *logProvider)
	{
		// TODO: add the RCCService.exe version of the function
		// that version sends a request to a socket (some dump site?)
		// func: std::string *Log::setLogProvider(ILogProvider *logProvider)
		this->provider = logProvider;
	}

	void RBX::Log::writeEntry(Severity severity, char *message)
	{
		SYSTEMTIME sysTime;
		char timeString [256];

		GetLocalTime(&sysTime);
		sprintf(timeString, "%02u:%02u.%03u ", sysTime.wHour, sysTime.wMinute, sysTime.wMilliseconds);
		this->stream << timeString;
		this->stream.flush();

		if (severity != Information) {
			if (severity != Warning) {
				if (severity != Error) goto EndEntry;
				this->stream << Error;
			}
			this->stream << Warning;
		}
		this->stream << Information;

EndEntry:
		this->stream << message << std::endl;
		this->stream.flush();
	}
}


LogManager::LogManager()
{
	
}

LogManager::~LogManager()
{
	delete this->log;
}

RBX::Log *LogManager::getLog()
{
	this->log = new RBX::Log("Unknown.log"); // TODO: add the name here ig
	return this->log;
}