/*
 * ResourceManager.cpp
 *
 *  Created on: Sep 29, 2013
 *      Author: Maxwell
 */

#include "ResourceManager.h"
#include "LogManager.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <stdlib.h>

using std::string;
using std::ifstream;
using std::endl;

//PRIVATE
ResourceManager::ResourceManager(){};
//PROTECTED
//PUBLIC
void discardCR(string &str)
{
	if(str[str.size() -1] == '\r')
	{
		str.erase(str.size() - 1);
	}
};
int readLineInt(ifstream *p_file, int *p_line_number, const char *tag)
{
	string line;
	getline(*p_file,line);
	discardCR(line);

	if(!line.compare(0, strlen(tag) + 1, tag))
	{
		//INCORRECT TAG
		return -1;
	}

	if(tag == COLOR_TOKEN)
	{
		string mysub = line.substr(strlen(tag) +1);
		if(mysub == "red")
		{
			(*p_line_number) += 1;
			return 0;
		}
		else if(mysub == "green")
		{
			(*p_line_number) += 1;
			return 1;
		}
		else if(mysub == "yellow")
		{
			(*p_line_number) += 1;
			return 2;
		}
		else if(mysub == "blue")
		{
			(*p_line_number) += 1;
			return 3;
		}
		else if(mysub == "magenta")
		{
			(*p_line_number) += 1;
			return 4;
		}
		else if(mysub == "cyan")
		{
			(*p_line_number) += 1;
			return 5;
		}
		else if(mysub == "white")
		{
			(*p_line_number) += 1;
			return 6;
		}
		else
		{
			(*p_line_number) += 1;
			//ERROR COLOR UNKNOWN
			return -1;
		}
	};

	int number = atoi(line.substr(strlen(tag) + 1).c_str());
	(*p_line_number) += 1;
	return number;
};
Frame readFrame(ifstream *p_file, int *p_line_number, int width, int height)
{
	LogManager &lm = LogManager::getInstance();
	string line, frame_str;
	Frame empty;

	for(int i = 0; i < height; i += 1)
	{
		getline(*p_file, line);
		discardCR(line);
		if(line.length() > width)
		{
			lm.writeLog("Sprite size is incorrect\n");
			return empty;
		}
		frame_str += line;
	}

	getline(*p_file,line);

	if(line == "end")
	{
		lm.writeLog("Line == end\n");
		return empty;
	}

	Frame myFrame = Frame(width, height, frame_str);
	(*p_line_number) += 1;

	return myFrame;
};
ResourceManager::~ResourceManager(){};
ResourceManager &ResourceManager::getInstance()
{
	static ResourceManager resource_manager;
	return resource_manager;
};
int ResourceManager::startUp()
{
	LogManager &lm = LogManager::getInstance();
	lm.writeLog("ResoruceManager startUp() initiated\n");
	started = true;
	sprite_count = 0;
	return 0;
};
void ResourceManager::shutDown()
{
	//DELETE ALL SPRITES
	started = false;
};
int ResourceManager::loadSprite(string filename, string label)
{
	LogManager &lm = LogManager::getInstance();
	ifstream myFile (filename.c_str());
	int lineNum = 0;
	int frames, width, height, color;

	if(myFile.is_open())
	{
		frames = readLineInt(&myFile, &lineNum, FRAMES_TOKEN);
		width = readLineInt(&myFile, &lineNum, WIDTH_TOKEN);
		height = readLineInt(&myFile, &lineNum, HEIGHT_TOKEN);
		color = readLineInt(&myFile, &lineNum, COLOR_TOKEN);

		Sprite *newSprite = new Sprite (frames);

		while(myFile.good())
		{
			Frame myFrame = readFrame(&myFile, &lineNum, width, height);
			newSprite->addFrame(myFrame);
		}
		myFile.close();
		newSprite->setWidth(width);
		newSprite->setHeight(height);
		newSprite->setColor(color);
		newSprite->setLabel(label);
		sprites[sprite_count] = newSprite;
		sprite_count += 1;
		lm.writeLog("HERE IS WEIRD %s\n",sprites[sprite_count-1]->getFrame(0).getString().c_str());
		return 0;
	}
	else
	{
		lm.writeLog("File %s Not Found\n", filename.c_str());
		return -1;
	}
};
int ResourceManager::unloadSprite(string label)
{
	for(int i = 0; i < sprite_count; i += 1)
	{
		if(label == sprites[i]->getLabel())
		{
			delete sprites[i];
			for(int j = i; j < sprite_count; j += 1)
			{
				sprites[j] = sprites[j+1];
			}
			sprite_count -= 1;
			return 0;
		}
	}
	//ERROR
	return -1;
};
Sprite *ResourceManager::getSprite(string label)
{
	for(int i = 0; i < sprite_count; i += 1)
	{
		if(label == sprites[i]->getLabel())
		{
			return sprites[i];
		}
	}
	return NULL;
};
