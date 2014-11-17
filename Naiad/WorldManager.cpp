/*
 *	WorldManager.cpp
 *
 *	Created on: Sep 17, 2013
 *		Author: Maxwell
 */

#include "WorldManager.h"
#include "LogManager.h"
#include "EventCollision.h"
#include "GraphicsManager.h"
#include "EventOut.h"

//PRIVATE
WorldManager::WorldManager(){};
WorldManager::WorldManager(WorldManager const&){};
ObjectList updates;
ObjectList deletions;
//PROTECTED
//PUBLIC
WorldManager::~WorldManager(){};
int WorldManager::startUp()
{
	LogManager &lm = LogManager::getInstance();
	lm.writeLog("WorldManager startUp() initiated\n");
	started = true;
	return 0;
};
int WorldManager::insertObject(Object *p_o)
{
	LogManager &lm = LogManager::getInstance();
	updates.insert(p_o);
	return 0;
};
int WorldManager::removeObject(Object *p_o)
{
	deletions.remove(p_o);
	return 0;
};
ObjectList WorldManager::getAllObjects(void)
{
	return updates;
};
void WorldManager::update()
{
	ObjectListIterator oli(&deletions);
	while(!oli.isDone())
	{
		//delete the current object
		if(oli.currentObject() != NULL)
		{
			markForDeletion(oli.currentObject());
		}
		oli.next();
	}
	deletions.clear();
	ObjectListIterator olu(&updates);
	while(!olu.isDone())
	{
		if(olu.currentObject() != NULL)
		{
			int x = olu.currentObject()->getXVelocityStep();
			int y = olu.currentObject()->getYVelocityStep();

			if(x != 0 || y != 0)
			{
				Position oldPos = olu.currentObject()->getPosition();
				Position newPos;
				newPos.setXY(oldPos.getX() + x, oldPos.getY() + y);
				moveObject(olu.currentObject(), newPos);
			}
		}
		olu.next();
	}

};
int WorldManager::markForDeletion(Object *p_o)
{
	ObjectListIterator oli(&deletions);
	while(!oli.isDone())
	{
		if(oli.currentObject() == p_o)
		{
			return 0;
		}
		oli.next();
	}
	deletions.insert(p_o);
	return 0;
};
WorldManager &WorldManager::getInstance()
{
	static WorldManager world_manager;
	return world_manager;
};
bool WorldManager::isValid(string event_name)
{
	if(event_name != "step")
	{
		return true;
	}
	return false;
};
void WorldManager::draw()
{
	LogManager &lm = LogManager::getInstance();
	ObjectListIterator oli(&updates);

	for(int i = 0; i < MAX_ALTITUDE; i += 1)
	{
		while(!oli.isDone())
		{
			if(oli.currentObject() != NULL)
			{
				if(oli.currentObject()->getAltitude() == i)
				{
					oli.currentObject()->draw();
				}
			}
			oli.next();
		};
	}
};
ObjectList WorldManager::isCollision(Object *p_o, Position where)
{
	ObjectList collisions;
	ObjectListIterator oli(&updates);

	while(!oli.isDone())
	{
		if(oli.currentObject() != NULL)
		{
			Object *p_temp_o = oli.currentObject();
			if(p_temp_o != p_o)
			{
				if(pointsIntersect(p_temp_o->getPosition(), where) && p_temp_o->isSolid())
				{
					if(p_temp_o != NULL)
					{
						collisions.insert(p_temp_o);
					}
				}
			}
		}
		oli.next();
	}
	return collisions;
};
int WorldManager::moveObject(Object *p_o, Position where)
{
	GraphicsManager &gm = GraphicsManager::getInstance();
	bool do_move = true;
	if(p_o->isSolid())
	{
		ObjectList list = isCollision(p_o, where);
		if(!list.isEmpty())
		{
			ObjectListIterator oli(&list);
			while(!oli.isDone())
			{
				if(oli.currentObject() != NULL)
				{
					Object *p_temp_o = oli.currentObject();

					EventCollision c(p_o,p_temp_o, where);

					p_o->eventHandler(&c);
					p_temp_o->eventHandler(&c);

					if(p_o->getSolidness() == HARD && p_temp_o->getSolidness() == HARD)
					{
						do_move = false;
					}
				}
				oli.next();
			}
			if(do_move == false)
			{
				return -1;
			}
		}
	}
	p_o->setPosition(where);

	if((where.getX() < 0 || where.getX() > gm.getHorizontal()) ||
	   (where.getY() < 0 || where.getY() > gm.getVertical()))
	{
		EventOut o;
		p_o->eventHandler(&o);
	}

	return 0;
};
