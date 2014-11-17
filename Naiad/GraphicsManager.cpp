/*
 *	GraphicsManager.cpp
 *
 *	Created on: Sep 25, 2013
 *		Author: Maxwell
 */

#include "GraphicsManager.h"
#include "LogManager.h"

//PRIVATE
GraphicsManager::GraphicsManager(){};
//PROTECTED
//PUBLIC
GraphicsManager::~GraphicsManager(){};
GraphicsManager &GraphicsManager::getInstance()
{
	static GraphicsManager graphics_manager;
	return graphics_manager;
};
int GraphicsManager::startUp()
{
	LogManager &lm = LogManager::getInstance();
	lm.writeLog("Graphics Manager startUp() initiated\n");
	bool success = false;
	initscr();
	buffer = newwin(0,0,0,0);
	int max_y, max_x;
	getmaxyx(stdscr, max_y, max_x);
	clearok(stdscr, TRUE);
	leaveok(stdscr, TRUE);
	clearok(buffer, TRUE);
	leaveok(buffer, TRUE);

	if(has_colors())
	{
		start_color();
		init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
		init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
		init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
		init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
		init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
		init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);
		init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
		success = true;
	};

	wattron(buffer, A_BOLD);

	if(success)
	{
		lm.writeLog("Graphics Manager startUp() successful\n");
		started = true;
		return 0;
	}
	else
	{
		lm.writeLog("Graphics Manager startUp() failed\n");
		return -1;
	}
	return 0;
};
void GraphicsManager::shutDown()
{
	LogManager &lm = LogManager::getInstance();
	lm.writeLog("Graphics Manager shutDown() initiated\n");
	endwin();
};
int GraphicsManager::drawCh(Position world_pos, char ch, int color)
{
	wattron(buffer,COLOR_PAIR(color));
	mvwaddch(buffer, world_pos.getY(), world_pos.getX(), ch);
	//mvwaddstr(buffer, world_pos.getY(), world_pos.getX(), &ch);
	wattroff(buffer, COLOR_PAIR(color));
	return 0;
};
int GraphicsManager::drawString(Position world_pos, string str, Justification just, int color)
{
	Position starting_pos = world_pos;
	switch(just)
	{
	case(LEFT_JUSTIFIED):
		break;
	case(CENTER_JUSTIFIED):
		starting_pos.setX(world_pos.getX() - str.size() / 2);
		break;
	case(RIGHT_JUSTIFIED):
		starting_pos.setX(world_pos.getX() - str.size());
		break;
	default:
		break;
	};
	for(int i = 0; i < str.size(); i += 1)
	{
		Position temp_pos(starting_pos.getX() + i, starting_pos.getY());
		drawCh(temp_pos,str[i], color);
	};
	return 0;
};

int GraphicsManager::getHorizontal()
{
	int max_y, max_x;
	getmaxyx(stdscr, max_y, max_x);
	return max_x;
};
int GraphicsManager::getVertical()
{
	int max_y, max_x;
	getmaxyx(stdscr, max_y, max_x);
	return max_y;
};
int GraphicsManager::swapBuffers()
{
	wrefresh(buffer);
	werase(buffer);
	return 0;
};
WINDOW *GraphicsManager::getBuffer()
{
	return buffer;
};
int GraphicsManager::drawFrame(Position world_pos, Frame frame, bool centered, int color)
{
	int x_offset, y_offset;
	if(frame.getString().empty() == -1)
	{
		//error, empty frame
		return -1;
	}
	if(centered)
	{
		x_offset = frame.getWidth() / 2;
		y_offset = frame.getHeight() / 2;
	}
	else
	{
		x_offset = 0;
		y_offset = 0;
	}
	string str = frame.getString();
	for(int y = 0;  y <= frame.getHeight(); y += 1)
	{
		for(int x = 0; x <= frame.getWidth(); x += 1)
		{
			Position temp_pos(world_pos.getX() - x_offset + x,
							  world_pos.getY() - y_offset + y);
			drawCh(temp_pos, str[y * frame.getWidth() + x], color);
		}
	}
	return 0;
};
