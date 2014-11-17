/*
 *	EventMouse.h
 *
 *	Created on: Sep 26, 2013
 *		Author: Maxwell
 */

#ifndef EVENTMOUSE_H_
#define EVENTMOUSE_H_

#include "Event.h"

#define MOUSE_EVENT "__mouse__"

enum MouseActionList
{
	LEFT_BUTTON_CLICK,
	LEFT_BUTTON_DOUBLECLICK,
	RIGHT_BUTTON_CLICK,
	RIGHT_BUTTON_DOUBLECLICK,
	UNDEFINED
};

class EventMouse : public Event
{
	private:
	/*Dragonfly Egg*/
	/*Dragonfly Naiad*/
	enum MouseActionList mouse_action;
	int mouse_x;
	int mouse_y;
	protected:
	/*Dragonfly Egg*/
	/*Dragonfly Naiad*/
	public:
	/*Dragonfly Egg*/
	/*Dragonfly Naiad*/
		EventMouse();
		virtual ~EventMouse();
		void setMouseAction(enum MouseActionList new_mouse_action);
			//Load mouse event action
		enum MouseActionList getMouseAction();
			//Return mouse's event action
		int getMouseX();
			//Set new mouseX
		int getMouseY();
			//Set new mouseY
		void setMouseX(int new_x);
			//Return mouseX
		void setMouseY(int new_y);
			//Return mouseY
};

#endif /* EVENTMOUSE_H_ */
