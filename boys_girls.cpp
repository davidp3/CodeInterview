#include <stdio.h>
#include <math.h>

int main()	{
	int N = 200;
	double numerator = 0, denominator = 0;
	
	for(int i=1; i<N; ++i)	{
		numerator += pow(0.5, i) * ((double)i-1.0);
		denominator += pow(0.5, i);
		printf("%d -> (%lf, %lf) %lf\n", i, numerator, denominator, numerator/denominator);
	}
}



