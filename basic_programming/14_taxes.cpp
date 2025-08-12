#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t, x;
    cin >> t;
    while(t--)
    {
        cin >> x;
        cout << (x > 100 ? x - 10 : x) << endl;
    }
}
