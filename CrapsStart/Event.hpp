#ifndef EVENT_HPP_
#define EVENT_HPP_

#include "Config.hpp"
#include "EventTypes.hpp"

/**
 *
 */
class Event
{
	public:
		Event(EventType anEventType) : eventType(anEventType){}
		Event(const Event& anEvent) : eventType(anEvent.eventType){}
		virtual ~Event(){}
		Event& operator=(const Event& anEvent)
		{
			if(this!=&anEvent)
			{
				eventType = anEvent.eventType;
			}
			return *this;
		}
		bool operator==(const Event& anEvent) const
		{
			return eventType == anEvent.eventType;
		}
		EventType getType() const {return eventType;}

	private:
		EventType eventType;

};

#endif // EVENT_HPP_
