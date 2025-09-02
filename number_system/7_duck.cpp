#include <iostream>

using namespace std;

bool duck(int n)
{
    while(n)
    {
        if (n % 10 == 0) return true;
        n /= 10;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    cout << n << (duck(n) ? " is duck number" : " is not duck number") << endl;
}