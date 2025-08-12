#include <iostream>

using namespace std;

class AddTwoNumbers
{
    public:
        int t, a, b;
    
    AddTwoNumbers()
    {
        cin >> t;
        while (t--)
        {
            cin >> a >> b;
            cout << a + b << endl;
        }
    }
};

int main()
{
    AddTwoNumbers test;
}