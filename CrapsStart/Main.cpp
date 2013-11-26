#include "Config.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <boost/thread.hpp>
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
		GameContext game1("1");
		boost::thread table1([&game1] {game1.play();});

		GameContext game2("2");
		boost::thread table2([&game2] {game2.play();});

		GameContext game3("3");
		boost::thread table3([&game3] {game3.play();});


		table1.join();
		table2.join();
		table3.join();
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
