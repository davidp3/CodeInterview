#include <vector>
#include <string>

using std::string;
using std::vector;

static const int NUM_LETTERS = 256;

bool permutation(const string &str1, const string &str2)	{
	vector<unsigned int> letterCount(NUM_LETTERS);
	for(string::const_iterator it = str1.begin(); it != str1.end(); ++it)	{
		letterCount[(unsigned int)(*it)]++;
	}
	for(string::const_iterator it = str2.begin(); it != str2.end(); ++it)	{
		if(letterCount[(unsigned int)(*it)] == 0)
			return false;
		letterCount[(unsigned int)(*it)]--;
	}
	for(vector<unsigned int>::const_iterator it = letterCount.begin(); it != letterCount.end(); ++it)	{
		if((*it) != 0)
			return false;
	}
	return true;
} 

int main(void)	{
	string str1("This is A"), str2("A is This");
	if(permutation(str1, str2))
		printf("TRUE\n");
	else
		printf("FALSE\n");
}


