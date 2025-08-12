#include <bits/stdc++.h>
using namespace std;

class Ludo
{
    public:
        int t, x;
    
    Ludo()
    {
        cin >> t;
        while (t--)
        {
            cin >> x;
            if (x == 6)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
};

int main() {
	// your code goes here
    Ludo test;
}
