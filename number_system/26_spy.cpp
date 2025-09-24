#include <iostream>
#include <vector>

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

bool spy(int n)
{
    int sum = 0, product = 1;
    for(auto i: get_digits(n)){
        sum += i;
        product *= i;
    } 
    return sum == product;
}

int main()
{
    int n;
    cin >> n;
    cout << spy(n) << endl;

    return 0;
}