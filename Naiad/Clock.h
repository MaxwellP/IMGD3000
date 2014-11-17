/*
 * Clock.h
 *
 *  Created on: Sep 11, 2013
 *      Author: Maxwell
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include <time.h>

class Clock
{
	private:
		struct timespec prev_ts;//Stores previous time delta() called
	protected:
	public:
		Clock();				//Sets prev_ts to current time
		virtual ~Clock();
		long int delta(void);	//Return time elapsed since delta() was last called
								//Units are microseconds
		long int split(void);	//Return time elapsed since delta was last called()
								//Units are microseconds
};

#endif /* CLOCK_H_ */
