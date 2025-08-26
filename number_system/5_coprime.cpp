#include <iostream>

using namespace std;


int hcf(int a, int b)
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

bool coprime(int a, int b)
{
  int factor = hcf(a, b);
  cout << factor << endl;
  return factor == 1;
}

int main()
{
  int a, b;
  cin >> a >> b;
  bool success = coprime(a, b);
  cout << a << " and " << b << (success ? " are coprime" : " are not coprime") << endl;
  return 0;
}
