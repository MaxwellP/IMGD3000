/*
 * EventView.h
 *
 *  Created on: Oct 1, 2013
 *      Author: Maxwell
 */

#ifndef EVENTVIEW_H_
#define EVENTVIEW_H_

#include "Event.h"
#include <string>
using std::string;

#define VIEW_EVENT "__view__"

class EventView : public Event
{
	private:
		string tag;
			//Tag to associate
		int value;
			//Value for view
		bool delta;
			//True if change in value, else false
	protected:
	public:
		EventView();
			//Create view event, with tag VIEW_EVEMT, value = 0, delta = false
		virtual ~EventView();
		EventView(string new_tag, int new_value, bool new_delta);
			//Create view event with given tag, value, and delta
		void setTag(string new_tag);
			//Set new value for tag
		string getTag();
			//Return value of tag
		void setValue (int new_value);
			//Set new value for value
		int getValue();
			//Return value of value
		void setDelta(bool new_delta);
			//Set new value for delta
		bool getDelta();
			//Return value of delta`
};

#endif /* EVENTVIEW_H_ */
