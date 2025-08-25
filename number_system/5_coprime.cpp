#include <iostream>

using namespace std;

int hcf(int a, int b)
{
  int dividend, divisor, quotient, remainder;
  while(remainder > 0)
  {
    dividend = divisor;
    divisor = remainder;
    quotient = dividend / divisor;
    remainder = dividend % divisor;
  }
  return divisor;
}

bool coprime(int a, int b)
{
  return hcf(a, b) == 1;
}

int main()
{
  int a, b;
  cin >> a >> b;
  cout << a << " and " << b << (coprime(a, b) ? " are coprime" : " are not coprime") << endl;
  return 0;
}
