#include <iostream>

using namespace std;

#define SIZE 10

int main()
{
	int array[SIZE];
	int reverse[SIZE];
	
	for(int i = 0; i < SIZE; i++)
	{
		cin >> array[i];
	}
	for(int i = 0; i < SIZE; i++)
	{
		reverse[SIZE - 1 - i] = array[i];
	}
	
	for(int i = 0; i < SIZE; i++)
	{
		cout << reverse[i] << " ";
	}
}
