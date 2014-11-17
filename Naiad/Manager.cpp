/*
 *	Manager.cpp
 *
 *	Created on: Sep 7, 2013
 *		Author: Maxwell
 */

#include "Manager.h"
#include "LogManager.h"

Manager::Manager()
{
	started = false;
	event_list_count = 0;
};
Manager::~Manager()
{
};
bool Manager::isStarted()
{
	return started;
};
int Manager::startUp()
{
	//started = true;
	return 1;
};
void Manager::shutDown(){};
int Manager::registerEvent(Object *p_go, string event_name)
{
	LogManager &lm = LogManager::getInstance();
	if(!isValid(event_name))
	{
		lm.writeLog("INVALID EVENT NAME: %s\n", event_name.c_str());
		return -1;
	};
	for(int i = 0; i <= event_list_count -1 ; i += 1)
	{
		if(event[i] == event_name)
		{
			obj_list[i].insert(p_go);
		}
	};
	if(event_list_count >= MAX_EVENTS)
	{
		//ERROR LIST IS FULL
		return -1;
	};
	event[event_list_count] = event_name;
	obj_list[event_list_count].insert(p_go);
	event_list_count += 1;
	return 0;
};
int Manager::unregisterInterest(Object *p_go, string event_name)
{
	for(int i = 0; i <= event_list_count - 1; i += 1)
	{
		if(event[i] == event_name)
		{
			obj_list[i].remove(p_go);
			return 0;
		}

		if(obj_list[i].isEmpty())
		{
			for(int j = i; j < MAX_EVENTS; j += 1)
			{
				obj_list[j] = obj_list[j+1];
				event[j] = event[j+1];
			}
			event_list_count -= 1;
			return -1;
		}
	};
	return -1;
};
void Manager::onEvent(Event *p_event)
{
	for(int i = 0; i < event_list_count; i += 1)
	{
		if(event[i] == p_event->getType())
		{
			ObjectListIterator list(&obj_list[i]);
			while(!list.isDone())
			{
				if(list.currentObject() != NULL)
				{
					list.currentObject()->eventHandler(p_event);
				}
				list.next();
			}
		}
	};
};
bool Manager::isValid(string event_name)
{
	return false;
};
