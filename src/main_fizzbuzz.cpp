//------------------------------------------------------
//	Problem: https://open.kattis.com/problems/fizzbuzz
//	Author: Ola Enberg
//	Date: 2016-11-05
//------------------------------------------------------

#include <iostream>

int main()
{
	int x, y, n;
	std::cin >> x >> y >> n;

	for ( int i = 1; i <= n; ++i )
	{
		if ( i % x == 0 )
		{
			if ( i % y == 0 )
			{
				std::cout << "FizzBuzz" << std::endl;
			}
			else
			{
				std::cout << "Fizz" << std::endl;
			}
		}
		else
		{
			if ( i % y == 0 )
			{
				std::cout << "Buzz" << std::endl;
			}
			else
			{
				std::cout << i << std::endl;
			}
		}
	}

	return 0;	// EXIT_SUCCESS
};