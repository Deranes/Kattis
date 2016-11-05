//------------------------------------------------------
//	Problem: https://open.kattis.com/problems/simonsays
//	Author: Ola Enberg
//	Date: 2016-11-05
//------------------------------------------------------

#include <iostream>
#include <string>

int main()
{
	const std::string SimonSays( "Simon says" );
	int n;
	std::cin >> n;

	std::string Line;
	std::getline( std::cin, Line );

	for ( int i = 0; i < n; ++i )
	{
		std::getline( std::cin, Line );

		if ( Line.size() <= SimonSays.size() )
		{
			continue;
		}

		if ( Line.compare( 0, SimonSays.size(), "Simon says" ) == 0 )
		{
			std::cout << &Line[ SimonSays.size() + 1 ] << std::endl;
		}
	}

	return 0;	// EXIT_SUCCESS
};