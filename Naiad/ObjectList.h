/*
 *	ObjectList.h
 *
 *	Created on: Sep 15, 2013
 *		Author: Maxwell
 */

#ifndef OBJECTLIST_H_
#define OBJECTLIST_H_

#define MAX_OBJECTS 5000

#include "Object.h"
#include "ObjectListIterator.h"

class Object;
class ObjectListIterator;

class ObjectList
{
	private:
		int count;										//stores the number of items in list
		Object *list[MAX_OBJECTS];						//an array to store all objects
	protected:
	public:
		ObjectList();									//objectlist constructor
		~ObjectList();									//objectlist destructor
		friend class ObjectListIterator;				//makes ObjectListIterator a friend class
		ObjectListIterator createIterator() const;		//creates an iterator
		int insert(Object *p_o);						//insterts a given object to the list
		int remove(Object *p_o);						//removes the given object from the list
		void clear();									//removes all object from the list
		int getCount();									//return count
		bool isEmpty();									//false if list is not empty, else true
		bool isFull();									//false if list is empty, else true
};

#endif /* OBJECTLIST_H_ */
