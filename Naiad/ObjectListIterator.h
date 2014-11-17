/*
 *	ObjectListIterator.h
 *
 *	Created on: Sep 15, 2013
 *		Author: Maxwell
 */

#ifndef OBJECTLISTITERATOR_H_
#define OBJECTLISTITERATOR_H_

#include "Object.h"
#include "ObjectList.h"

class Object;
class ObjectList;

class ObjectListIterator
{
	private:
		ObjectListIterator();								//constructor
		int index;											//current index of iterator in list
		const ObjectList *p_list;							//pointer to list being analyzed
	protected:
	public:
		ObjectListIterator(const ObjectList *p_l);			//constructor given a list
		void first();										//sets index to 1
		void next();										//increases index
		bool isDone();										//returns true if value of index is the last non-null value in the list
		Object *currentObject();							//returns the current object, at list[index]
};

#endif /* OBJECTLISTITERATOR_H_ */
