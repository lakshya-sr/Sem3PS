#include <iostream>

using namespace std;

bool harshad(int n)
{
    int digit_sum = 0, n_ = n;
    while(n_)
    {
        digit_sum += n_ % 10;
        n_ /= 10;
    }
    return n % digit_sum == 0;
}


int main()
{
    int n;
    cin >> n;
    cout << n << " is " << (harshad(n) ? "" : "not ") << "harshad" << endl;
    return 0;
}
