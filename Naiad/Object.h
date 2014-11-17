/*
 *	Object.h
 *
 *	Created on: Sep 15, 2013
 *		Author: Maxwell
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include <string>
#include "Position.h"
#include "Event.h"
#include "Sprite.h"
#include "Box.h"
using std::string;

#define MAX_OBJ_EVENTS 100

enum Solidness
{
	HARD,
	SOFT,
	SPECTRAL,
};

class Object
{
	private:
	/*Dragonfly Egg*/
		string type;
			//stores the name of the type of object
		Position pos;
			//stores the position of the object
	/*Dragonfly Naiad*/
		float x_velocity;
			//Horizontal speed/step
		float x_velocity_countdown;
			//Countdown until horizontal movement
		float y_velocity;
			//Vertical speed/step
		float y_velocity_countdown;
			//Countdown until vertical movement
		int altitude;
			//0-MAX lower drawn first
		Solidness solidness;
			//Solidity of object
		Sprite *p_sprite;
			//Sprite associated with object
		bool sprite_center;
			//True if sprite is centered on screen
		int sprite_index;
			//Current frame index for sprite
		int sprite_slowdown;
			//Slwodown rate (1 = no slowdown, 0 = stop)
		int sprite_slowdown_count;
			//Slowdown counter
		Box box;
			//Box for sprite boundary and collisions
		int event_count;
	protected:
	/*Dragonfly Egg*/
	/*Dragonfly Naiad*/
	public:
	/*Dragonfly Egg*/
		Object();
			//object constructor
		virtual ~Object();
			//object destructor
		void setType(string new_type);
			//sets the type of object
		void setPosition(Position new_position);
			//sets the position of the object
		virtual int eventHandler(Event *p_e);
			//handles all events, such as step
		string getType();
			//returns the type of object
		Position getPosition();
			//returns the position of the object
	/*Dragonfly Naiad*/
		string event_name[MAX_OBJ_EVENTS];
		int registerInterest(string event);
			//register interest for the event
			//keep track of manager and event
			//return 0 if ok, else -1
		int unregisterEvent(string event);
			//unregister interest for event
			//return 0 if ok, else -1
		virtual void draw();
		void setXVelocity(float new_x_velocity);
			//Set new x velocity
		float getXVelocity();
			//Return x velocity
		void setYVelocity(float new_y_velocity);
			//Set new y velocity
		float getYVelocity();
			//Return y velocity
		int getXVelocityStep();
			//Perform 1 step of velocity in horizontal direction
			//Return horizontal distance moved this step
		int getYVelocityStep();
			//Perform 1 step of velocity in vertical direction
			//Return vertical distance moved this step
		int getAltitude();
			//Returns altitude
		void setAltitude(int new_altitude);
			//Set new altitude
		bool isSolid();
			//True if hard or soft, else false
		int setSolidness(Solidness new_solid);
			//Set solidity of object
			//Return 0 if ok, else -1
		Solidness getSolidness();
			//Return solidity of object
		void setSprite(Sprite *p_new_sprite);
			//Set sprite associated with object to new one
			//Set bounding box to size of sprite
		void setSprite(Sprite *p_new_sprite, bool set_box);
			//Set object sprite to new one
			//If set_box == true, set bounding box to size of Sprite
		Sprite *getSprite();
			//Return pointer to sprite associated with this object
		void setCentered(bool centered);
			//Set sprite to be centered at object position
		bool isCentered();
			//Indicates if sprite is centered at object position
		void setSpriteIndex(int new_sprite_index);
			//Sets new value for sprite_index
		int getSpriteIndex();
			//Returns value of sprite_index
		void setSpriteSlowdown(int new_sprite_slowdown);
			//Set new value for sprite_slowdown
		int getSpriteSlowdown();
			//Returns value for sprite_slowdown
		void setSpriteSlowdownCount(int new_count);
			//Set new value for sprite_slowdown_count
		int getSpriteSlowdownCount();
			//Returns value for sprite_slowdown_count
		void setBox(Box new_box);
			//Sets new value for box
		Box getBox();
			//Returns objects box
};

#endif /* OBJECT_H_ */
