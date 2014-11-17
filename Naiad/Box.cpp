/*
 *	Box.cpp
 *
 *	Created on: Oct 1, 2013
 *		Author: Maxwell
 */

#include "Box.h"
#include "LogManager.h"

//PRIVATE
//PROTECTED
//PUBLIC
Box::Box()
{
	corner = Position(0,0);
	horizontal = 0;
	vertical = 0;
};
Box::Box(Position init_corner, int init_horizontal, int init_vertical)
{
	corner = init_corner;
	horizontal = init_horizontal;
	vertical = init_vertical;
};
Position Box::getCorner()
{
	return corner;
};
void Box::setCorner(Position new_corner)
{
	corner = new_corner;
};
int Box::getHorizontal()
{
	return horizontal;
};
int Box::getVertical()
{
	return vertical;
};
void Box::setHorizontal(int new_horizontal)
{
	horizontal = new_horizontal;
};
void Box::setVertical(int new_vertical)
{
	vertical = new_vertical;
};
Box::~Box(){};
