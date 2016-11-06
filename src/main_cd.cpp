//------------------------------------------------------
//  Problem: https://open.kattis.com/problems/cd
//  Author: Ola Enberg
//  Date: 2016-11-06
//------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <malloc.h>
#include <vector>

size_t CalcAnswer( size_t n, size_t m, size_t* memory )
{
	if ( n <= 0 || m <= 0 )
	{
		size_t temp;
		for ( size_t i = 0, end = n + m; i < end; ++i )
		{
			scanf( "%d", &temp );
		}
		return 0;
	}

	if ( n > m )
	{
		std::swap( n, m );
	}

	size_t* JacksDiscography = memory;

	for ( size_t i = 0; i < n; ++i )
	{
		scanf( "%d", &JacksDiscography[i] );
	}

	size_t CatalogID;
	size_t ans = 0;
	size_t low_n = 0;
	size_t high_n;
	size_t m_i;
	for ( m_i = 0; m_i < m; ++m_i )
	{
		scanf( "%d", &CatalogID );

		high_n = n - 1;

		if ( JacksDiscography[high_n] <= CatalogID )
		{
			if ( JacksDiscography[high_n] == CatalogID )
			{
				++ans;
			}
			break;
		}

		do
		{
			const int mid_n = low_n + ( high_n - low_n ) / 2;

			if ( JacksDiscography[mid_n] > CatalogID )
			{
				high_n = mid_n;
			}
			else if ( JacksDiscography[mid_n] < CatalogID )
			{
				if (mid_n > low_n  )
				{
					low_n = mid_n;
				}
				else
				{
					if ( JacksDiscography[high_n] < CatalogID )
					{
						low_n = high_n;
					}
					else if ( JacksDiscography[high_n] == CatalogID )
					{
						low_n = high_n;
						++ans;
					}
					break;
				}
			}
			else
			{
				low_n = mid_n + 1;
				++ans;
				break;
			}
		} while ( high_n > low_n );
	}

	for ( ++m_i; m_i < m; ++m_i )
	{
		scanf( "%d", &CatalogID );
	}

	return ans;
}

int main()
{
	size_t* memory = new size_t[10000001];

	while ( true )
	{
		size_t n, m;
		scanf( "%d%d", &n, &m );

		if ( n == 0 && m == 0 )
		{
			return 0;   // EXIT_SUCCESS
		}

		const size_t ans = CalcAnswer( n, m, memory );
		printf( "%d\n", ans );
	}

	delete [] memory;

	return 0;   // EXIT_SUCCESS
};