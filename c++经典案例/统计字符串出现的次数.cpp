//统计字符串出现的次数
#include<iostream>
using namespace std;
int main()
{
	string m, s;
	cin >> m >> s;//定义并输入两个字符串
	int m_len = m.length();
	int s_len = s.length();//获取两个字符串的长度
	int sum = 0;//sum为计数器
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