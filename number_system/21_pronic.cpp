#include <iostream>

using namespace std;

int integer_square_root(int n)
{
    int start = 1, end = n, mid = n/2;
    while(start <= end)
    {
        mid = (start + end) / 2;
        if(mid*mid == n) return mid;
        else if(mid*mid > n) end = mid - 1;
        else if(mid*mid < n) start = mid + 1;
        cout << mid << endl;
    }
    return -1;
}
/*  We check if the quadratic equation x(x+1) = n has integer roots.
    Equation is x^2 + x - n = 0
    Roots are (-1 +- sqrt(1 + 4*n)) / 2
    To check if integer root exists we check if sqrt(1 + 4*n) is an odd integer
*/

bool pronic(int n)
{
    int square_root = integer_square_root(1 + 4*n);
    cout << square_root << endl;
    if(square_root == -1) return false;
    return square_root % 2 == 1;
}

int main()
{
    int n;
    cin >> n;
    cout << pronic(n) << endl;
}