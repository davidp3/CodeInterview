#include <stdio.h>
#include <string.h>

void replaceSpaces(char *str, unsigned int len)	{
	if(str == NULL)
		return;
	unsigned int nSpaces = 0;
	char *tstr = str;
	while(*tstr)	{
		if(*tstr == ' ')
			++nSpaces;
		++tstr;
	}
	tstr = str + len + 2*nSpaces;
	char *tstr2 = str + len;
	while(tstr >= str)	{
		if(*tstr2 != ' ')	{
			*tstr = *tstr2;
			--tstr;
			--tstr2;
		}
		else	{
			*(tstr-2) = '%';
			*(tstr-1) = '2';
			*(tstr-0) = '0';
			tstr -= 3;
			--tstr2;
		}
	}
}

int main(void)	{
	char mystr[100] = "This is the string.";
	replaceSpaces(mystr, strlen(mystr));
	printf("%s\n", mystr);
}

