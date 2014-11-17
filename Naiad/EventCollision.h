/*
 *	EventColission.h
 *
 *	Created on: Sep 26, 2013
 *		Author: Maxwell
 */

#ifndef EVENTCOLLISION_H_
#define EVENTCOLLISION_H_

#include "Event.h"
#include "Object.h"
#include "Position.h"

#define COLLISION_EVENT "__collision__"

class EventCollision : public Event
{
	private:
		Position pos;
			//position of collision
		Object *p_obj1;
			//first object in collision
		Object *p_obj2;
			//second object in collision
	protected:
	public:
		EventCollision();
			//create collision event at 0,0 with obj1 and obj2 NULL
		virtual ~EventCollision();
		EventCollision(Object *p_o1, Object *p_o2, Position p);
		Object *getObject1();
		Object *getObject2();
		void setObject1(Object *p_new1);
		void setObject2(Object *p_new2);
		Position getPosition();
		void setPosition(Position new_pos);
};

#endif /* EVENTCOLLISION_H_ */
