/*
 *	Saucer.cpp
 *
 *	Created on: Sep 17, 2013
 *		Author: Maxwell
 */

#include "Saucer.h"
#include "Event.h"
#include "Position.h"
#include "LogManager.h"
#include "GraphicsManager.h"
#include "EventStep.h"
#include "EventMouse.h"
#include "EventKeyboard.h"
#include "EventCollision.h"
#include "WorldManager.h"
#include "Sprite.h"
#include "ResourceManager.h"

Saucer::Saucer(int x, int y)
{
	Position a = Position (x,y);
	setPosition(a);
	setType("saucer");
	setSolidness(HARD);
	setXVelocity(0);
	setYVelocity(0);
	setAltitude(0);
	registerInterest("step");
	registerInterest("keyboard");
	registerInterest("mouse");
	ResourceManager &rm = ResourceManager::getInstance();
	Sprite *p_temp_sprite = rm.getSprite("bullet");

	LogManager &lm = LogManager::getInstance();
	if(!p_temp_sprite)
	{
		lm.writeLog("FILE NOT FOUND\n");
	}
	setSprite(p_temp_sprite);
	setSpriteSlowdown(0);
};
Saucer::~Saucer(){};
int Saucer::eventHandler(Event *p_e)
{
	LogManager &lm = LogManager::getInstance();
	WorldManager &wm = WorldManager::getInstance();
	if(p_e->getType() == "step")
	{
		return 0;
	}
	else if(p_e->getType() == "keyboard")
	{
		EventKeyboard *p_keyboard_event = static_cast <EventKeyboard *> (p_e);
		switch(p_keyboard_event->getKey())
		{
			case KEY_UP:
				wm.moveObject(this,Position(getPosition().getX(),
											getPosition().getY() - 1));
				break;
			case KEY_DOWN:
				wm.moveObject(this,Position(getPosition().getX(),
											getPosition().getY() + 1));
				break;
			case KEY_RIGHT:
				wm.moveObject(this,Position(getPosition().getX() + 1,
											getPosition().getY()));
				break;
			case KEY_LEFT:
				wm.moveObject(this,Position(getPosition().getX() - 1,
											getPosition().getY()));
				break;
			default:
				break;
		};
		return -1;
	}
	else if(p_e->getType() == "mouse")
	{
		EventMouse *p_mouse_event = static_cast <EventMouse *> (p_e);
		setPosition(Position(p_mouse_event->getMouseX(), p_mouse_event->getMouseY()));
		lm.writeLog("Saucer: Position Set: %d , %d. Mouse \n", p_mouse_event->getMouseX(),p_mouse_event->getMouseY());
		return 0;
	}
	else if(p_e->getType() == "collision")
	{
		EventCollision *p_collision_event = static_cast <EventCollision *> (p_e);
		lm.writeLog("Saucer: Collision: %s, %s, Position: %d, %d\n",
				p_collision_event->getObject1()->getType().c_str(),
				p_collision_event->getObject2()->getType().c_str(),
				p_collision_event->getPosition().getX(),
				p_collision_event->getPosition().getY());
		return 0;

	}
	else if(p_e->getType() == "out")
	{
		lm.writeLog("Saucer: Out Event Triggered\n");
	}
	return -1;
};
