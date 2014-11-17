/*
 *	Event.h
 *
 *	Created on: Sep 16, 2013
 *		Author: Maxwell
 */

#ifndef EVENT_H_
#define EVENT_H_

#define UNDEFINED_EVENT "__undefined__"

#include <string>
using std::string;

class Event
{
	private:
		string event_type;					//stores the name of the event
	protected:
	public:
		Event();							//event constructor
		virtual ~Event();					//event destructor
		void setEventType(string new_type); //sets name of event
		string getType();					//returns the name of the event
};

#endif /* EVENT_H_ */
