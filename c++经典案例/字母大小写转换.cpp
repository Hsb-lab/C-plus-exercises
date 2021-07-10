//大小写字母转换
//大写字母的ASCII码值 + 32 = 小写字母的ASCII码值
#include<iostream>
using namespace std;
int main()
{
	char a = 'a';
	for (int i = 0; i < 26; i++)
	{
		cout << (char)(a + i) << ' ';
	}
	cout << endl;
	for (int i = 0; i < 26; i++)
	{
		cout << (char)(a + i - 32) << ' ';
	}
	cout << endl;
	
}