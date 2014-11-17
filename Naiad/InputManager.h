/*
 *	InputManager.h
 *
 *	Created on: Sep 26, 2013
 *		 Author: Maxwell
 */

#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include "Manager.h"
#include <string.h>
using std::string;

class InputManager : public Manager
{
	private:
	/*Dragonfly Egg*/
	/*Dragonfly Naiad*/
		InputManager();
		InputManager (InputManager const&);
		void operator = (InputManager const&);
	protected:
	/*Dragonfly Egg*/
	/*Dragonfly Naiad*/
	public:
	/*Dragonfly Egg*/
		virtual ~InputManager();
	/*Dragonfly Naiad*/
		static InputManager &getInstance();
			//Singleton of InputManager
		int startUp();
			//Prepare terminal for input
			//Return 0 if ok, else -1
		void shutDown();
			//Revert back to normal terminal mode
		bool isValid(string event_name);
			//Input manager only accepts keyboard and mouse events
			//Return false if not that type of event
		void getInput();
			//Get keyboard and mouse input
			//For each object interested, pass events along
};

#endif /* INPUTMANAGER_H_ */
