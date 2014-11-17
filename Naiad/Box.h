/*
 *	Box.h
 *
 *	Created on: Oct 1, 2013
 *		Author: Maxwell
 */

#ifndef BOX_H_
#define BOX_H_

#include "Position.h"

class Box
{
private:
	Position corner;
		//Upper left corner of box
	int horizontal;
		//Width of box
	int vertical;
		//Height of box
protected:
public:
	Box();
		//Creates a box with (0,0) for the corner and 0 for horizontal and vertical
	Box(Position init_corner, int init_horizontal, int init_vertical);
		//Creates a box with given values
	Position getCorner();
		//Returns value of corner
	void setCorner(Position new_corner);
		//Sets new value for the corner
	int getHorizontal();
		//Returns value of horizontal
	int getVertical();
		//Returns value of vertical
	void setHorizontal(int new_horizontal);
		//Sets new value for horizontal
	void setVertical(int new_vertical);
		//Sets new value for vertical
	virtual ~Box();
};

#endif /* BOX_H_ */
