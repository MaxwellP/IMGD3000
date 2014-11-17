/*
 * Utility.h
 *
 *  Created on: Sep 14, 2013
 *      Author: Maxwell
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#include <stdio.h>
#include <time.h>
#include "Position.h"
#include "Box.h"

char *getTimeString();		//returns a properly formatted time string
bool pointsIntersect(Position p1, Position p2);
//bool boxIntersectsBox(Box a, Box b);

#endif /* UTILITY_H_ */
