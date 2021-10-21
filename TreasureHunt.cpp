// Treasure Hunt:

// Answer in C++:

#include<bits/stdc++.h>

using namespace std;

//MACRO Definition
const int ROWS = 5;
const int COLS = 5;

int arr[ROWS][COLS];
int sol[30];
int k = 1, countnumber[25];
int flag = 1;

int printCells(int arr[], int size)
{
    int p = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[abs(arr[i])] >= 0)
        {
            p = arr[abs(arr[i])] = -arr[abs(arr[i])];
        }
        else
        {
            // NO TREASURE
            flag = flag * 0;
            break;
        }
    }
    
    return p;
}
 
void treasureSearch(int a[][COLS])
{
    int count = 0, nrt = 0, ncu = 0, p, c = 1;
    int x = 0, y = 0;
    int nextIndex = 1, flag = 1;
 
    //if nextClue not equals nextIndex
    while (a[x][y] != nextIndex)
    {
        nextIndex = ((x + 1) * 10) + (y + 1);
        
        //starting index 0,0
        if (x == 0 && y == 0)
        {
            sol[0] = nextIndex;
        }
        
        //if nextClue not equals nextIndex
        if (a[x][y] != nextIndex)
        {
            if (c < 25)
            {
                sol[c] = a[x][y];
            }         
            else
            {
                p = printCells(sol, 30);
                if (p == 0)
                {
                    flag = 0;
                    break;
                }
            }
 
            nrt = a[x][y] / 10;
            ncu = a[x][y] % 10;
            x = nrt - 1;
            y = ncu - 1;
            c++;
            count++;
        }
    }
    
    if (flag == 1)
    {
        for (int i = 0; i <= count; i++)
        {
            nrt = sol[i] / 10;
            ncu = sol[i] % 10;
            cout << nrt << " " << ncu << endl;
        }
    }
    else
        cout << "NO TREASURE" << endl;
}
 
int main()
{
    int i,j,checkflag = 0;
    int nrt, ncu = 0;
    int nextclue = 0;
    
    //populate the array
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    //check if unit and tenths place are withing  1 to 5
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)      
        {           
            nextclue = arr[i][j];
            nrt = nextclue / 10;
            ncu = nextclue % 10;
            
            if (nrt >= 1 && nrt <= 5 && ncu >= 1 && ncu <= 5)
            {
                checkflag = 1;
            }
            //condition for no treasure
            else
            {
                checkflag = 0;
                break;
            }
        }
    }
    
    //if treasure exists, call treasureSearch()
    if (checkflag == 0)
    {
        cout << "NO TREASURE" << endl;
    }
    else
    {
        treasureSearch(arr);
    }
}


Input: 
34 21 32 41 25
14 42 43 14 31
54 45 52 42 23
33 15 51 31 35
21 52 33 13 23

Output:
1 1
3 4
4 2
1 5
2 5
3 1
5 4
1 3
3 2
4 5
3 5
2 3
4 3
5 1
2 1
1 4
4 1
3 3
5 2