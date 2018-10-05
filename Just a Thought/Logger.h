#pragma once

#include <string>
#include <iostream>

class Logger
{
public:

	Logger() = delete;
	~Logger() = delete;

	enum logType
	{
		LOG_ERROR,
		LOG_DEBUG,
		LOG_INFO
	};

	static void log(const std::string& message, logType category);
	static inline void outputsToFile(bool outputsToFile) { m_fileOutput = outputsToFile; }
	static inline void setLogLevel(logType logLevel) {}

private:

	static bool m_fileOutput;
	static logType m_logLevel;

	static std::ostream* logData;
	static void outputLog();

};

