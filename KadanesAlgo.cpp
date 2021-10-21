#include <iostream>
using namespace std;

int KadanesAlgo(int ar[], int size)
{
    int local_max, global_max = 0;
    
    for(int i = 0; i < size; i++)
    {
        local_max = ar[i] + local_max;
        
        if(local_max < 0)
        {
            local_max = 0;
        }
        else if(local_max > global_max)
        {
            global_max = local_max;
        }
    }
    
    return global_max;
}

int main() 
{
    int ar[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = sizeof(ar)/sizeof(ar[0]);
    
    cout << "Max subarray: " << KadanesAlgo(ar, size);
    
	return 0;
}
