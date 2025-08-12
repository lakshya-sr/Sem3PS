#include <bits/stdc++.h>
using namespace std;

class SavingTaxes
{
    public:
        int t, x, y;
    
    SavingTaxes()
    {
        cin >> t;
        while (t--)
        {
            cin >> x >> y;
            cout << x - y << endl;
        }
    }
};
int main() {
	// your code goes here
    SavingTaxes test;
}
