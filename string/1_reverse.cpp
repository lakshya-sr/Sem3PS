#include <iostream>
#include <string>

using namespace std;

string reverse(string s)
{
	string res = "";
	for(int i = s.length()-1; i >= 0; i--)
	{
		res += s[i];
	}
	return res;
}

int main()
{
	string s;
	cout << "Enter string to reverse:" << endl;
	cin >> s;
	cout << reverse(s);
	return 0;
}
