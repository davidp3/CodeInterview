#include <stdio.h>

enum Denomination { PENNY, NICKEL, DIME, QUARTER };
int denomValue[] = { 1, 5, 10, 25 };

int countWays(int N, Denomination denom)	{
	if(N < 0)
		return 0;		// overshot
	if(N == 0)
		return 1;		// exact change!
		
	int ret = 0;
	for(int i=0; i<=denom; ++i)	{
		if(N >= denomValue[i])	{
			ret += countWays(N-denomValue[i], (Denomination)i);
		}
	}
	return ret;
}

int main()	{
	int N = 10;
	int nWays = countWays(N, QUARTER);
	printf("%d\n", nWays);
}

