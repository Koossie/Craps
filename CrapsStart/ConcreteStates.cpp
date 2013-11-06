#include "ConcreteStates.hpp"

#include <cstdlib>
#include "Event.hpp"
#include "GameContext.hpp"

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
				AbstractState *state(new PlayState);
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
	std::cout << "We won..." << std::endl;
	aGameContext.setCurrentState(nullptr);
}

void LoseState::handleEvent(	const Event& anEvent,
                            	GameContext& aGameContext)
{
	std::cout << "We lost..." << std::endl;
	aGameContext.setCurrentState(nullptr);
}

void PlayState::handleEvent(const Event& anEvent, GameContext& aGameContext) {
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	switch(aGameContext.getScore()) {
	case 1: { //getScore():	{
		AbstractState *state(new WinState);
		aGameContext.setCurrentState(state);
		break;
	}
	case 7: {
		AbstractState *state(new LoseState);
		aGameContext.setCurrentState(state);
		break;
	}
	default: {
		break;
	}
	}
}

//void State4::handleEvent(	const Event& anEvent,
//                         	GameContext& aGameContext)
//{
//	std::cout << __PRETTY_FUNCTION__ << std::endl;
//	std::cout << "getType: " << anEvent.getType() << std::endl;
//	switch (aGameContext.getScore())
//	{
//		case 4:
//		{
//			AbstractState *state(new WinState);
//			aGameContext.setCurrentState(state);
//			break;
//			break;
//		}
//		case 7:
//		{
//			AbstractState *state(new LoseState);
//			aGameContext.setCurrentState(state);
//			break;
//		}
//		default:
//		{
//			// Stay in the current state and do nothing...
//			break;
//		}
//	}
//}
//
//void State5::handleEvent(	const Event& anEvent,
//                         	GameContext& aGameContext)
//{
//	std::cout << __PRETTY_FUNCTION__ << std::endl;
//	switch (aGameContext.getScore())
//	{
//		case 5:
//		{
//			AbstractState *state(new WinState);
//			aGameContext.setCurrentState(state);
//			break;
//			break;
//		}
//		case 7:
//		{
//			AbstractState *state(new LoseState);
//			aGameContext.setCurrentState(state);
//			break;
//		}
//		default:
//		{
//			// Stay in the current state and do nothing...
//			break;
//		}
//	}
//}
//
//void State6::handleEvent(	const Event& anEvent,
//                         	GameContext& aGameContext)
//{
//	std::cout << __PRETTY_FUNCTION__ << std::endl;
//	switch (aGameContext.getScore())
//	{
//		case 6:
//		{
//			AbstractState *state(new WinState);
//			aGameContext.setCurrentState(state);
//			break;
//			break;
//		}
//		case 7:
//		{
//			AbstractState *state(new LoseState);
//			aGameContext.setCurrentState(state);
//			break;
//		}
//		default:
//		{
//			// Stay in the current state and do nothing...
//			break;
//		}
//	}
//}
//
//void State8::handleEvent(	const Event& anEvent,
//                         	GameContext& aGameContext)
//{
//	std::cout << __PRETTY_FUNCTION__ << std::endl;
//	switch (aGameContext.getScore())
//	{
//		case 8:
//		{
//			AbstractState *state(new WinState);
//			aGameContext.setCurrentState(state);
//			break;
//			break;
//		}
//		case 7:
//		{
//			AbstractState *state(new LoseState);
//			aGameContext.setCurrentState(state);
//			break;
//		}
//		default:
//		{
//			// Stay in the current state and do nothing...
//			break;
//		}
//	}
//}
//
//void State9::handleEvent(	const Event& anEvent,
//                         	GameContext& aGameContext)
//{
//	std::cout << __PRETTY_FUNCTION__ << std::endl;
//	switch (aGameContext.getScore())
//	{
//		case 9:
//		{
//			AbstractState *state(new WinState);
//			aGameContext.setCurrentState(state);
//			break;
//			break;
//		}
//		case 7:
//		{
//			AbstractState *state(new LoseState);
//			aGameContext.setCurrentState(state);
//			break;
//		}
//		default:
//		{
//			// Stay in the current state and do nothing...
//			break;
//		}
//	}
//}
//
//void State10::handleEvent(	const Event& anEvent,
//                          	GameContext& aGameContext)
//{
//	std::cout << __PRETTY_FUNCTION__ << std::endl;
//	switch (aGameContext.getScore())
//	{
//		case 10:
//		{
//			AbstractState *state(new WinState);
//			aGameContext.setCurrentState(state);
//			break;
//			break;
//		}
//		case 7:
//		{
//			AbstractState *state(new LoseState);
//			aGameContext.setCurrentState(state);
//			break;
//		}
//		default:
//		{
//			// Stay in the current state and do nothing...
//			break;
//		}
//	}
//}
//
//void State11::handleEvent(	const Event& anEvent,
//                          	GameContext& aGameContext)
//{
//	std::cout << __PRETTY_FUNCTION__ << std::endl;
//	switch (aGameContext.getScore())
//	{
//		case 11:
//		{
//			AbstractState *state(new WinState);
//			aGameContext.setCurrentState(state);
//			break;
//			break;
//		}
//		case 7:
//		{
//			AbstractState *state(new LoseState);
//			aGameContext.setCurrentState(state);
//			break;
//		}
//		default:
//		{
//			// Stay in the current state and do nothing...
//			break;
//		}
//	}
//}
