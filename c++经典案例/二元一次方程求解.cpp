//求解一元二次方程
//C++特性：数值除0外全为真值
#include<iostream>
#include<cmath>
using namespace std;

double Judge(double a, double b , double c)
{
	return pow(b, 2) - 4 * a * c;
}

int main()
{
	double a, b, c;//a，b，c分别代表二元一次方程的二次项系数、一次项系数以及常数项
	cin >> a >> b >> c;
	double p = Judge(a, b, c);
	if (p < 0)
	{
		cout << "此方程无实数解" << endl;
		return 0;
	}
	double x1 = (-b + sqrt(p)) / (2 * a);
	double x2 = (-b - sqrt(p)) / (2 * a);
	if (x1 == x2)
	{
		cout << "方程只有一个解：" << x1 << endl;
	}
	else
	{
		cout << "方程有两个解：" << x1 <<'\t'<<x2<< endl;
	}
}