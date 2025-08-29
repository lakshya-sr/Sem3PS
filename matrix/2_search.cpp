#include <iostream>

using namespace std;

bool binary_search(int array[], int m, int n, int value)
{
	int start=0, end=m*n, mid;
	while(start <= end)
	{
		mid = (start+end)/2;
		if(array[mid] == value)
			return true;
		else if (array[mid] < value)			
			start = mid+1;
		else if (array[mid] > value)
			end = mid-1;
	}
	return false;
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
	
	int value;
	cout << "Enter value to search: ";
	cin >> value;
	cout << (binary_search(matrix, m, n, value) ? "true" : "false") << endl;
	return 0;
}
