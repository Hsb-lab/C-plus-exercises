//���һ�仰�����Ӣ�ĵ���
#include<iostream>
using namespace std;
int main()
{
	string str1 , str2 = "";
	while (cin >> str1)
	{
		if (str1.size() > str2.size())
		{
			str2 = str1;
		}
	}
	cout << str2 << endl;
	return 0;
}