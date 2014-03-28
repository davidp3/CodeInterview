#include <stdio.h>


unsigned int countWays(int nStairs)	{
	if(nStairs < 0)
		return 0;		// we jumped too far
	if(nStairs == 0)
		return 1;		// we jumped exactly the right distance
	return countWays(nStairs-1) + countWays(nStairs-2) + countWays(nStairs-3);
}


int main()	{
	int N = 2;
	printf("%d\n", countWays(N));
}


