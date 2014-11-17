/*
 *	Sprite.cpp
 *
 *	Created on: Sep 29, 2013
 *		Author: Maxwell
 */

#include "Sprite.h"
#include "GraphicsManager.h"
#include "LogManager.h"


//PRIVATE
//PROTECTED
//PUBLIC
Sprite::Sprite(){};
Sprite::~Sprite()
{
	if(frame != NULL)
	{
		delete [] frame;
	}
};
Sprite::Sprite(int max_frames)
{
	frame_count = 0;
	width = 0;
	height = 0;
	frame = new Frame[max_frames];
	max_frame_count = max_frames;
	color = COLOR_DEFAULT;
};
int Sprite::getWidth()
{
	return width;
};
int Sprite::getHeight()
{
	return height;
};
void Sprite::setWidth(int new_width)
{
	width = new_width;
};
void Sprite::setHeight(int new_height)
{
	height = new_height;
};
int Sprite::getColor()
{
	return color;
};
void Sprite::setColor(int new_color)
{
	color = new_color;
};
int Sprite::getFrameCount()
{
	return frame_count;
};
Frame Sprite::getFrame(int frame_number)
{
	LogManager &lm = LogManager::getInstance();
	if((frame_number < 0)||(frame_number >= frame_count))
	{
		Frame empty;
		lm.writeLog("Empty Frame\n");
		return empty;
	}
	return frame[frame_number];
};
int Sprite::addFrame(Frame new_frame)
{
	LogManager &lm = LogManager::getInstance();
	if(frame_count == max_frame_count)
	{
		lm.writeLog("Sprite is full, cannot add more frames\n");
		return -1;
	}
	else
	{
		frame[frame_count] = new_frame;
		frame_count += 1;
		return 0;
	}
};
string Sprite::getLabel()
{
	return label;
};
void Sprite::setLabel(string new_label)
{
	label = new_label;
};
