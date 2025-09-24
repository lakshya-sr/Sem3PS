#include <iostream>
#include <map>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int freq[128] = {0};
	for(int i = 0; i < s.length(); i++)
	{
		freq[s[i]]++;
	}
	for(int i = 0; i < 256; i++)
	{
		if(freq[i] > 1)
		{
			cout << (char)i << " " << freq[i] << endl;
		}
	}
	
	return 0;
}
