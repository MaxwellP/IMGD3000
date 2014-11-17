/*
 *	WorldManager.h
 *
 *	Created on: Sep 17, 2013
 *		Author: Maxwell
 */

#ifndef WORLDMANAGER_H_
#define WORLDMANAGER_H_

#include "Manager.h"
#include "ObjectList.h"
#include "Utility.h"

#define MAX_ALTITUDE 4

class WorldManager : public Manager
{
	private:
	/*Dragonfly Egg*/
		WorldManager();								//constructor
		WorldManager(WorldManager const&);			//prevents copying
		void operator=(WorldManager const&);		//cannot be assigned to
		ObjectList updates;							// stores all objects
		ObjectList deletions;						//stores all objets to be deleted
	/*Dragonfly Naiad*/
	protected:
	/*Dragonfly Egg*/
	/*Dragonfly Naiad*/
	public:
	/*Dragonfly Egg*/
		virtual ~WorldManager();					//destructor
		int startUp();								//start up worldmanager and tell dragonfly.log
		int insertObject(Object *p_o);				//inserts given object into the world
		int removeObject(Object *p_o);				//removes given object from the world
		ObjectList getAllObjects(void);				//returns list containing all world objects
		void update();								//updates game state
		int markForDeletion(Object *p_o);			//puts object to be deleted into deletions
		static WorldManager &getInstance();			//returns singleton of worldmanager
	/*Dragonfly Naiad*/
		bool isValid(string event_name);
		void draw();
		ObjectList isCollision(Object *p_o, Position where);
			//Return list of object colliding at position
			//Collision only with solid objects
			//Does not consider if p_o is solid or not
		int moveObject(Object *p_o, Position where);
			//If no collision with solid, move ok, else dont move
			//If p_o is spectral, move ok
			//Return 0 if move ok, else -1 if collision with solid
};

#endif /* WORLDMANAGER_H_ */
