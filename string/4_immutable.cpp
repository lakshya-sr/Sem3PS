#include <iostream>

using namespace std;

int main()
{
	string s;
	int i;
	char c;
	
	cout << "Enter string: "; cin >> s;
	cout << "Enter index to change: "; cin >> i;
	cout << "Enter character: "; cin >> c;
	s[i] = c;
	cout << "Result: " << s;
	
	return 0;
}
