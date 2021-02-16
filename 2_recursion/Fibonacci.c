#include <stdio.h>
int Fibo(int n);
int main(void)
{
	int i;
	for(i=1;i<15;i++)
		printf("%d ",Fibo(i));

	return 0;
}

int Fibo(int n)
{
	int i;
	if(n == 1)
		return 0;
	else if(n == 2)
		return 1;
	else
		return Fibo(n-1) + Fibo(n-2);

}