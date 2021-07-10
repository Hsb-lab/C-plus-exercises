//进制转换
//整数转换：除基取余，逆序排列
//小数转换：乘积取整，正序排列
//调用了系统的标准函数就不要写自己的了，否则会产生意想不到的操蛋结果
#include<iostream>
using namespace std;
#include<bitset>
#include<cmath>
void test01(int m)
{
	cout << oct << m << endl;//八进制
	cout << dec << m << endl;//十进制
	cout << hex << m << endl;//十六进制
	cout << bitset<8>(m) << endl;//二进制
}

void test02(int m , int n)
{
	int sum = 0 , i = 0;
	while (m)
	{
		sum += (m % n) * pow(10, i);
		m = m / n;
		i++;
	}
	cout << sum << endl;
}

int main()
{
	int m; 
	cout << "请输入要转换的数" << endl;
	cin >> m;
	//test01(m);//直接调用系统的标准函数
	cout << "请输入要转换成的进制" << endl;
	int n; 
	cin >> n;
	test02(m, n);
}