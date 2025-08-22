#include <iostream>
#include <cmath>

using namespace std;

int count_digits(int n)
{
	int digits = 0;
	while(n)
	{
		n /= 10;
		digits++;
	}
	return digits;
}

int last_digits(int n, int digits)
{
	return n % (int)pow(10, digits);
}

bool check_automorphic(int n)
{
	int num_digits = count_digits(n);
	int last_digits_of_square = last_digits(n*n, num_digits);
//	cout << num_digits << " " << last_digits_of_square << endl;
	return last_digits_of_square == n;
}

int main()
{
//	for (int i = 1; i < 1000000; i++)
//	{
//		if (check_automorphic(i))
//			cout << i << " automorphic " << i*i << endl;
//	}
//	
	int n;
	cout << "Enter a number: ";
	cin >> n;
	if (check_automorphic(n))
		cout << n << " is automorphic\n";
	else 
		cout << n << " is not automorphic\n";
	return 0;
}