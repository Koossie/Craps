#include "GameContext.hpp"

#include "ConcreteStates.hpp"
#include "Event.hpp"
#include <boost\thread.hpp>
#include <boost\chrono.hpp>


void GameContext::play()
{
	for(;;)
	{
		if(!currentState)
		{
			std::cout << "Starting New Game" << std::endl;
			currentState = new StartState;
			while(currentState)
			{
				throwDices();
				currentState->handleEvent( Event(DiceRolled),*this);
			}
		}
#if (BOOST_VERSION < 105000)
		boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
#else
		boost::this_thread::sleep_for(boost::chrono::milliseconds(1000));
#endif		
	}
}

void GameContext::throwDices()
{
	// operator precedence
	// Zie ook http://en.cppreference.com/w/cpp/language/operator_precedence
	// "%" heeft hogere prioriteit dan "+"
	// Let op dat "Meneer van Dalen wacht op antwoord" NIET geldt voor post/infix ++ en --.
	// en dat de associativiteit hiervoor wellicht verrassend is.

	dice1.setValue( std::rand() % 6 + 1);
	dice2.setValue( std::rand() % 6 + 1);
    std::cout << "Dice Rolled: " << dice1 <<  " " << dice2 << std::endl;

}
