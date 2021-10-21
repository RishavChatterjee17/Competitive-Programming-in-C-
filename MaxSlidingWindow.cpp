#include <iostream>
using namespace std;

int Sliding(int ar[], int size, int window)
{
    if(size < window)
    {
        return -1;
    }
    
    int max_sum = 0;
    for(int i = 0; i<window; i++)
    {
        max_sum = max_sum + ar[i];
    }
    
    int window_sum = max_sum;
    for(int i = window; i<size; i++)
    {
        window_sum += ar[i] - ar[i - window];
        max_sum = max(max_sum, window_sum);
    }
    
    return max_sum;
}

int main() 
{
	int ar[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
	int size = sizeof(ar) / sizeof(ar[0]);
	
	int window = 3;
	
	cout << " " << Sliding(ar, size, window);
	
	return 0;
}
