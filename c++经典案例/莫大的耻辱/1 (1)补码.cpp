#include<iostream>
#include<string>
using namespace std;
int main()
{
	int dec = 0;
    string num;
	cin >> num;
	int len = num.size();
	if (num[0] == '1')
	{
		len--;
		num[len] -= 1;
		while (num[len] == '0'-1)
		{
			num[len] = '1';
			len--;
			num[len] -= 1;
		}
		for (int i = 1; i < num.size(); i++)
		{
			if (num[i] == '0')
				num[i] = '1';
			else
				num[i] = '0';
		}
		cout << "-";
	}
	for (int i = 1; i < num.size(); i++)
	{
		dec += ((num[i] - '0') << (num.size() - 1 - i));
	}
	cout << dec;
	return 0;
}
