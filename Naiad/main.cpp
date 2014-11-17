/*
 *	main.cpp
 *
 *	Created on: Sep 11, 2013
 *		Author: Maxwell
 */

#include "GameManager.h"
#include "GraphicsManager.h"
#include "InputManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "ResourceManager.h"

#include "Clock.h"
#include "Object.h"
#include "ObjectList.h"
#include "Position.h"
#include "Utility.h"

#include "Saucer.h"
#include "Wall.h"

int main()
{
	GameManager &gm = GameManager::getInstance();
	gm.startUp();
	LogManager &lm = LogManager::getInstance();
	lm.startUp(true);
	WorldManager &wm = WorldManager::getInstance();
	wm.startUp();
	GraphicsManager &gpm = GraphicsManager::getInstance();
	gpm.startUp();
	InputManager &im = InputManager::getInstance();
	im.startUp();
	ResourceManager &rm = ResourceManager::getInstance();
	rm.startUp();

	rm.loadSprite("sprites/bullet-spr.txt","bullet");

	Saucer *s = new Saucer(3,9);
	Wall *w1 = new Wall(10,5,'-');
	Wall *w2 = new Wall(11,5,'-');
	Wall *w3 = new Wall(12,5,'-');
	Wall *w4 = new Wall(13,5,'-');
	Wall *w5 = new Wall(14,5,'-');
	Wall *w6 = new Wall(15,5,'-');
	Wall *w7 = new Wall(10,10,'-');
	Wall *w8 = new Wall(11,10,'-');
	Wall *w9 = new Wall(12,10,'-');
	Wall *w10 = new Wall(13,10,'-');
	Wall *w11 = new Wall(14,10,'-');
	Wall *w12 = new Wall(15,10,'-');
	Wall *w13 = new Wall(10,6,'|');
	Wall *w14 = new Wall(10,7,'|');
	Wall *w15 = new Wall(10,8,'|');
	Wall *w16 = new Wall(10,9,'|');
	Wall *w18 = new Wall(15,6,'|');
	Wall *w19 = new Wall(15,7,'|');
	Wall *w20 = new Wall(15,8,'|');
	Wall *w21 = new Wall(15,9,'|');

	gm.run(33);

	im.shutDown();
	gpm.shutDown();
	wm.shutDown();
	lm.shutDown();
	gm.shutDown();
	return 1;
};
