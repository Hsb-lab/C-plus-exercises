//【题目描述】
//给定两个正整数m, n，以及一个m* n的二维数组，将这个数组按列输出。（输出转置后的矩阵）
//【输入格式】
//输入共 m 行 ，每行 n 个数表示一个二维数组
//【输出格式】
//输出共 n 行 ，每行 m 个数表示原数组按列输出后的结果(转置后的矩阵)
//【样例输入】
//3 4
//1 2 3 4
//5 6 7 8
//9 10 11 12
//【样例输出】
//1 5 9
//2 6 10
//3 7 11
//4 8 12
#include<iostream>
using namespace std;
int main()
{
	int m, n; cin >> m >> n;//m代表行数，n代表列数(一列有m个，一行有n个)
	int** x = new int* [m];//创建第一个动态数组
	for (int i = 0; i < m; i++)
	{
		x[i] = new int[n];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> x[i][j];
	}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << x[j][i] << " ";
			if (j == m - 1) cout << endl;
			
	}

	}
}