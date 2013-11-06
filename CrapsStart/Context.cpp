#include "Context.hpp"

Context::~Context()
{
}

AbstractState *Context::getCurrentState()
{
	return currentState;
}

void Context::setCurrentState( AbstractState *aCurrentState)
{
	currentState = aCurrentState;
}
