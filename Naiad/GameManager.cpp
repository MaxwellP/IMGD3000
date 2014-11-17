/*
 * GameManager.cpp
 *
 *  Created on: Sep 11, 2013
 *      Author: Maxwell
 */

#include "GameManager.h"
#include "GraphicsManager.h"
#include "LogManager.h"
#include "InputManager.h"
#include "WorldManager.h"
#include "Clock.h"
#include "EventStep.h"
#include "EventMouse.h"
#include "EventKeyboard.h"

//PRIVATE
GameManager::GameManager(){};
GameManager::GameManager(GameManager const&){};
bool game_over = false;
int frame_time = 33;
//PROTECTED
//PUBLIC
GameManager::~GameManager(){};
GameManager &GameManager::getInstance()
{
	static GameManager game_manager;
	return game_manager;
};
int GameManager::startUp()
{
	LogManager &lm = LogManager::getInstance();
	lm.writeLog("GameManager startUp() initiated\n");
	return 0;
};
int GameManager::startUp(bool flush)
{
	LogManager &lm = LogManager::getInstance();
	lm.writeLog("GameManager startUp() initiated\n");
	lm.startUp(flush);
	return 0;
};int GameManager::startUp(bool flush, time_t seed)
{
	LogManager &lm = LogManager::getInstance();
	lm.writeLog("GameManager startUp() initiated\n");
	srandom(seed);
	lm.startUp(flush);
	return 0;
};
void GameManager::shutDown()
{
	LogManager &lm = LogManager::getInstance();
	lm.writeLog("GameManager shutDown() initiated\n");
	lm.shutDown();
};
void GameManager::run(int fr_time)
{
	int loop_time;
	Clock clok;

	EventStep s;
	WorldManager &wm = WorldManager::getInstance();
	ObjectList all = wm.getAllObjects();
	ObjectListIterator oli(&all);

	GraphicsManager &gpm = GraphicsManager::getInstance();
	InputManager &im = InputManager::getInstance();
	LogManager &lm = LogManager::getInstance();

	while(!game_over)
	{
		clok.delta();

		onEvent(&s);
		im.getInput();

		wm.update();
		wm.draw();
		gpm.swapBuffers();

		loop_time = clok.split();
		usleep((fr_time - loop_time) * 1000);
	};
};
void GameManager::setGameOver(bool new_game_over)
{
	game_over = new_game_over;
};
int GameManager::getFrameTime()
{
	return frame_time;
};
bool GameManager::isValid(string event_name)
{
	if(event_name  == "step")
	{
		return true;
	}
	else
	{
		return false;
	}
};
