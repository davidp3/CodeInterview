#include <stdio.h>

int main()	{
	static const int N = 4 * 1000 * 1000;
	int sum = 0;
	int prev0 = 1, prev1 = 1;
	while(prev1 < N)	{
		int t = prev0 + prev1;
		sum += (t % 2 == 0) ? t : 0;
		prev0 = prev1;
		prev1 = t;
	}
	printf("%d\n", sum);
}
