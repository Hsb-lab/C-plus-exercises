//ˮ�ɻ���
//��νˮ�ɻ�����NarcissisticNumber����ָһ��3λ�������λ���ֵ������͵���������
//˼·����1����������λ���ַֽ������Ȼ����������������Ƿ����ԭ��
//��2����3�����֣����һ����λ������������������Ƿ���ڴճɵ�����ע���λ���ִ�1��ʼ��
//����153�ǡ�ˮ�ɻ���������Ϊ��153 = 13 + 53 + 33��
//���100~1000֮���ˮ�ɻ���
#include<iostream>
#include<cmath>
using namespace std;

bool func(int i)
{
	int a = i % 10;//��ȡ��λ����
	int b = (i / 10) % 10;//��ȡʮλ����
	int c = i / 100;//��ȡ��λ����
	int temp = pow(a, 3) + pow(b, 3) + pow(c, 3);
	if (temp == i) return true;
	else return false;
}

int main()
{
	for (int i = 100; i < 1000; i++)
	{
		if (func(i)) cout << i << endl;
	}
}