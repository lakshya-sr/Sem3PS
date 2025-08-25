//0  1  2  3  4  5  6 
//7  8  9  10 11 12 13 
//14 15 16 17 18 19 20
//21 22 23 24 25 26 27
//28 29 30 31 32 33 34

#include <iostream>

using namespace std;

int elem(int i, int j, int n)
{
	return i*n + j;
}

void outer_rect(int matrix[], int m, int n, int x_offset, int y_offset)
{
	for(int i = 0+x_offset; i < n-x_offset; i++)
	{
		cout << matrix[elem(0+y_offset, i,n)] << " ";
	}
	cout << "|";
	for(int i = 1+y_offset; i < m-y_offset; i++)
	{
		cout << matrix[elem(i, n-1-x_offset, n)] << " ";
	}
	cout << "|";
	
	for(int i = n-2-x_offset; i >= 0+x_offset; i--)
	{
		cout << matrix[elem(m-1-y_offset, i, n)] << " ";
	}
	cout << "|";
	
	for(int i = m-2-y_offset; i >= 1+y_offset; i--)
	{
		cout << matrix[elem(i, 0+x_offset, n)] << " ";
	}
	cout << endl;
}


void spiral(int matrix[], int m, int n)
{
	int result[m*n];
	int top = 0, bottom = m-1, left = 0, right = n-1;
	while(top <= bottom && left <= right)
	{
		for(int i = left; i <= right; i++)
		{
			result[index++] = matrix[top][i];
		}
		top++;
		for(int i = top; i <= bottom; i++)
		{
			result[index++] = matrix[i][right];
		}
		right--;
		
		
	}
}

int main()
{
	int m, n;
	cin >> m >> n;
	int matrix[m*n];
	for (int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> matrix[elem(i, j, n)];
		}
	}
	
	int lesser_dimension = m < n ? m : n;
	for(int i = 0; i < (lesser_dimension / 2 + lesser_dimension % 2); i++)
	{
		outer_rect(matrix, m, n, i, i);
	}
	return 0;
}




//
//void outer_rect(int matrix[], int m, int n, int x_offset, int y_offset)
//{
//	for(int i = 0; i < n; i++)
//	{
//		cout << matrix[elem(0,i,n)] << " ";
//	}
//	
//	for(int i = 1; i < m; i++)
//	{
//		cout << matrix[elem(i, n-1, n)] << " ";
//	}
//	
//	for(int i = n-2; i >= 0; i--)
//	{
//		cout << matrix[elem(m-1, i, n)] << " ";
//	}
//	
//	for(int i = m-2; i >= 1; i--)
//	{
//		cout << matrix[elem(i, 0, n)] << " ";
//	}
//	cout << endl;
//}
//
