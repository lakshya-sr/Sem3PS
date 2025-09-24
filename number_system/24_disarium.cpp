#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> get_digits(int n)
{
    vector<int> digits;
    while(n)
    {
        digits.push_back(n%10);
        n/=10;
    }
    return digits;
}

bool disarium(int n)
{
    int sum = 0;
    vector<int> digits = get_digits(n);
    for(int i = digits.size(); i >= 1; i--)
    {
        sum += (int)pow(digits[digits.size()-i], i);
    }
    return sum == n;
}

int main()
{
    int n;
    cin >> n;
    cout << disarium(n) << endl;

    return 0;
}