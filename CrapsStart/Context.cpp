#include "Context.hpp"

Context::Context() : currentState(nullptr)
{
}

Context::~Context()
{
}

AbstractState *Context::getCurrentState()
{
	return currentState;
}

void Context::setCurrentState( AbstractState *aCurrentState)
{
	delete currentState;
	currentState = aCurrentState;
}
