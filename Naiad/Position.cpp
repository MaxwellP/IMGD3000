/*
 * Position.cpp
 *
 *  Created on: Sep 15, 2013
 *      Author: Maxwell
 */

#include "Position.h"

//PRIVATE
int x;
int y;
//PROTECTED
//PUBLIC
Position::Position()
{
	x = 0;
	y = 0;
};
Position::Position(int start_x, int start_y)
{
	x = start_x;
	y = start_y;
};
Position::~Position(){};
void Position::setX(int new_x)
{
	x = new_x;
};
void Position::setY(int new_y)
{
	y = new_y;
};
void Position::setXY(int new_x, int new_y)
{
	x = new_x;
	y = new_y;
};
int Position::getX()
{
	return x;
};
int Position::getY()
{
	return y;
};
