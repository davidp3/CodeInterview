#include <stdio.h>

static const unsigned int ERROR = 0xffff;

unsigned int insert(unsigned int n, unsigned int m, unsigned int i, unsigned int j)	{
	if(j <= i)
		return ERROR;
	unsigned int mask = 0;
//	for(unsigned int x=0; x<j-i+1; ++x)
//		mask = (mask << 1)|0x1;
	mask = ((1 << (j-i+1))-1) << i;
	printf("%0x\n", mask);
	m = m << i;
	n = n & (~mask);
	n = n | m;
	return n;
}

int main()	{
	unsigned int n = 0x400, m = 0x13, i=2, j=6;
	printf("%x\n", insert(n,m,i,j));
}
