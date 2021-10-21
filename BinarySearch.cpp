#include <iostream>
using namespace std;

void Swap(int *, int *);

int BinarySearch(int arr[], int size, int find)
{
    int low = 0;
    int high = size - 1;
    
    while (low <= high)
    {
        int mid =  low + (high - low)/2;
        
        if(find == arr[mid])
        {
            return mid;
        }
        else if(find < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

void SelectionSort(int *ptr, int size)
{
    int *x, *y;
    
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(*(ptr + j)  < *(ptr + i))
            {
                x = (ptr + i);
                y = (ptr + j);
                
                Swap(x, y);
            }
        }
    }
}

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Display(int *ptr, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << *(ptr + i) << " ";
    }
}

int main() 
{
	int arr[] = {23,2,56,32,68,45,1,67,99,12};
	int size = *(&arr + 1) - arr;;
	int find = 23;
	
	int *p;
	p = arr;
	
	SelectionSort(p, size);
	int a = BinarySearch(arr, size, find);
	
	cout <<"Found at pos: "<< a << endl;
	Display(p, size);
	
	return 0;
}
