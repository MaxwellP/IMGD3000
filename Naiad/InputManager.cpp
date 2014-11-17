/*
 *	InputManager.cpp
 *
 *	Created on: Sep 26, 2013
 *		 Author: Maxwell
 */

#include "InputManager.h"
#include "GameManager.h"
#include "GraphicsManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "EventMouse.h"
#include "EventKeyboard.h"

//PRIVATE
InputManager::InputManager(){};
InputManager::InputManager(const InputManager&){};
//PROTECTED
//PUBLIC
InputManager::~InputManager(){};
InputManager &InputManager::getInstance()
{
	static InputManager input_manager;
	return input_manager;
};
int InputManager::startUp()
{
	LogManager &lm = LogManager::getInstance();
	GraphicsManager &gpm = GraphicsManager::getInstance();
	bool success = true;

	if(!gpm.isStarted())
	{
		lm.writeLog("InputManager startUp() failed, GraphicsManager is not started\n");
		return -1;
	};

	cbreak();
	nodelay(stdscr, TRUE);
	nonl();
	curs_set(0);
	noecho();
	mousemask(BUTTON1_CLICKED, NULL);
	keypad(stdscr, TRUE);

	if(success)
	{
		lm.writeLog("InputManager startUp() successful\n");
		started = true;
		return 0;
	}
	else
	{
		lm.writeLog("InputManager startUp() failed\n");
		return -1;
	}
};
void InputManager::shutDown()
{
	//REPORT SHUT DOWN TO LOGFILE
	started = false;
};
bool InputManager::isValid(string event_name)
{
	if(event_name == "keyboard" || event_name == "mouse")
	{
		return true;
	}
	else
	{
		return false;
	}
};
void InputManager::getInput()
{
	int c = getch();

	if(c != ERR)
	{
		MEVENT m_event;
		if(c == KEY_MOUSE && getmouse(&m_event) == OK)
		{
			if(m_event.bstate && BUTTON1_CLICKED)
			{
				EventMouse mouse_event;
				mouse_event.setMouseX(m_event.x);
				mouse_event.setMouseY(m_event.y);
				onEvent(&mouse_event);
			}
		}
		else
		{
			EventKeyboard key_event;
			key_event.setKey(c);
			onEvent(&key_event);
		}
	}
};
