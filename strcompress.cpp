#include <stdio.h>
#include <string>
#include <sstream>

using std::string;

string compress(const string &str)	{
	string compressed;
	string scopy = str;
	unsigned int originalLen = str.length();
	while(!scopy.empty())	{
		char letter = scopy[0];
		unsigned int count = 1;
		unsigned int slen = scopy.length(); 
		while((slen > count) && scopy[count] == letter)
			++count;
		std::stringstream stream;
		stream << letter << count;
		compressed += stream.str();
		scopy = scopy.substr(count);
	}
	return (originalLen > compressed.length()) ? compressed : str;
}

int main(void)	{
	string mystr = "aaabbccccccddddefgggg";
	string newstr = compress(mystr);
	printf("%s\n", newstr.c_str());
}

