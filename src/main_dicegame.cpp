//------------------------------------------------------
//  Problem: https://open.kattis.com/problems/dicegame
//  Author: Ola Enberg
//  Date: 2016-11-07
//------------------------------------------------------

#include <iostream>

struct Die
{
	int		_Min;
	int		_Max;
};

struct Player
{
	Die		_Die1;
	Die		_Die2;
};

int main()
{
	Player Gunnar, Emma; 

	scanf( "%d%d%d%d%d%d%d%d", &Gunnar._Die1._Min, &Gunnar._Die1._Max, &Gunnar._Die2._Min, &Gunnar._Die2._Max, &Emma._Die1._Min, &Emma._Die1._Max, &Emma._Die2._Min, &Emma._Die2._Max );

	float vGunnarAvarage = Gunnar._Die1._Min + Gunnar._Die2._Min + 0.5f * ( ( Gunnar._Die1._Max + Gunnar._Die2._Max ) - ( Gunnar._Die1._Min + Gunnar._Die2._Min ) );
	float vEmmaAvarage = Emma._Die1._Min + Emma._Die2._Min + 0.5f * ( ( Emma._Die1._Max + Emma._Die2._Max ) - ( Emma._Die1._Min + Emma._Die2._Min ) );

	if ( vGunnarAvarage > vEmmaAvarage )
	{
		printf( "Gunnar" );
	}
	else if ( vGunnarAvarage < vEmmaAvarage )
	{
		printf( "Emma" );
	}
	else
	{
		printf( "Tie" );
	}

	return 0;   // EXIT_SUCCESS
};