/*
 *	Manager.h
 *
 *	Created on: Sep 7, 2013
 *		Author: Maxwell
 */

#ifndef MANAGER_H_
#define MANAGER_H_

#include "Event.h"
#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"
#include <string>
using std::string;

#define MAX_EVENTS 100

class Manager
{
	private:
	/*Dragonfly Egg*/
		int event_list_count;
			//# of events
	/*Dragonfly Naiad*/
		string event[MAX_EVENTS];
			//List of events
		ObjectList obj_list[MAX_EVENTS];
			//Objects interested in event
	protected:
	/*Dragonfly Egg*/
		bool started;
			//Set to true when properly started
	/*Dragonfly Naiad*/
	public:
	/*Dragonfly Egg*/
		Manager();
		virtual ~Manager();
		bool isStarted();
		virtual int startUp();
			//Startup Manager
			//Return 0 if okay, else return a negative number
		virtual void shutDown();
			//Shutdown Manager
	/*Dragonfly Naiad*/
		int registerEvent(Object *p_go, string event_name);
			//Indicate interest in event
			//Return 0 if ok, else -1
		int unregisterInterest(Object *p_go, string event_name);
			//Indicate no interest in event
			//Return 0 if ok, else -1
		void onEvent(Event *p_event);
			//Send event to all interested objects
		virtual bool isValid(string event_name);
			//if this event is allowed by the manager, return 1, else return 0
};

#endif /* MANAGER_H_ */
