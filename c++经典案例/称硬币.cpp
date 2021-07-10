//��Ӳ��
//������������12öӲ�ҡ�������11ö��Һ�1ö�ٱҡ��ٱҺ����������ͬ��
//����֪���ٱұ�����ػ����ᡣ���ڣ���һ����ƽ������Щ�����Σ�
//������ƵĽ���������ҳ��ٱҲ���ȷ���ٱ���������

//��������
//1
//ABCD EFGH even / up / down ��ƽ�������ߵ�Ӳ����������ȵ�

//strchr��������Ϊ��һ�����в��Ҹ����ַ��ĵ�һ��ƥ��֮����
//����ԭ��Ϊ��char* strchr(const char* str, int c)��
//���ڲ��� str ��ָ����ַ�����������һ�γ����ַ� c��һ���޷����ַ�����λ�á�
//strchr����������C ��׼�� <string.h>�С�

//char* strchr(const char* str, int c)
//str-- Ҫ�������� C �ַ�����
//c-- �� str ��Ҫ�������ַ���
//�ڲ���str��ָ����ַ�����������һ�γ����ַ�c��һ���޷����ַ�����λ��
//����һ��ָ����ַ����е�һ�γ��ֵ��ַ���ָ�룬����ַ����в��������ַ��򷵻�NULL��ָ�롣

#include<iostream>
using namespace std;
#include<cstring>
char Left[3][7];//��ƽ���Ӳ��
char Right[3][7];//��ƽ�ұ�Ӳ��
char Result[3][7];//���

//lightΪ���ʾ����ٱ�Ϊ�ᣬ�����ʾ����ٱ�Ϊ��
bool IsFake(char c, bool light);

int main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < 3; i++)
		{
			cin >> Left[i] >> Right[i] >> Result[i];
		}
		for (char c = 'A'; c <= 'L'; c++)
		{
			if (IsFake(c, true))
			{
				cout << c << " is the counterfeit coin and it is light" << endl;
				break;
			}
			else if (IsFake(c, false))
			{
				cout << c << " is the counterfeit coin and it is heavy" << endl;
				break;
			}
		}

	}
}

bool IsFake(char c, bool light)
{
	//lightΪ���ʾ����ٱ�Ϊ�ᣬ�����ʾ�ٱ�Ϊ��
	for (int i = 0; i < 3; i++)
	{
		char* pLeft, * pRight;//ָ����ƽ���ߵ��ַ���
		if (light)
		{
			pLeft = Left[i];
			pRight = Right[i];
		}
		else
		{
			pLeft = Right[i];
			pRight = Left[i];
		}

		switch (Result[i][0])//��ƽ�ұߵ����
		{
		case'u':
			if (strchr(pRight, c) == NULL) return false;
			break;

		case'e':
			if (strchr(pLeft, c) || strchr(pRight, c)) return false;
			break;

		case'd':
			if (strchr(pLeft, c) == NULL) return false;
			break;
		}
	}
	return true;
}