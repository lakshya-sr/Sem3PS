#include <iostream>

using namespace std;

void floyd_triangle(int n)
{
    int k = 1;
    for(int i = 1; k <= n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            cout << k << " ";
            k++;
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    floyd_triangle(n);
    return 0;
}