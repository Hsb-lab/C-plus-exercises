//���һԪ���η���
//C++���ԣ���ֵ��0��ȫΪ��ֵ
#include<iostream>
#include<cmath>
using namespace std;

double Judge(double a, double b , double c)
{
	return pow(b, 2) - 4 * a * c;
}

int main()
{
	double a, b, c;//a��b��c�ֱ�����Ԫһ�η��̵Ķ�����ϵ����һ����ϵ���Լ�������
	cin >> a >> b >> c;
	double p = Judge(a, b, c);
	if (p < 0)
	{
		cout << "�˷�����ʵ����" << endl;
		return 0;
	}
	double x1 = (-b + sqrt(p)) / (2 * a);
	double x2 = (-b - sqrt(p)) / (2 * a);
	if (x1 == x2)
	{
		cout << "����ֻ��һ���⣺" << x1 << endl;
	}
	else
	{
		cout << "�����������⣺" << x1 <<'\t'<<x2<< endl;
	}
}