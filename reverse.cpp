#include <algorithm>

void reverse(char *str)	{
	if(str == NULL)
		return;
	size_t len = strlen(str);
	for(unsigned int i=0; i<len/2; ++i)	{
		printf("%d\n", len);
		printf("%s\n", str);
		std::swap(str[i], str[len-i-1]);
	}
}


int main(void)	{
	char mystr[] = "This is it.";
	reverse(mystr);
	printf("%s\n", mystr);
}
