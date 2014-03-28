#include <stdbool.h>
#include <memory.h>
#include <stdio.h>

static const unsigned int BPC = 1, BPB = 8, NUM_LETTERS = 256;


unsigned int getLetter(const char *str, unsigned int bytesPerChar)	{
	unsigned int ret = 0;
	for(unsigned int i=0; i<bytesPerChar; ++i)	{
		ret = (ret << 8) | ((int)(*str));
		++str;
	}
	return ret;
}

bool hasAllUnique(const char *str) {
	unsigned int LEN_ARRAY = (NUM_LETTERS-1)/BPB + 1;
	unsigned char letters[LEN_ARRAY];
	memset(letters, 0, LEN_ARRAY);
	if(str == NULL)
		return true;
	while(*str)	{
		unsigned int letter = getLetter(str, BPC);
		printf("%c\n", (char)letter); 
		unsigned int byte = letter / BPB,
			bit = letter % BPB;
		if((letters[byte] & (1 << bit)) != 0)
			return false;
		letters[byte] |= (1 << bit);
		str += BPC;
	}
	return true;
}

int main(void)	{
	char *mystr = "This is.";
	if(hasAllUnique(mystr))
		printf("TRUE\n"); 
	else
		printf("FALSE\n"); 
}



