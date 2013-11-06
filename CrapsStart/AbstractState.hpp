#ifndef ABSTRACTSTATE_HPP_
#define ABSTRACTSTATE_HPP_

#include "Config.hpp"

class Event;
class Context;

/**
 *
 */
class AbstractState
{
	public:
		virtual ~AbstractState(){};
		virtual void handleEvent( const Event& anEvent, Context& aContext) = 0;

}; // class AbstractState

#endif // ABSTRACTSTATE_HPP_
