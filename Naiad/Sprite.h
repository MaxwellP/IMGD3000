/*
 *	Sprite.h
 *
 *	Created on: Sep 29, 2013
 *		Author: Maxwell
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include "Frame.h"
#include <string.h>
using std::string;

class Sprite
{
	private:
		int width;
		int height;
		int max_frame_count;
			//Maximum # of frames for given sprite
		int frame_count;
			//# of frames for sprite
		int color;
			//Optional color for entire sprite
		Frame *frame;
			//An array of frames
		string label;
			//Text to identify sprite
		Sprite();
	protected:
	public:
		virtual ~Sprite();
		Sprite(int max_frames);
			//Create sprite with given # of frames
		int getWidth();
			//Return value of width
		int getHeight();
			//Return value of height
		void setWidth(int new_width);
			//Set new value for width
		void setHeight(int new_height);
			//Set new value for height
		int getColor();
			//Return value of color
		void setColor(int new_color);
			//Set new value for color of sprite
		int getFrameCount();
			//Return value of frame_count
		Frame getFrame(int frame_number);
			//Return frame indicated by given number
			//Return empty frame if frame_number is out of range
		int addFrame(Frame new_frame);
			//Add frame to sprite
			//Return -1 if array is full, else 0
		string getLabel();
			//Return value of label
		void setLabel(string new_label);
			//Set new vale for label
};

#endif /* SPRITE_H_ */
