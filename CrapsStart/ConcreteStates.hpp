#ifndef CONCRETESTATES_HPP_
#define CONCRETESTATES_HPP_

#include "Config.hpp"
#include "AbstractState.hpp"

class GameContext;

class AbstractGameState :public AbstractState
{
	public:
		virtual void handleEvent( const Event& anEvent, Context& aContext);
		virtual void handleEvent( const Event& anEvent, GameContext& aGameContext) = 0;
};

/**
 *
 */
class StartState : public AbstractGameState
{
	public:
		virtual void handleEvent( const Event& anEvent, GameContext& aGameContext);
};

class WinState : public AbstractGameState
{
	public:
		virtual void handleEvent( const Event& anEvent, GameContext& aGameContext);
};

class LoseState : public AbstractGameState
{
	public:
		virtual void handleEvent( const Event& anEvent, GameContext& aGameContext);
};

class PlayState : public AbstractGameState {
public:
	PlayState(const int aRoll);
	virtual void handleEvent (const Event& anEvent, GameContext& aGameContext);
	const int getInitialThrow();

private:
	int initialThrow;
};

#endif // CONCRETESTATES_HPP_
