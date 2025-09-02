#include <iostream>
#include <vector>

using namespace std;

bool palindrome(int n)
{
    vector<int> digits;
    while(n)
    {
        digits.push_back(n % 10);
        n /= 10;
    }
    for(int i = 0; i < (digits.size() / 2) + 1; i++)
    {
        if(digits[i] != digits[digits.size()-i-1]) return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    cout << (palindrome(n) ? "palindrome" : "not palindrome") << endl;
    return 0;
}