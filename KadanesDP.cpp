#include <iostream>
using namespace std;

int KadanesAlgo(int ar[], int size)
{
    int local_max, global_max = ar[0];
    
    for(int i = 1; i < size; i++)
    {
        local_max = max(ar[i], ar[i] + local_max);
        global_max = max(global_max, local_max);
    }
    
    return global_max;
}

int main() 
{
    int ar[] = {-2, -3, -4, -1, -2, -1, -5, -3};
    int size = sizeof(ar)/sizeof(ar[0]);
    
    cout << "Max subarray: " << KadanesAlgo(ar, size);
    
	return 0;
}
