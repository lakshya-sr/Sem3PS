#include <iostream>

using namespace std;

template <typename T>
T avg(T a, T b) {
	return (a + b)/2;
}

int main()
{
	cout << avg(1, 2) << endl; 
	cout << avg(1.5, 1.0) << endl;
}
