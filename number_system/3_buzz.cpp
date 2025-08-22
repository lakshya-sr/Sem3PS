#include <iostream>

using namespace std;

bool check_buzz(int n)
{
	return n % 10 == 7 || n % 7 == 0;
}

int main()
{
	// for(int i = 0; i < 100; i++)
	// {
	// 	if (check_buzz(i))
	// 		cout << i << " is buzz" << endl;
	// }
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << n << (check_buzz(n) ? " is buzz" : " is not buzz") << endl;
	return 0;
}