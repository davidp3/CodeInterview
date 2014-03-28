#include <stdio.h>
#include <vector>
#include <math.h>


int main()	{
	static const long long N = 600851475143;
	unsigned int sqrtN = (unsigned int)sqrt((double)N);
	std::vector<bool> vec(sqrtN+1, false);
	unsigned int best = 1;
	printf("%d\n", sqrtN);
	for(unsigned int i=2; i <= sqrtN; ++i)	{
		if(vec[i])
			continue;
		if(N % (long long)i == 0)
			best = i;
		for(unsigned int j=i*i; j <= sqrtN; j+=i)	{
		printf("%d %d\n", j,i);
			vec[j] = true;
		}
	}
	printf("%d\n", best);
}
