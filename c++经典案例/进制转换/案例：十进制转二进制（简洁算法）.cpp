//����Ŀ������
//����1��������n��n > 0��������ת��Ϊ�����ƺ������
//�������ʽ��
//һ��һ�������� n
//�������ʽ��
//һ��һ������������ʾ���
//���������롿
//15
//�����������
//1111
#include <iostream>
using namespace std;
#include <cmath>
int main()
{
	long long n, i = 0, sum = 0;
	cin >> n;
	while (n)
	{
		sum += (n % 2) * pow(10, i);
		n = n / 2;
		++i;
	}
	cout << sum;
}