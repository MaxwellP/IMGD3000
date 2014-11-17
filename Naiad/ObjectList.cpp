/*
 *	ObjectList.cpp
 *
 *	Created on: Sep 15, 2013
 *		Author: Maxwell
 */

#include "ObjectList.h"

//PRIVATE
int count;
Object *list[MAX_OBJECTS];
//PROTECTED
//PUBLIC
ObjectList::ObjectList()
{
	count = 0;
};
ObjectList::~ObjectList(){};
int ObjectList::insert(Object *p_o)
{
	if(count == MAX_OBJECTS)
	{
		return false;
	};
	list[count] = p_o;
	count += 1;
	return true;
};
int ObjectList::remove(Object *p_o)
{
	for(int i = 0; i < count; i += 1)
	{
		if(list[i] == p_o)
		{
			for(int j = i; j < count; j += 1)
			{
				list[j] = list[j+1];
				count -= 1;
				return 1;
			}
		}
	}
	return 0;
};
void ObjectList::clear()
{
	count = 0;
};
int ObjectList::getCount()
{
	return count;
};
bool ObjectList::isEmpty()
{
	if(count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
};
bool ObjectList::isFull()
{
	if(count == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
};
