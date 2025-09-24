#include <iostream>

using namespace std;

string rotate(string s)
{
	return s[s.length()-1] + s.substr(0,s.length()-1);
}

bool check_rotation(string s1, string s2)
{
	if(s1.length() != s2.length()) return false;
//	int len = s1.length(), start = 0;
//	bool equal;
//	while(start < len)
//	{
//		equal = true;
//		for(int i = start; i != start-1; i < len ? i++ : i = 0)
//		{
//			cout << i << endl;
//			if(s1[i] != s2[i]) equal = false;
//			break;
//		}
//		if(equal) break;
//		start++;
//		cout << "-------" << endl;
//	}
//	return equal;

	string s = s1;
	do
	{
		s = rotate(s);
		if(s == s2) return true;
	}while(s != s1);
	return false;
}

int main()
{
	string s1, s2;
	cin >> s1;
	cin >> s2;
	
	cout << check_rotation(s1, s2) << endl;
}
