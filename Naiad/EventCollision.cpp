/*
 *	EventColission.cpp
 *
 *	Created on: Sep 26, 2013
 *		Author: Maxwell
 */

#include "EventCollision.h"

//PRIVATE
//PROTECTED
//PUBLIC
EventCollision::EventCollision(){setEventType("collision");};
EventCollision::~EventCollision(){};
EventCollision::EventCollision(Object *p_o1, Object *p_o2, Position p)
{
	p_obj1 = p_o1;
	p_obj2 = p_o2;
	pos = p;
	setEventType("collision");
};
Object *EventCollision::getObject1()
{
	return p_obj1;
};
Object *EventCollision::getObject2()
{
	return p_obj2;
};
void EventCollision::setObject1(Object *p_new1)
{
	p_obj1 = p_new1;
};
void EventCollision::setObject2(Object *p_new2)
{
	p_obj2 = p_new2;
};
Position EventCollision::getPosition()
{
	return pos;
};
void EventCollision::setPosition(Position new_pos)
{
	pos = new_pos;
};
