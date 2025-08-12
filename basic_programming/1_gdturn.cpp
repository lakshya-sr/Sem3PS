#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        // your code goes here
        cout << (x + y > 6 ? "YES" : "NO") << endl;
    }
	return 0;
}
