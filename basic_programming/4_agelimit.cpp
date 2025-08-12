#include <iostream>

using namespace std;

class AgeLimit
{
    public:
        int t, x, y, a;
    AgeLimit()
    {
        cin >> t;
        while (t--)
        {
            cin >> x >> y >> a;
            if (a >= x && a < y)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
};

int main()
{
    AgeLimit ageCheck;
    return 0;
}