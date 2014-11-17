/*
 *	LogManager.h
 *
 *	Created on: Sep 7, 2013
 *		Author: Maxwell
 */

#ifndef LOGMANAGER_H_
#define LOGMANAGER_H_

#include <stdio.h>
#include "Utility.h"
#include "Manager.h"
#include <string>
using std::string;

#define LOGFILE_Name "dragonfly.log"

class LogManager : public Manager
{
	private:
	/*Dragonfly Egg*/
		LogManager();						//a singleton LogManager
		LogManager(LogManager const&);		//copying is not allowed
		void operator=(LogManager const&);	//cannot be assigned to
		bool do_flush;						//determines whether or not fflush is called
		FILE *p_f;							//pointer to log file
	/*Dragonfly Naiad*/
	protected:
	/*Dragonfly Egg*/
	/*Dragonfly Naiad*/
	public:
	/*Dragonfly Egg*/
		~LogManager();
		//char *getTimeString();
			//returns a formatted string
		static LogManager &getInstance();
			//returs the singleton of LogManager
		int startUp(bool flush=false);
			//start up the LogManager and open the logfile
			//if flush == true, then call flush() after each write
		void shutDown();
			//shuts down the LogManager and closes the log file
		int writeLog(const char *fmt, ...);
			//write to logfile, supports printf()
			//return number of bytes written, returns -1 if error
		/*Dragonfly Naiad*/
			bool isValid(string event_name);
};

#endif /* LOGMANAGER_H_ */
