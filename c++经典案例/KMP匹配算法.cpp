//KMP ģʽƥ���㷨ʵ��

#include<iostream>
using namespace std;
#include<string>
#include<cstring>

//�õ�next����ĺ���
void Get_Next(string T,int *next)//T����Ŀ���Ӵ�
{
	int len = T.size();//��ȡ�Ӵ��ĳ���
	int i = 1, j = 0;

	next[0] = 0;
	while (i < len)
	{
		if (T[i] == T[j])
		{
			next[i] = j + 1;
			i++;
			j++;
		}
		else
		{
			if (j > 0) j = next[j - 1];
			else if (j == 0 && T[i] != T[j])
			{
				next[i] = 0;
				i++;
			}
		}
	}

	return;//��Ҫ���ؾֲ����������û��ַ
}

//���KMPƥ��ĺ���
void KMP(string MasterStr,string SubStr,int *next)
{
	int Times = 0;//ͳ���Ӵ����ֵĴ���
	int len01 = MasterStr.length();
	int len02 = SubStr.length();
	int i = 0,j = 0;
	while (j < len01)
	{
		if (SubStr[i] == MasterStr[j])
		{
			i++;
			j++;
		}
		else
		{
			if (i > 0) i = next[i - 1];
			else
			{
				if (SubStr[0] != MasterStr[j]) j++;
			}
		}

		if (i == len02 - 1 && SubStr[i] == MasterStr[j])
		{
			Times++;
			i = 0;
			j++;
		}
	}

	if (Times == 0) cout << "δƥ�䵽���ַ�" << endl;
	else cout << "ƥ�䵽���ַ�" << "���ַ�������" << Times << "��" << endl;
}

void test01()
{
	string T = "aa";
	int len = T.length();
	int *next = new int[len];
	Get_Next(T, next);
	for (int i = 0; i < len; i++)
	{
		cout << next[i];
	}
	cout << endl;

	KMP("abaaabaaa", T, next);
}

int main()
{
	test01();
}