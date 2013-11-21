#ifndef CONTEXT_HPP_
#define CONTEXT_HPP_

#include "Config.hpp"
#include "AbstractState.hpp"

/**
 *
 */
class Context
{
	public:
		Context();
		virtual ~Context();

		AbstractState *getCurrentState();
		void setCurrentState(AbstractState *aCurrentState);

	protected:
		AbstractState *currentState;
};

#endif // CONTEXT_HPP_
