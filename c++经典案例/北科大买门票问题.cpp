//���ƴ�����Ʊ����
#include<iostream>
using namespace std;

int COUNT = 0;//��������ȫ�ֱ�����

//��n�׳˵ĺ���
int func01(int n)
{
	if (n == 1) return 1;
	else return n * func01(n - 1);
}

void func02(int m_five , int m_ten , int x)
{
	if (m_five == 0 || m_ten == 0)
	{
		COUNT++;
		return;
	}
	
    else if (x > 0)
	{
		func02(m_five - 1, m_ten, x + 1);
		func02(m_five, m_ten - 1, x - 1);
	}
    
	else if (x == 0)
	{
		func02(m_five - 1, m_ten, x + 1);
	}
}

int main()
{
	int sum, m_five, m_ten;//sum������������m_five��������Ԫ��������m_ten������ʮԪ������
	cin >> sum >> m_five >> m_ten;
	if (sum != m_five + m_ten)
	{
		cout << "���SB�������������ԣ�" << endl;
		return 0;
	}
	func02(m_five, m_ten, 0);
	cout << func01(m_five) * func01(m_ten) * COUNT<< endl;
	return 0;
}