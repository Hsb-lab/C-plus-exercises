//��Сд��ĸת��
//��д��ĸ��ASCII��ֵ + 32 = Сд��ĸ��ASCII��ֵ
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