#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "defs.h"

int UpdateGameTimeAndScore(int& time,
                           int& speed,
                           int& score)

{
	if (time == TIME_MAX)
	{
		speed += SPEED_INCREASEMENT;
	}

	if (time > TIME_MAX)
	{
		time = 0;
	}
	if (time % 5 == 0)
	{
		score += SCORE_INCREASEMENT;
	}

	time += TIME_INCREASEMENT;

	return time;
}

#endif // MENU_H_INCLUDED
