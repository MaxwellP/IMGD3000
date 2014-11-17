/*
 *	Object.cpp
 *
 *	Created on: Sep 15, 2013
 *		Author: Maxwell
 */

#include "Object.h"
#include "LogManager.h"
#include "GameManager.h"
#include "WorldManager.h"
#include "InputManager.h"
#include "GraphicsManager.h"

#include <math.h>

//PRIVATE
string type;
Position pos;
//PROTECTED
//PUBLIC
Object::Object()
{
	LogManager &lm = LogManager::getInstance();
	event_count = 0;
	WorldManager &wm = WorldManager::getInstance();
	wm.insertObject(this);
};
Object::~Object()
{
	WorldManager &wm = WorldManager::getInstance();
	wm.removeObject(this);
};
void Object::setType(string new_type)
{
	type = new_type;
};
void Object::setPosition(Position new_position)
{
	pos.setXY(new_position.getX(), new_position.getY());
};
int Object::eventHandler(Event *p_e)
{
	return 0;
};
string Object::getType()
{
	return type;
};
Position Object::getPosition()
{
	return pos;
};
int Object::registerInterest(string event)
{
	GameManager &gm = GameManager::getInstance();
	InputManager &im = InputManager::getInstance();
	LogManager &lm = LogManager::getInstance();

	if(event_count >= MAX_OBJ_EVENTS)
	{
		lm.writeLog("ERROR: TOO MANY EVENTS\n");
		return -1;
	};
	if(event == "step")
	{
		gm.registerEvent(this,"step");
	}
	else if(event == "mouse")
	{
		im.registerEvent(this,"mouse");
	}
	else if(event == "keyboard")
	{
		im.registerEvent(this,"keyboard");
	}
	else
	{
		WorldManager &wm = WorldManager::getInstance();
			wm.registerEvent(this,event);
	}
	event_name[event_count] = event;
	event_count += 1;
	return 0;
};
int Object::unregisterEvent(string event)
{
	bool found = false;
	for(int i = 0; i < event_count-1; i += 1)
	{
		if(event_name[i] == event)
		{
			found = true;
		}
	};
	if(!found)
	{
		return -1;
	};
	if(event == "string")
	{
		GameManager &gm = GameManager::getInstance();
		gm.unregisterInterest(this,event);
	}
	//else if(event == otherEventNames){see above}
	else
	{
		GameManager &gm = GameManager::getInstance();
		gm.unregisterInterest(this,event);
	};

	//SCOOT OVER ALL ITEMS IN EVENT_NAME

	event_count -= 1;
	return 0;
};
void Object::draw()
{
	int indx;
	indx = getSpriteIndex();
	GraphicsManager &gpm = GraphicsManager::getInstance();
	LogManager &lm = LogManager::getInstance();
	lm.writeLog("About to Draw Frame\n");
	gpm.drawFrame(pos,
				p_sprite->getFrame(indx),
				sprite_center,
				p_sprite->getColor());
	lm.writeLog("Frame Drawn\n");
	if(getSpriteSlowdown() == 0)
	{
		return;
	}
	int count;
	count = getSpriteSlowdown();
	count += 1;
	if(count >= getSpriteSlowdown())
	{
		count = 0;
		indx += 1;
		if(indx >= p_sprite->getFrameCount())
		{
			indx = 0;
		}
	}
	setSpriteSlowdown(count);
	setSpriteIndex(indx);

};
void Object::setXVelocity(float new_x_velocity)
{
	x_velocity = new_x_velocity;
};
float Object::getXVelocity()
{
	return x_velocity;
};
void Object::setYVelocity(float new_y_velocity)
{
	y_velocity = new_y_velocity;
};
float Object::getYVelocity()
{
	return x_velocity;
};
int Object::getXVelocityStep()
{
	if(x_velocity == 0)
	{
		return 0;
	}

	x_velocity_countdown -= fabs(x_velocity);

	if(x_velocity_countdown > 0)
	{
		return 0;
	};

	int spaces = floor(1 - x_velocity_countdown);
	x_velocity_countdown = 1 + fmod(x_velocity_countdown, 1);

	if(x_velocity > 0)
	{
		return spaces;
	}
	else
	{
		return -1 * spaces;
	}
};
int Object::getYVelocityStep()
{
	if(y_velocity == 0)
	{
		return 0;
	}

	y_velocity_countdown -= fabs(y_velocity);

	if(y_velocity_countdown > 0)
	{
		return 0;
	};

	int spaces = floor(1 - y_velocity_countdown);
	y_velocity_countdown = 1 + fmod(y_velocity_countdown, 1);

	if(y_velocity > 0)
	{
		return spaces;
	}
	else
	{
		return -1 * spaces;
	}
};
int Object::getAltitude()
{
	return altitude;
};
void Object::setAltitude(int new_altitude)
{
	altitude = new_altitude;
};
bool Object::isSolid()
{
	if(solidness == HARD || solidness == SOFT)
	{
		return true;
	}
	else
	{
		return false;
	}
};
int Object::setSolidness(Solidness new_solid)
{
	solidness = new_solid;
	return 0;
};
Solidness Object::getSolidness()
{
	return solidness;
};
void Object::setSprite(Sprite *p_new_sprite)
{
	p_sprite = p_new_sprite;
};
void Object::setSprite(Sprite *p_new_sprite, bool set_box)
{
	p_sprite = p_new_sprite;
	box = Box(Position(0,0), p_sprite->getWidth(), p_sprite->getHeight());
};
Sprite *Object::getSprite()
{
	return p_sprite;
};
void Object::setCentered(bool new_centered)
{
	sprite_center = new_centered;
};
bool Object::isCentered()
{
	return sprite_center;
};
void Object::setSpriteIndex(int new_sprite_index)
{
	sprite_index = new_sprite_index;
};
int Object::getSpriteIndex()
{
	return sprite_index;
};
void Object::setSpriteSlowdown(int new_sprite_slowdown)
{
	sprite_slowdown = new_sprite_slowdown;
};
int Object::getSpriteSlowdown()
{
	return sprite_slowdown;
};
void Object::setSpriteSlowdownCount(int new_count)
{
	sprite_slowdown_count = new_count;
};
int Object::getSpriteSlowdownCount()
{
	return sprite_slowdown_count;
};
void Object::setBox(Box new_box)
{
	box = new_box;
};
Box Object::getBox()
{
	return box;
};
