#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

int main() 
{
	string s = "aA; avX,   @asqw: a";
	
	//erase all non-alhanumeric characters
	s.erase(std::remove_if(s.begin(), s.end(), 
            []( auto const& c ) -> bool { return !std::isalnum(c); } ), s.end());
        
    //transform string to lower case
    transform(s.begin(), s.end(), s.begin(),
            [](unsigned char c){ return std::tolower(c);});
	
	cout << s;
	
	return 0;
}


