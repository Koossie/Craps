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
	virtual void handleEvent (const Event& anEvent, GameContext& aGameContext);
};
//class State4 : public AbstractGameState
//{
//	public:
//		virtual void handleEvent( const Event& anEvent, GameContext& aGameContext);
//};
//
//class State5 : public AbstractGameState
//{
//	public:
//		virtual void handleEvent( const Event& anEvent, GameContext& aGameContext);
//};
//
//class State6 : public AbstractGameState
//{
//	public:
//		virtual void handleEvent( const Event& anEvent, GameContext& aGameContext);
//};
//
//class State8 : public AbstractGameState
//{
//	public:
//		virtual void handleEvent( const Event& anEvent, GameContext& aGameContext);
//};
//
//class State9 : public AbstractGameState
//{
//	public:
//		virtual void handleEvent( const Event& anEvent, GameContext& aGameContext);
//};
//
//class State10 : public AbstractGameState
//{
//	public:
//		virtual void handleEvent( const Event& anEvent, GameContext& aGameContext);
//};
//
//class State11 : public AbstractGameState
//{
//	public:
//		virtual void handleEvent( const Event& anEvent, GameContext& aGameContext);
//};


#endif // CONCRETESTATES_HPP_
