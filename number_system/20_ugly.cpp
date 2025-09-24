#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int n)
{
    for(int i = 2; i*i <= n; i++)
    {
        if(n % i == 0) return false;
    }
    return true;
}

vector<int> prime_factors(int n)
{
    vector<int>factors;
    for(int i = 2; i*i <= n; i++)
    {
        if(n % i == 0 && is_prime(i)) factors.push_back(i);
    }
    return factors;
}

bool ugly(int n)
{
    vector<int> factors = prime_factors(n);
    return factors.size() <= 3 && (factors.back() == 5 || factors.back() == 3 || factors.back() == 2);
}

int main()
{
    int n;
    cin >> n;
    //for(auto i: prime_factors(n)) cout << i << "|";
    cout << ugly(n) << endl;
}