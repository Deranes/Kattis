//------------------------------------------------------
//  Problem: https://open.kattis.com/problems/vauvau
//  Author: Ola Enberg
//  Date: 2016-11-07
//------------------------------------------------------

#include <iostream>

struct Dog
{
	int		_TimeAggressive;
	int		_TimeCalm;
	int		_PeriodLength;
};

int main()
{
	Dog Dog1, Dog2;
	int ArrivalTimes[3];

	scanf( "%d%d%d%d%d%d%d", &Dog1._TimeAggressive, &Dog1._TimeCalm, &Dog2._TimeAggressive, &Dog2._TimeCalm, &ArrivalTimes[0], &ArrivalTimes[1], &ArrivalTimes[2] );

	Dog1._PeriodLength = Dog1._TimeAggressive + Dog1._TimeCalm;
	Dog2._PeriodLength = Dog2._TimeAggressive + Dog2._TimeCalm;
	ArrivalTimes[0] -= 1;
	ArrivalTimes[1] -= 1;
	ArrivalTimes[2] -= 1;

	int timesAttacked;
	for ( int i = 0; i < 3; ++i )
	{
		timesAttacked = 0;

		if ( ArrivalTimes[i] % Dog1._PeriodLength < Dog1._TimeAggressive )
		{
			++timesAttacked;
		}
		if ( ArrivalTimes[i] % Dog2._PeriodLength < Dog2._TimeAggressive )
		{
			++timesAttacked;
		}

		if ( timesAttacked == 0 )
		{
			printf( "none\n" );
		}
		else if ( timesAttacked == 1 )
		{
			printf( "one\n" );
		}
		else
		{
			printf( "both\n" );
		}
	}
	
	return 0;   // EXIT_SUCCESS
};