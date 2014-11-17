/*
 * Clock.cpp
 *
 *  Created on: Sep 11, 2013
 *      Author: Maxwell
 */

#include "Clock.h"

//PRIVATE
struct timespec prev_ts;
//PROTECTED
//PUBLIC
Clock::Clock()
{
	clock_gettime(CLOCK_REALTIME, &prev_ts);
};
Clock::~Clock(){};
long int Clock::delta()
{
	struct timespec current_ts;
	clock_gettime(CLOCK_REALTIME, &current_ts);
	long int before_msec, after_msec;

	before_msec	=	prev_ts.tv_sec*1000		+ prev_ts.tv_nsec/1000000;
	after_msec	=	current_ts.tv_sec*1000	+ current_ts.tv_nsec/1000000;

	prev_ts = current_ts;
	return (after_msec - before_msec);
};
long int Clock::split()
{
	struct timespec current_ts;
	clock_gettime(CLOCK_REALTIME, &current_ts);
	long int before_msec, after_msec;

	before_msec	=	prev_ts.tv_sec*1000		+ prev_ts.tv_nsec/1000000;
	after_msec	=	current_ts.tv_sec*1000	+ current_ts.tv_nsec/1000000;

	return (after_msec - before_msec);
};
