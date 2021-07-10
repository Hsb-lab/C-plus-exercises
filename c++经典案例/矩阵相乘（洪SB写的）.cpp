#include<iostream>
using namespace std;

int ** func01(int row , int col)//创建动态二维数组
{
	int** a_Arr = new int* [row];//创建行指针
	for (int i = 0; i < row; i++)
	{
		a_Arr[i] = new int[col];//给每一行分配内存
	}
	cout << "请输入元素" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> a_Arr[i][j];
		}
	}
	return a_Arr;
}

//编译程序时，出现了以下问题：
//严重性 代码 说明 项目 文件 行 禁止显示状态 错误 C3861 “managerMenu” : 找不到标识符
//原因时调用函数，但之前没有编写函数声明，解决方法：在前面加入函数的声明
int func03(int** p1, int** p2, int i, int j, int col_1, int row_2);

int** func02(int** p1, int row_1, int col_1, int** p2, int row_2, int col_2)//创建相乘后的数组
{
	int** a_Arr = new int* [row_1];//创建行指针
	for (int i = 0; i < row_1; i++)
	{
		a_Arr[i] = new int[col_2];//给每一行分配内存
	}

	for (int i = 0; i < row_1; i++)
	{
		for (int j = 0; j < col_2; j++)
		{
			a_Arr[i][j] = func03(p1, p2, i, j,col_1,row_2);//其实这里col_1 = row_2
		}
	}
	return a_Arr;
}

int func03(int** p1, int** p2,int i,int j,int col_1,int row_2)//两个数组间的相乘操作
{
	int sum = 0;
	for (int q = 0; q < col_1; q++)
	{
		sum += p1[i][q] * p2[q][j];
	}
	return sum;
}

int main()
{
	int row, col;//row代表行数，即一列有多少个；col代表列数，即一行有多少个
	cout << "请输入行数和列数" << endl;
	cin >> row >> col;
	int m = row; int n = col;
	int** p1 = func01(m, n);//创建第一个矩阵

	cout << "请再次输入行数和列数" << endl;
	cin >> row >> col;
	if (n != row)
	{
		cout << "你个SB，输入错误" << endl;
		cout << "第一个矩阵的行数应该与第二个矩阵的列数相等" << endl;
		cout << "如果还想继续在运行一次吧" << endl;
		return 0;
	}
	int** p2 = func01(row, col);//创建第二个矩阵

	int ** p = func02(p1,m,n,p2,row,col);

	cout << "两个相乘后的矩阵为" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}