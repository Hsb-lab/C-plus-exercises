//ͳ���ַ������ֵĴ���
#include<iostream>
using namespace std;
int main()
{
	string m, s;
	cin >> m >> s;//���岢���������ַ���
	int m_len = m.length();
	int s_len = s.length();//��ȡ�����ַ����ĳ���
	int sum = 0;//sumΪ������
	for (int i = 0; i < m_len; i++)
	{
		if (m[i] == s[0])
		{
			for (int j = 0 , h = i; j < s_len; j++,h++)
			{
				if (m[h] != s[j])  break;
				if (j == s_len - 1)   sum += 1;
			}
		}
	}

	cout << sum << endl;
}