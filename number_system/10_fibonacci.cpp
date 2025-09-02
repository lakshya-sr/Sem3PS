#include <iostream>
#include <vector>

using namespace std;

vector<int> fib(int n)
{
    vector <int>res;
    int a=0, b=1;
    while(b <= n)
    {
        int temp = a+b;
        a = b;
        b = temp;
        res.push_back(a);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << "Fibonacci sequence until " << n << endl;
    for(int i : fib(n)) cout << i << endl;
    return 0;
}