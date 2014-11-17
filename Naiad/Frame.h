/*
 *	Frame.h
 *
 *	Created on: Sep 29, 2013
 *		Author: Maxwell
 */

#ifndef FRAME_H_
#define FRAME_H_

#include <string>
using std::string;

class Frame
{
	private:
		int width;
		int height;
		string frame_str;
	protected:
	public:
		Frame();
		virtual ~Frame();
		Frame(int new_width, int new_height, string frame_str);
		int getWidth();
			//Return value of width
		int getHeight();
			//Return value of height
		void setWidth(int new_width);
			//Set new value for width
		void setHeight(int new_height);
			//Set new value for height
		string getString();
			//Return value of frame_str
		void setFrame(string new_frame_str);
			//Set frame characters (stored as a string)
};

#endif /* FRAME_H_ */
