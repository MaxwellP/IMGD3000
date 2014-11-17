/*
 * Utility.cpp
 *
 *  Created on: Sep 14, 2013
 *      Author: Maxwell
 */

#include "Utility.h"

char* getTimeString()
{
	static char time_str[30];
	time_t timer;
	time(&timer);
	struct tm *p_time = localtime(&timer);
	sprintf(time_str, "%02d:%02d:%02d",
			p_time -> tm_hour, p_time -> tm_min, p_time -> tm_sec);
	return time_str;
};
bool pointsIntersect(Position p1, Position p2)
{
	if(p1.getX() == p2.getX() && p1.getY() == p2.getY())
	{
		return true;
	}
	else
	{
		return false;
	}
};
/*
bool boxIntersectsBox(Box a, Box b)
{
	if(b.getCorner().getX() <= a.getCorner().getX() || a.getCorner().getX() <= b.getHorizontal())
	{

	}

};*/
