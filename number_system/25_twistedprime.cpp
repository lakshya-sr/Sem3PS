#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime(int n)
{
    for(int i = 2; i*i <= n; i++)
    {
        if(n % i == 0) return false;
    }
    return true;
}

vector<int> get_digits(int n)
{
    vector<int> digits;
    while(n)
    {
        digits.push_back(n%10);
        n/=10;
    }
    return digits;
}

int reverse(int n)
{
    int res = 0;
    vector<int> digits = get_digits(n);
    for(int i = digits.size()-1; i >= 0; i--)
    {
        res += digits[i]*(int)pow(10, digits.size()-i-1);
    }
    return res;
}

bool twistedprime(int n)
{
    return is_prime(n) && is_prime(reverse(n));
}

int main()
{
    int n;
    cin >> n;
    cout << twistedprime(n) << endl;

    return 0;
}