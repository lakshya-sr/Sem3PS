#include <iostream>
#include <chrono>


using namespace std;

bool happy(int n)
{
    int n_ = n;
    do
    {
        int sum = 0, n__ = n_;
        while(n__)
        {
            sum += (n__ % 10) * (n__ % 10);
            n__ /= 10;
        }
        n_ = sum;
        // cout << n_ << endl;
        // std::this_thread::sleep_for(100)
    } while(!(n_ == 1 || n_ == n));
    
    return n_ == 1;
}

int main()
{
    int n;
    cin >> n;
    cout << n << " is " << (happy(n) ? "" : "not ") << "happy" << endl;
    return 0;
}