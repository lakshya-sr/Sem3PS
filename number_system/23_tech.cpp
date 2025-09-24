#include <iostream>
#include <vector>
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

bool tech(int n)
{
    int digits = count_digits(n);
    if(digits % 2 == 1) return false;
    int sum = (n % (int)pow(10,digits/2)) + (n / (int)pow(10,digits/2));
    return sum*sum == n;
}

int main()
{
    int n;
    cin >> n;
    cout << tech(n) << endl;
    return 0;
}