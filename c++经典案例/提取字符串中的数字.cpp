//��ȡ����
#include<iostream>
using namespace std;

//���Խ�������ַ��������ֺ���ĸ�ֿ������
int main()
{
	string str1 , str2;//str2���ڱ���str1�е���ĸ
	cin >> str1;
	int sum = 0, index = 0;
	for (int i = 0; str1[i] != '\0'; i++)
	{
		if ('0' <= str1[i] && str1[i] <= '9')
		{
			sum *= 10;
			sum += str1[i] - '0';//�����ַ���ascii-�ַ�'0'��ascii��͵��ڸ�����
			//����Ҫֱ����intת��������ںܴ����ֵ��ֵ��
		}
		if ('A' <= str1[i] && str1[i] <= 'Z' || 'a' <= str1[i] && str1[i] <= 'z')
		{
			str2 += str1[i];
		}
	}
	cout << sum << endl;
	cout << str2 << endl;
}