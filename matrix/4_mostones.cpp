#include <iostream>

using namespace std;

int count_ones(int matrix[], int m, int n, int i)
{
	int j = 0;
	while(matrix[i*n+j] == 1)
	{
		j++;
	}
	return j;
}

int most_ones(int matrix[], int m, int n)
{
	int max_index = -1, max_ones = -1;
	for(int i = 0; i < m; i++)
	{
		int ones = count_ones(matrix, m, n, i);
		if (ones > max_ones)
		{
			max_ones = ones;
			max_index = i;
		}
	}
	return max_index;
}

int main()
{
	int m, n;
	cout << "Enter dimensions of matrix(space separated): ";
	cin >> m >> n;
	int matrix[m*n];
	cout << "Enter values of matrix(space separated): " << endl;
	for(int i = 0; i < m*n; i++)
		cin >> matrix[i];
	
	cout << most_ones(matrix, m, n) << endl;
	return 0;
}
