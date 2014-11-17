/*
 *	EventKeyboard.cpp
 *
 *	Created on: Sep 26, 2013
 *		Author: Maxwell
 */

#include "EventKeyboard.h"

//PRIVATE
//PROTECTED
//PUBLIC
EventKeyboard::EventKeyboard(){setEventType("keyboard");};
EventKeyboard::~EventKeyboard(){};
void EventKeyboard::setKey(int new_key)
{
	key_val = new_key;
};
int EventKeyboard::getKey()
{
	return key_val;
};
