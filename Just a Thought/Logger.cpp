#include "Logger.h"

bool Logger::m_fileOutput = false;
Logger::logType Logger::m_logLevel = Logger::LOG_ERROR;

void Logger::log(const std::string& message, Logger::logType category)
{

	outputLog();
}

void Logger::outputLog()
{

}
