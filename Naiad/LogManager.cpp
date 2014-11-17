/*
 * LogManager.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: Maxwell
 */

#include <stdarg.h>
#include <time.h>
#include <iostream>

//#include "Manager.h"
#include "LogManager.h"

//PRIVATE
LogManager::LogManager(){};
//PROTECTED
//PUBLIC
LogManager::~LogManager(){};
LogManager &LogManager::getInstance()
{
	static LogManager log_manager;
	return log_manager;
};
int LogManager::startUp(bool flush)
{
	p_f = fopen(LOGFILE_Name,"w");
	writeLog("LogManager startUp() initiated\n");
	if(flush)
	{
		do_flush = true;
		fflush(p_f);
	}
	return 1;
};
void LogManager::shutDown()
{
	LogManager &lm = LogManager::getInstance();
	lm.writeLog("LogManager shutDown() executed\n");
	fclose(p_f);
};
int LogManager::writeLog(const char *fmt, ...)
{
	p_f = fopen(LOGFILE_Name,"a");
	va_list args;
	va_start(args, fmt);
	fprintf(p_f, "%s   ",getTimeString());
	vfprintf(p_f, fmt, args);
	va_end(args);
	fclose(p_f);
	return 0;
};
bool LogManager::isValid(string event_name)
{
	if(event_name != "step")
	{
		return true;
	};
	return false;
};
