#include<iostream>
#include<vector>
using namespace std;

template <class T>
void Swap(T &val1, T &val2);

//bubble sort
template <class T>
void Sort(T arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = i + 1 ; j < size ; j++)
        {
            if(arr[i] > arr[j])
            {
                Swap(arr[i], arr[j]);
            }
        }
    }
}

template <class T>
void Swap(T &val1, T &val2)
{
    T temp = val1;
    val1 = val2;
    val2 = temp;
}

template <class T>
void PrintArray(T arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

//test case class
class Person
{
public:
    int age;
    string name;

    Person(int page, string pname)
    {
        age = page;
        name = pname;
    }
    
    friend int operator> (Person obj1, Person obj2)
    {
        int rel = 0;
        
        if(obj1.age > obj2.age)
        {
            rel = 1;
        }
        
        return rel;
    }
    
    friend ostream & operator<<(ostream & ccout, Person obj)
    {
        ccout << obj.age << endl;
        ccout << obj.name << endl;
        
        return ccout;
    }
};

int main()
{
	int intArray[] = { 5,8,4,2,8,9,10,34,0,32,2,1 };
	int n = sizeof(intArray) / sizeof(int);

	cout << "Integer Array Before Sort: ";
	PrintArray(intArray, n);

	Sort(intArray, n);

	cout << "Integer Array After Sort: ";
	PrintArray(intArray, n);

	cout << endl;

	char charArray[] = { 'A','Z','F','S','B','C','Q','O' };
	n = sizeof(charArray) / sizeof(char);

	cout << "Char Array Before Sort: ";
	PrintArray(charArray, n);

	Sort(charArray, n);

	cout << "Char Array After Sort: ";
	PrintArray(charArray, n);
	
	cout << endl;
	
	char asciiArray[] = { 'A','d','C','B','D','e','Q','g' };
	n = sizeof(charArray) / sizeof(char);

	cout << "ASCII Array Before Sort: ";
	PrintArray(asciiArray, n);

	Sort(asciiArray, n);

	cout << "ASCII Array After Sort: ";
	PrintArray(asciiArray, n);
	
	cout << endl;
	
	string str[] = {"car", "bus", "toy", "zebra", "sgdigital"};
	n = sizeof(str) / sizeof(str[0]);
	
	cout << "String Array Before Sort: ";
	PrintArray(str, n);

	Sort(str, n);

	cout << "String Array After Sort: ";
	PrintArray(str, n);
	
	cout << endl;
	
	Person arr[3] = {Person(25, "Mark"), Person(30, "John"), Person(20, "Isaac")};
	cout << "Unsorted Person List by Age" << endl;
	PrintArray(arr, 3);
	Sort(arr, 3);
	cout << "Sorted Person List by Age" << endl;
	PrintArray(arr, 3);
	
	return 0;
}


Output:
Integer Array Before Sort: 5 8 4 2 8 9 10 34 0 32 2 1 
Integer Array After Sort: 0 1 2 2 4 5 8 8 9 10 32 34 

Char Array Before Sort: A Z F S B C Q O 
Char Array After Sort: A B C F O Q S Z 

ASCII Array Before Sort: A d C B D e Q g 
ASCII Array After Sort: A B C D Q d e g 

String Array Before Sort: car bus toy zebra sgdigital 
String Array After Sort: bus car sgdigital toy zebra 

Unsorted Person List by Age
25
Mark
 30
John
 20
Isaac
 
Sorted Person List by Age
20
Isaac
 25
Mark
 30
John