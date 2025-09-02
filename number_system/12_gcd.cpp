#include <iostream>

using namespace std;

// Copied from coprime
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
    
    // cout << quotient << " " << remainder << " " << dividend << " " << divisor << endl;
  }
  return divisor;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;
    return 0;
}