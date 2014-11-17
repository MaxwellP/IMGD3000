/*
 *	EventStep.h
 *
 *	Created on: Sep 16, 2013
 *		Author: Maxwell
 */

#ifndef EVENTSTEP_H_
#define EVENTSTEP_H_

#include "Event.h"

#define STEP_EVENT "__step__"

class EventStep : public Event
{
	private:
	protected:
	public:
		EventStep();
		virtual ~EventStep();
};

#endif /* EVENTSTEP_H_ */
