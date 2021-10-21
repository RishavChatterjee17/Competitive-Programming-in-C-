#include <iostream>
using namespace std;

int fibonacci(int n)
{
    return (n<=1) ? n : (fibonacci(n-1) + fibonacci(n-2) );
}

int main() 
{
	int n = 30;

    for (int i = 1; i <= n; i++)
    {
        cout<<" "<<fibonacci(i);
    }
  
  return 0;
}