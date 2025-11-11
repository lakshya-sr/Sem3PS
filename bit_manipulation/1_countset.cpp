#include <iostream>
using namespace std;

int countSetBits(unsigned int n) {
    int count = 0;
    while (n > 0) {
        count += (n & 1);  
        n >>= 1;
    }
    return count;
}

int main() {
    unsigned int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << "Number of set bits: " << countSetBits(n) << endl;

    return 0;
}
