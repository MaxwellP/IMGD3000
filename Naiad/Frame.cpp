/*
 *	Frame.cpp
 *
 *	Created on: Sep 29, 2013
 *		Author: Maxwell
 */

#include "Frame.h"

//PRIVATE
//PROTECTED
//PUBLIC
Frame::Frame(){};
Frame::~Frame(){};
Frame::Frame(int new_width, int new_height, string new_frame_str)
{
	width = new_width;
	height = new_height;
	frame_str = new_frame_str;
};
int Frame::getWidth()
{
	return width;
};
int Frame::getHeight()
{
	return height;
};
void Frame::setWidth(int new_width)
{
	width = new_width;
};
void Frame::setHeight(int new_height)
{
	height = new_height;
};
string Frame::getString()
{
	return frame_str;
};
void Frame::setFrame(string new_frame_str)
{
	frame_str = new_frame_str;
};
