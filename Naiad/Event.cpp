/*
 *	Event.cpp
 *
 *	Created on: Sep 16, 2013
 *		Author: Maxwell
 */

#include "Event.h"

//PRIVATE
string event_type;
//PROTECTED
//PUBLIC
Event::Event(){};
Event::~Event(){};
void Event::setEventType(string new_type)
{
	event_type = new_type;
};
string Event::getType()
{
	return event_type;
};
