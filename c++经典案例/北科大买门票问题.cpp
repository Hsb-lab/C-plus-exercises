//北科大买门票问题
#include<iostream>
using namespace std;

int COUNT = 0;//计数器（全局变量）

//求n阶乘的函数
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
	int sum, m_five, m_ten;//sum代表总人数，m_five代表拿五元的人数，m_ten代表拿十元的人数
	cin >> sum >> m_five >> m_ten;
	if (sum != m_five + m_ten)
	{
		cout << "你个SB，人数都数不对！" << endl;
		return 0;
	}
	func02(m_five, m_ten, 0);
	cout << func01(m_five) * func01(m_ten) * COUNT<< endl;
	return 0;
}