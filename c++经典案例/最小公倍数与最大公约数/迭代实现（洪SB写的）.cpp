//�㷨�뽨ģ
//һ����ֵ����ѧ����
//��С������   ��    ���Լ��
//�㷨��շת�����
//���ۣ�������Ȼ�������Լ�������ǵ���С�������ĳ˻��������������ĳ˻�
#include<iostream>
using namespace std;

void Swap(int& m, int& n)
{
	int temp = m;
	m = n;
	n = temp;
}

int func(int m, int n)
{
	int s ;//����������
	do
	{
		s = m % n;
		m = n;
		n = s;
	} while (s != 0);
	return m;
}

int main()
{
	int m, n;
	cin >> m >> n;
	if (m < n)  Swap(m, n);
	int p1 = func(m, n);
	int p2 = m * n / p1;
	cout << p1 << endl;//�����Լ��
	cout << p2 << endl;//����С������

}