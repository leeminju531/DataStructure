#ifndef __POINT_H__
#define __POINT_H__
enum _comp
{
	Else= -1 ,
	EqualX=0 ,
	EqualY=1 ,
	Equal=2 
};

typedef struct _point
{
	int xpos;
	int ypos;
}Point;

void SetPointPos(Point* ppos,int xpos, int ypos);
void ShowPointPos(Point* ppos);
int PointComp(Point* pos1, Point* pos2);

#endif
