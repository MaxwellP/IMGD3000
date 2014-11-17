/*
 *	EventMouse.cpp
 *
 *	Created on: Sep 26, 2013
 *		Author: Maxwell
 */

#include "EventMouse.h"

//PRIVATE
//PROTECTED
//PUBLIC
EventMouse::EventMouse(){setEventType("mouse");};
EventMouse::~EventMouse(){};
void EventMouse::setMouseAction(enum MouseActionList new_mouse_action)
{
	mouse_action = new_mouse_action;
};
enum MouseActionList EventMouse::getMouseAction()
{
	return mouse_action;
};
int EventMouse::getMouseX()
{
	return mouse_x;
};
int EventMouse::getMouseY()
{
	return mouse_y;
};
void EventMouse::setMouseX(int new_x)
{
	mouse_x = new_x;
};
void EventMouse::setMouseY(int new_y)
{
	mouse_y = new_y;
};
