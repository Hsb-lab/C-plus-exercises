//【题目描述】
//在 n* n方阵里填入1，2……n* n，要求填成蛇形。例如 n = 4 时方阵为：
//10 11 12 1
//9 16 13 2
//8 15 14 3
//7 6 5 4
//上面的方阵中，多余的空格只是为了便于观察规律，不必严格输出。n <= 10
//【输入格式】
//一行一行个整数n
//【输出格式】
//一个 n * n 的矩阵表示蛇形填数后的结果。
//要求：每一个数字要占4位，不足用空格补全。
//【样例输入】
//2
//【样例输出】
//4 1
//3 2
#include <iostream>
using namespace std;
void func(int ** arr, int n)
{
	static int count = 1;
	static int  x = 0;
	for (int i = 0 + x ; i < n-x; i++)//从上向下填数字
	{
		arr[i][n-1-x] = count++;
	}

	for (int i = n - 2 - x; i >= 0+x; i--)//从右至左填数字
	{
		arr[n - 1 - x][i] = count++;
	}

	for (int i = n - 2 - x; i >= 0+x; i--)//从下向上填数字
	{
		arr[i][0+x] = count++;
	}

	for (int i = 1 + x; i <= n - 2 - x; i++)//从左至右填数字
	{
		arr[0+x][i] = count++;
	}
	x++;
	if ((n-x*2)== -1 ||(n-x*2) == 0)   return;
	else  func(arr, n);
}

int main()
{
	int n; cin >> n;//n代表n*n的矩阵
	int** arr = new int* [n];//创建动态二维数组
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
	}
	func(arr, n);
	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < n ; j++)
		{   
			cout << arr[i][j] << "   ";
			if (j == n - 1)  cout << endl;
		}
	}
}