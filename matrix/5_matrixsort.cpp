#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void sort(int array[], int len)
{
	for(int i = 0; i < len; i++)
	{
		for(int j = i+1; j < len; j++)
		{
			if(array[j] < array[i])
			{
				swap(array[i], array[j]);
			}
		}
	}
}

void display(int matrix[], int m, int n)
{
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << matrix[i*n + j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int m, n;
	cin >> m >> n;
	int matrix[m * n];
	for (int i = 0; i < m*n; i++)
	{
		cin >> matrix[i];
	}
	
	display(matrix, m, n);
	
	sort(matrix, m*n);
	
	display(matrix, m, n);
	return 0;
}

