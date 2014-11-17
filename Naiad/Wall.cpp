/*
 *	Wall.cpp
 *
 *	Created on: Sep 29, 2013
 *		Author: Maxwell
 */

#include "Wall.h"
#include "GraphicsManager.h"

//PRIVATE
//PROTECTED
//PUBLIC
Wall::Wall(){};
Wall::Wall(int x, int y, char cha)
{
	Position a = Position (x,y);
	setPosition(a);
	setType("wall");
	setSolidness(HARD);
	setXVelocity(0);
	setYVelocity(0);
	setAltitude(0);
	c = cha;
};
Wall::~Wall(){};
void Wall::draw()
{
	GraphicsManager &gpm = GraphicsManager::getInstance();
	gpm.drawCh(this->getPosition(),c,2);
};
