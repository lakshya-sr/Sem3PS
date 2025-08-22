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

bool check_prime(int n)
{
	for(int i = 2; i < n; i++)
	{
		if(n % i == 0) return false;
	}
	return true;
}

bool check_cyclic_prime(int n)
{
	int temp = n, num_digits = count_digits(n);
	bool prime = true;
	do
	{
		cout << temp << endl;
		if (!check_prime(temp))
		{
			prime = false;
			break;
		}
		temp = (temp % 10) * (int)pow(10, num_digits-1) + temp / 10;
	}while(temp != n);
	
	return prime;
}

int main()
{
	cout << check_cyclic_prime(19937) << endl;
//	for (int i = 0; i < 100; i++)
//	{
//		cout << i << " " << check_cyclic_prime(i) << endl;
//	}
	return 0;
}



//1234567
//(num % 10) * 10^(num_digits-1) + num / 10
