#include <iostream>

#define SIZE 10

using namespace std;

void input_array(int array[])
{
	for(int i = 0; i < SIZE; i++)
	{
		cin >> array[i];
	}
}

void display_array(int array[])
{
	for(int i = 0; i < SIZE; i++)
	{
		cout << array[i] << " ";
	}
}

int main()
{
	int array[SIZE];
	int max = -99999999, min = 9999999;
	input_array(array);
	for(int i = 0; i < SIZE; i++)
	{
		if(array[i] > max) max = array[i];
		if(array[i] < min) min = array[i];
	}
	cout << min << " " << max << endl;
}
