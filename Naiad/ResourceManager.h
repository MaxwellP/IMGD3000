/*
 *	ResourceManager.h
 *
 *	Created on: Sep 29, 2013
 *	Author: Maxwell
 */

#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include "Manager.h"
#include "Sprite.h"
#include <string.h>
using std::string;

#define MAX_SPRITES 10000

/*SPRITE FILE DELIMETERS*/
#define FRAMES_TOKEN "frames"
#define HEIGHT_TOKEN "height"
#define WIDTH_TOKEN "width"
#define COLOR_TOKEN "color"
#define END_FRAME_TOKEN "end"
#define END_SPRITE_TOKEN "eof"

class ResourceManager : public Manager
{
	private:
		ResourceManager();
		ResourceManager(ResourceManager const&);
		void operator = (ResourceManager const&);
		Sprite *sprites[MAX_SPRITES];
			//Array of all sprites
		int sprite_count;
	protected:
	public:
		virtual ~ResourceManager();
		static ResourceManager &getInstance();
		int startUp();
			//Prepare manager for sprites
		void shutDown();
			//Shut down manager, free all sprite memory
		int loadSprite(string filename, string label);
			//Load sprite from file and assign label to sprite
			//Return 0 if ok, else -1
		int unloadSprite(string label);
			//Unload sprite with indicated label
			//Return 0 if ok, else -1
		Sprite *getSprite(string label);
			//Return sprite with indicated label
			//If not found, return NULL
};

#endif /* RESOURCEMANAGER_H_ */
