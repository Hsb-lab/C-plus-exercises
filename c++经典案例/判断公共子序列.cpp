#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2, s, str;
	cin >> s1 >> s2 >> s;
	int i1 = 0, j1 = 0;
	while (i1 < s.length() && j1 < s1.length())
	{
		if (s[i1] == s1[j1])
		{
			++i1;
			++j1;
		}
		else
		{
			++j1;
		}
	}
	int i2 = 0, j2= 0;
	while (i2 < s.length() && j2 < s2.length())
	{
		if (s[i2] == s1[j2])
		{
			++i2;
			++j2;
		}
		else
		{
			++j2;
		}
	}
	if (i1 == s.length() && i2 == s.length())
		{
			cout << "yes";
		}
		else
		{
			cout << "no";
		}
	return 0;
}