/*
 * Position.h
 *
 *  Created on: Sep 15, 2013
 *      Author: Maxwell
 */

#ifndef POSITION_H_
#define POSITION_H_

class Position
{
	private:
		int x;									//x position
		int y;									//y position
	protected:
	public:
		Position();								//constructor
		Position(int start_x, int start_y);		//constructor given 2 values
		virtual ~Position();					//destructor
		void setX(int new_x);					//sets x position
		void setY(int new_y);					//sets y position
		void setXY(int new_x, int new_y);		//sets x and y position
		int getX();								//returns x position
		int getY();								//returns y position
};

#endif /* POSITION_H_ */
