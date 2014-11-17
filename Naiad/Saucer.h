/*
 *	Saucer.h
 *
 *	Created on: Sep 17, 2013
 *		Author: Maxwell
 */

#ifndef SAUCER_H_
#define SAUCER_H_

#include "Object.h"
#include "Event.h"

class Saucer : public Object
{
	private:
	/*Dragonfly Naiad*/
		float x_velocity;
			//Horizontal speed/step
		float x_velocity_countdown;
			//Countdown until horizontal movement
		float y_velocity;
			//Vertical speed/step
		float y_velocity_countdown;
			//Countdown until vertical movement
	protected:
	public:
		Saucer();
		Saucer(int x,int y);
		virtual ~Saucer();
		int eventHandler(Event *p_e);
};

#endif /* SAUCER_H_ */
