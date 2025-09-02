#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    int dividend = a, divisor = b, quotient, remainder;
    if (dividend < divisor)
    swap(dividend, divisor);

    remainder = divisor;
    while(remainder > 0)
    {
        divisor = remainder;
        quotient = dividend / divisor;
        remainder = dividend % divisor;
        dividend = divisor;
    }
    return divisor;
}

int lcm(int a, int b)
{
    return a*b / gcd(a, b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << "LCM is " << lcm(a, b) << endl;
    return 0;
}
