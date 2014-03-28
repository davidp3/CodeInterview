#include <stdio.h>
#include <string>
#include <algorithm>

using std::string;

string ERRSTR("ERROR");

string binReal(double x)	{
	unsigned int len = 0;
	string bin;
	if(x == 0.0)
		return "0";
	while((x != 0.0) && (len < 32))	{
		x = x * 2.0;
		if(x >= 1.0)	{
			bin += "1";
			x = x - 1.0;
		} 
		else
			bin += "0";
		++len;
	}
	if(x != 0.0)
		return ERRSTR;
	std::reverse(bin.begin(), bin.end());
	return bin;
}

int main()	{
	double x = 3.0/4.0;
	printf("%s\n", binReal(x).c_str());
}

