/*
 *	EventOut.h
 *
 *	Created on: Sep 29, 2013
 *		Author: Maxwell
 */

#ifndef EVENTOUT_H_
#define EVENTOUT_H_

#include "Event.h"

#define OUT_EVENT "__out__"

class EventOut : public Event
{
	private:
	protected:
	public:
		EventOut();
		virtual ~EventOut();
};

#endif /* EVENTOUT_H_ */
