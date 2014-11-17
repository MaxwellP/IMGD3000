/*
 *	GraphicsManager.h
 *
 *	Created on: Sep 25, 2013
 *		Author: Maxwell
 */

#ifndef GRAPHICSMANAGER_H_
#define GRAPHICSMANAGER_H_

#ifdef CYGWIN
#include <ncurses/curses.h>
#else
#include <curses.h>
#endif

#include "Manager.h"
#include "Position.h"
#include "Frame.h"
#include <string>
using std::string;

#define COLOR_DEFAULT COLOR_WHITE

enum Justification
{
	LEFT_JUSTIFIED,
	CENTER_JUSTIFIED,
	RIGHT_JUSTIFIED,
};

class GraphicsManager : public Manager
{
	private:
	/*Dragonfly Egg*/
	/*Dragonfly Naiad*/
		GraphicsManager();
		GraphicsManager(GraphicsManager const&);
		void operator = (GraphicsManager const&);
		WINDOW *buffer;

	protected:
	/*Dragonfly Egg*/
	/*Dragonfly Naiad*/

	public:
	/*Dragonfly Egg*/
		virtual ~GraphicsManager();
	/*Dragonfly Naiad*/
		static GraphicsManager &getInstance();
			//Get the singleton GraphicsManager
		int startUp();
			//Prepare terminal for text-based display
			//Return 0 if ok, else -1
		void shutDown();
			// return to normal terminal display
		int drawCh(Position world_pos, char ch, int color = COLOR_DEFAULT);
			//Draw character at provided location with given color (default is white)
			//Return 0 if successful, else -1
		int drawString(Position world_pos, string str, Justification just, int color = COLOR_DEFAULT);
			//Draw: string at given position with given color (otherwise default color
			//Justification: see enum at top
			//Return 0 if ok, else -1
		int getHorizontal();
			//Return width of display
		int getVertical();
			//Return height of display
		int swapBuffers();
			//Render current buffer
			//return 0 if successful, else -1
		WINDOW *getBuffer();
			//return the curses drawing window
		int drawFrame(Position world_pos, Frame frame, bool centered, int color);
			//Draw single sprite frame at screen posiiton, with color
			//If centered, then center frame at position
			//Return 0 if ok, else -1
};

#endif /* GRAPHICSMANAGER_H_ */
