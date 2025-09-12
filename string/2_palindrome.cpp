#include <iostream>
#include <string>

using namespace std;

bool palindrome(string s)
{
	for(int i = 0, l = s.length(); i < l/2; i++)
	{
		if(s[i] != s[l - i - 1]) return false;
	}
	return true;
}

int main()
{
	string s;
	cout << "Enter string to check for palindrome: " << endl;
	cin >> s;
	cout << (palindrome(s) ? "yes" : "no") << endl;
	return 0;
}
