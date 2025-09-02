#include <iostream>
#include <vector>
using namespace std;

vector<int> factors(int n)
{
    int a=1, b;
    vector <int>res;
    do
    {
        if(n % a == 0)
        {
            res.push_back(a);
            b = n / a;
            res.push_back(b);
        }
        a++;
        
    }while(a < b);
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << "Factors of " << n << " are : ";
    for(int factor : factors(n))
    {
        cout << factor << " ";
    }
    cout << endl;
    return 0;
}