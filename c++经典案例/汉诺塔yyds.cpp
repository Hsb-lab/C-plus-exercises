//汉诺塔问题
//该游戏是在一块铜板装置上，有三根杆(编号A、B、C)，
//在A杆自下而上、由大到小按顺序放置64个金盘(如图1)。
//游戏的目标：把A杆上的金盘全部移到C杆上，并仍保持原有顺序叠好。
//操作规则：每次只能移动一个盘子，并且在移动过程中三根杆上都
//始终保持大盘在下，小盘在上，
//操作过程中盘子可以置于A、B、C任一杆上。
#include<iostream>
using namespace std;

void Hanoi(int n, char A, char B, char C)
{
	if (n == 1)
	{
		cout << A << "->" << C << endl;
	}
	else
	{
		Hanoi(n - 1, A, C, B);
		cout << A << "->" << C << endl;
		Hanoi(n - 1, B, A, C);
	}
}

void test01()
{
	int n = 0;
	cin >> n;//输入汉诺塔问题的规模
	Hanoi(n, 'A', 'B', 'C');
}

int main()
{
	test01();
}