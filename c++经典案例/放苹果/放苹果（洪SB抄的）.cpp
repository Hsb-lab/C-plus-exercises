//��ƻ��
//��M��ͬ����ƻ������N��ͬ��������������е����ӿ��Ų��ţ��ʹ��ж����ֲ�ͬ�ķַ���
#include<iostream>
using namespace std;

int func(int m, int n)
{
	if (m == 0)  return 1;
	if (n == 0) return 0;
	if (m  < n)  return func(m, m);//���Ӳ�����ֿյ����
	else
	{
		return func(m - n, n) + func(m, n - 1);//��������ۣ����޿չ�����
	}
}

int main()
{
	int m, n;//m����ƻ��������n������������
	cin >> m >> n;
	cout << func(m, n) << endl;
}