#include <iostream>

using namespace std;

bool neon(int n)
{
    int square = n*n, sum = 0;
    while(square)
    {
        sum += square % 10;
        square /= 10;
    }
    return sum == n;
}

int main()
{
    int n;
    cin >> n;
    cout << n << " is " << (neon(n) ? "" : "not ") << "neon" << endl;
}