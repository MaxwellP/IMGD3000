/*
 * GameManager.h
 *
 *  Created on: Sep 11, 2013
 *      Author: Maxwell
 */

#include <time.h>
#include <unistd.h>
#include "Manager.h"
#include "stdlib.h"

#define DEFAULT_FRAME_TIME 33

#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

class GameManager : public Manager
{
	private:
	/*Dragonfly Egg*/
		GameManager();
		GameManager (GameManager const&);
			//No copying allowed
		void operator = (GameManager const&);
			//No assignment
		bool game_over;
			//True, then game loop stops
		int frame_time;
			//Target time per game loop
		/*Dragonfly Naiad*/
	protected:
	/*Dragonfly Egg*/
	/*Dragonfly Naiad*/
	public:
	/*Dragonfly Egg*/
		virtual ~GameManager();
		static GameManager &getInstance();
			//Get the singleton instance of the GameManager
		int startUp();
			//Starts up all GameManager services
		int startUp(bool flush);
			//If flush is true, call fflush() after each write
		int startUp(bool flush, time_t seed);
		void shutDown();
			//Shut down all GameManager services
		void run(int fr_time=DEFAULT_FRAME_TIME);
			//Run the game loop
			//fr_time is time between frames
		void setGameOver(bool new_game_over=true);
			//Set game over status to indicated value
			//if true, stop game loop
		int getFrameTime();
			//Return frame time
			//Frame time is target time for game loop
	/*Dragonfly Naiad*/
		bool isValid(string event_name);
};

#endif /* GAMEMANAGER_H_ */
