//函数指针
//C++中，可以用关键字typedef定义函数类型名。函数类型名定义的一般形式为：
//typedef 类型 函数类型名（形式参数列表）
//函数类型名统帅三军，是所有同类型函数（函数名不同）集体意志的表现(这局话最终解释权归洪SB所有)


#include<iostream>
using namespace std;
typedef void FuncType(int, int);
FuncType max, min;
typedef void (*pType)(int, int);
pType p1,p2;

int main()
{
	p1 = max;
	p2 = min;
	p1(10, 20);
	cout << endl;
	p2(10, 20);
}
void max(int a, int b)
{
	if (a > b) cout << a;
	else cout << b;
}
void min(int a, int b)
{
	if (a < b) cout << a;
	else cout << b;
}