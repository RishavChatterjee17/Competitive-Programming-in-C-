#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) 
{
    s.erase(std::remove_if(s.begin(), s.end(), 
        []( auto const& c ) -> bool { return !std::isalnum(c); } ), s.end());
    
    transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c){ return std::tolower(c);});
        
    string scpy = s;
    
    reverse(s.begin(), s.end());
    
    cout << s << endl;
    cout << scpy << endl;
    
    if(scpy == s)
        return true;
    else
        return false;
}
    
int main() 
{
	string s = "__As@@Sa_#";
	
	if(isPalindrome(s))
	    cout << "is Palindrome";
	else
	    cout << "is not Palindrome";
	    
	return 0;
}
