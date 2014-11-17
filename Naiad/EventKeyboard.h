/*
 *	EventKeyboard.h
 *
 *	Created on: Sep 26, 2013
 *		Author: Maxwell
 */

#ifndef EVENTKEYBOARD_H_
#define EVENTKEYBOARD_H_

#include "Event.h"

#define KEYBOARD_EVENT "__keyboard__"

class EventKeyboard : public Event
{
	private:
	/*Dragonfly Egg*/
	/*Dragonfly Naiad*/
		int key_val;
	protected:
	/*Dragonfly Egg*/
	/*Dragonfly Naiad*/
	public:
	/*Dragonfly Egg*/
		EventKeyboard();
		virtual ~EventKeyboard();
	/*Dragonfly Naiad*/
		void setKey(int new_key);
		int getKey();
};

#endif /* EVENTKEYBOARD_H_ */
