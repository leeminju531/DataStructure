#include "Point.h"
#include <stdio.h>

void SetPointPos(Point* ppos,int xpos, int ypos)
{
	ppos -> xpos = xpos;
	ppos -> ypos = ypos;
}

void ShowPointPos(Point* ppos)
{
	printf("(%d,%d)\n",ppos->xpos,ppos->ypos);
}

int PointComp(Point* pos1,Point* pos2)
{
	if(pos1->xpos == pos2->xpos && pos1->ypos == pos2->ypos)
		return Equal;
	else if(pos1->xpos == pos2->xpos)
		return EqualX;
	else if(pos1->ypos == pos2->ypos)
		return EqualY;
	else 
		return Else;
}
