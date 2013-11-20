#include "Config.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "GameContext.hpp"

// Why using "using std;" is probably not a good idea:
// http://www.parashift.com/c++-faq/using-namespace-std.html

int main( 	int argc,
			char** argv)
{
	// Initialise the C-library random mechanism by seeding it with the current time
	// See http://www.cplusplus.com/reference/clibrary/cstdlib/srand/
	std::srand( std::time( NULL));

	// For more info on exception handling: http://www.cplusplus.com/doc/tutorial/exceptions/
	// and http://www.parashift.com/c++-faq/exceptions.html
	try
	{
		GameContext game;
		game.play();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown exception caught: " << std::endl;
	}
	return 0;
}
