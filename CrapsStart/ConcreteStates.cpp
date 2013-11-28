#include "ConcreteStates.hpp"

#include <cstdlib>
#include "Event.hpp"
#include "GameContext.hpp"
#include "Logger.hpp"

void AbstractGameState::handleEvent( const Event& anEvent, Context& aContext)
{
	if(dynamic_cast<GameContext*>(&aContext))
	{
		handleEvent(anEvent,(GameContext&) aContext);
	}
}

void StartState::handleEvent(	const Event& anEvent,
                             	GameContext& aGameContext)
{
	std::cout << __PRETTY_FUNCTION__ << ": " << anEvent.getType() << std::endl;

	if(anEvent == DiceRolled)
	{
		switch (aGameContext.getScore())
		{
			// The lose cases
			case 2:
			case 3:
			case 12:
			{
				AbstractState *state = new LoseState;
				aGameContext.setCurrentState(state);
				break;
			}
			// the win case
			case 7:
			{
				AbstractState *state = new WinState;
				aGameContext.setCurrentState(state);
				break;
			}
			// The other cases
			case 4:
			case 5:
			case 6:
			case 8:
			case 9:
			case 10:
			case 11:
			{
				AbstractState *state(new PlayState(aGameContext.getScore()));
				aGameContext.setCurrentState(state);
				break;
			}
//			case 4:
//			{
//				AbstractState *state(new State4);
//				aGameContext.setCurrentState(state);
//				break;
//			}
//			case 5:
//			{
//				AbstractState *state(new State5);
//				aGameContext.setCurrentState(state);
//				break;
//			}
//			case 6:
//			{
//				AbstractState *state(new State6);
//				aGameContext.setCurrentState(state);
//				break;
//			}
//			case 8:
//			{
//				AbstractState *state(new State8);
//				aGameContext.setCurrentState(state);
//				break;
//			}
//			case 9:
//			{
//				AbstractState *state(new State9);
//				aGameContext.setCurrentState(state);
//				break;
//			}
//			case 10:
//			{
//				AbstractState *state(new State10);
//				aGameContext.setCurrentState(state);
//				break;
//			}
//			case 11:
//			{
//				AbstractState *state(new State11);
//				aGameContext.setCurrentState(state);
//				break;
//			}
			default:
			{
				std::cerr << "We should not get here..." << std::endl;

				AbstractState *state;
				aGameContext.setCurrentState(state);
				break;
			}
		}
	}
}

void WinState::handleEvent( const Event& anEvent,
                            GameContext& aGameContext)
{
	//std::cout << "Table " << aGameContext.getTableName() << " won..." << std::endl;
	Logger::getInstance().startOutput();
	Logger::getInstance().log("Table " + aGameContext.getTableName() + " won!!!");
	Logger::getInstance().endOutput();
	aGameContext.setCurrentState(nullptr);
}

void LoseState::handleEvent(	const Event& anEvent,
                            	GameContext& aGameContext)
{
	//std::cout << "Table " << aGameContext.getTableName() << " lost..." << std::endl;

	Logger::getInstance().startOutput();
	Logger::getInstance().log("Table " + aGameContext.getTableName() + " lost...");
	Logger::getInstance().endOutput();
	aGameContext.setCurrentState(nullptr);
}

void PlayState::handleEvent(const Event& anEvent, GameContext& aGameContext) {
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	if (aGameContext.getScore() == getInitialThrow()) {
		AbstractState *state(new WinState);
		aGameContext.setCurrentState(state);
	}
	else if (aGameContext.getScore() == 7) {
		AbstractState *state(new LoseState);
		aGameContext.setCurrentState(state);
	}
	else {

	}
}

PlayState::PlayState(const int aRoll) : initialThrow(aRoll) {}

const int PlayState::getInitialThrow() {
	return initialThrow;
}
