#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool check_armstrong(int n)
{
    vector<int> digits;
    int temp = n;
    while(temp)
    {
        digits.push_back(temp%10);
        temp /= 10;
    }
    
    int sum = 0;
    for (int digit : digits)
    {
        sum += pow(digit, digits.size());
    }

    return sum == n;
}

int main()
{
    int n;
    cout << "Enter a number: "; cin >> n;
    cout << n << " is " << (check_armstrong(n) ? "armstrong" : "not armstrong") << endl;
}