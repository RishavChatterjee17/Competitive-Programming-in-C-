#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Palindrome(int num)
{
    int numc = num;
    int digit, rev = 0;

    while(num != 0)
    {
        digit = num % 10;
        rev = (rev*10) + digit;
        num = num / 10;
    }
    
    if(numc == rev)
        cout << "is Palindrome";
    else
        cout << "is Not Palindrome";;
}

string Palindrome(string s)
{
    string scpy = s;
    
    reverse(s.begin(), s.end());
    
    if(scpy == s)
        return "is Palindrome";
    else
        return "is Not Palindrome";
}

int main() 
{
	int num = 10;
	string s = "abbb";
	
	Palindrome(num);
	cout << endl;
	cout << Palindrome(s);
	
	return 0;
}

