#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t, n, m;
    cin >> t;
    
    while (t--)
    {
        cin >> n >> m;
        int diff = n - m;
        cout << (diff >= 0 ? diff : 0) << endl;
    }
}
