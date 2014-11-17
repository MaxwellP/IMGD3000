/*
 *	Wall.h
 *
 *	Created on: Sep 29, 2013
 *		Author: Maxwell
 */

#ifndef WALL_H_
#define WALL_H_

#include "Object.h"

class Wall : public Object
{
	private:
	protected:
	public:
		char c;
		Wall();
		virtual ~Wall();
		Wall(int x, int y, char c);
		void draw();
};

#endif /* WALL_H_ */
