#include <stdio.h>
#include <string>

using std::string;

bool isSubstring(const string &str, const string &substr)	{
	return str.find(substr) != string::npos;
}

bool isRotation(const string &s1, const string &s2)	{
	if(s2.length() != s1.length())
		return false;
	string dup = s1 + s1;
	return isSubstring(dup, s2);
}

int main(void)	{
	string orig = "A simple string.";
	string rot = "le string.A simp";
	if(isRotation(orig, rot))
		printf("TRUE\n");
	else
		printf("FALSE\n");
}

