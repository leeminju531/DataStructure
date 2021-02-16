#include <stdio.h>

void HanoiTowerMove(int num, char from, char by, char to);

int main(void)
{
	HanoiTowerMove(3,'A','B','C');
	return 0;
}

void HanoiTowerMove(int num, char from, char by, char to)
{
	if(num == 1)
		printf("num%d :  %c -> %c moved !\n",num,from,to);	
	else
	{
		HanoiTowerMove(num-1,from,to,by);
		printf("num%d :  %c -> %c moved !\n",num,from,to);	
		HanoiTowerMove(num-1,by,from,to);
	}
}