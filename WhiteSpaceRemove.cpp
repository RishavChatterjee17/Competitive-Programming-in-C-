#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

bool isSpace(unsigned char c)
{
    return (c == ' '|| c == '\n' || c == '\r' ||
        c == '\t' || c == '\v' || c == '\f' || c == ',' || c == ':' || c == ';');
}

int main() 
{
	string s = "aa; av,   asqw: a";
	
	//or use ::isspace as default
	s.erase(remove_if(s.begin(), s.end(), isSpace), s.end());
	
	cout << s;
	
	return 0;
}


