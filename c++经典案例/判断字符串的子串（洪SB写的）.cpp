//����Ŀ������
//������s����ŵ�����˳��ѡ��һ���Ӵ�t����t��s�������С�
//���磬��������s = "abcbda"���Ӵ�"bcd"��s��һ�������С�
//������������s1��s2�����Ӵ�t����s1������������s2��������ʱ����t��s1��s2�Ĺ��������С�
//���磬����s1 = "abcbda"������s2 = "abcab"���Ӵ�"acb"������s1��s2�Ĺ��������С�
//Ҫ���д�����жϸ������Ӵ��Ƿ�Ϊ���������Ĺ��������С�
//�������ʽ��
//һ�������ַ���(�м���һ���ո�ָ�)���ֱ��ʾ�������� s1��s2 �� t
//�������ʽ��
//��Ҫ����� "yes" �� "no" (��������)
//����������1��
//abcdef abcffff abc
//���������1��
//yes
//����������2��
//abcdef ffff abc
//���������2��
//no
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//��ȡ�ַ����ĳ���
int func01(string str)
{
	int len = str.length();
	return len;
}

//�ж������ַ����Ƿ񹹳��ִ���ϵ
bool func02(string str1, string str2)
{
	int len_1 = func01(str1); int len_2 = func01(str2);
	  if (len_1 < len_2) return 0;
	for (int i = 0; i < len_2; i++)
	{
		for (int j = 0; j < len_1; j++)
		{
			if (str2[i] == str1[j]) break;
			if (j == len_1 - 1)  return 0;
	}
		
	}
	return 1;
}
int main()
{
	string s1, s2, t;
	cin >> s1 >> s2 >> t;
	if (func02(s1, t) && func02(s2, t))   cout << "yes";
	else  cout << "no";
}