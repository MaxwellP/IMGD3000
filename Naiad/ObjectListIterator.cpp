/*
 *	ObjectListIterator.cpp
 *
 *	Created on: Sep 15, 2013
 *		Author: Maxwell
 */

#include "ObjectListIterator.h"

//PRIVATE
ObjectListIterator::ObjectListIterator()
{

};
//PROTECTED
//PUBLIC

ObjectListIterator::ObjectListIterator(const ObjectList *p_l)
{
	p_list = p_l;
	first();
};
void ObjectListIterator::first()
{
	index = 0;
};
bool ObjectListIterator::isDone()
{
	return index ==  (p_list -> count + 1);
};
void ObjectListIterator::next()
{
	index += 1;
};
Object *ObjectListIterator::currentObject()
{
	return p_list -> list[index];
};
