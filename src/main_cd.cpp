//------------------------------------------------------
//	Problem: https://open.kattis.com/problems/cd
//	Author: Ola Enberg
//	Date: 2016-11-06
//------------------------------------------------------

#include <iostream>
#include <vector>

int CalcAnswer()
{
	int n, m;
	std::cin >> n >> m;

	if ( n <= 0 || m <= 0 )
	{
		return 0;
	}

	std::vector<int> JacksDiscography( n );

	for ( int i = 0; i < n; ++i )
	{
		std::cin >> JacksDiscography[i];
	}

	int CatalogID;
	int ans = 0;
	int start_n = 0;
	for ( int i = 0; i < m; ++i )
	{
		std::cin >> CatalogID;
		while ( CatalogID > JacksDiscography[start_n] )
		{
			if ( ++start_n == n )
			{
				return ans;
			}
		}
		if ( CatalogID == JacksDiscography[start_n] )
		{
			++ans;
		}
	}
	return ans;
}

int main()
{
	const int ans = CalcAnswer();
	std::cout << ans << std::endl;

	return 0;	// EXIT_SUCCESS
};