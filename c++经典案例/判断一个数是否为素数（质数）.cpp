//�㷨�뽨ģ
//��ֵ����ѧ����
//�����ж�
//�������ݣ��㷨2��������ɸѡ����n���ܹ��������ڸ���n���κ�������������n��һ������
//���������������Լ����㣩
//�״���ʾ��1��������
#include<iostream>
#include<cmath>
using namespace std;

//�ж�һ�����Ƿ�Ϊ�������������ĺ���
bool func(int m)
{
	for (int i = 2; i <= sqrt(m); i++)
	{
		if (m % i == 0)  return 0;
	}
	return 1;
}

int main()
{
	int m;
	cin >> m;
	if (func(m)) cout << "mΪ����" << endl;
	else cout << "m��������" << endl;
}