//二项式系数表(杨辉三角)
#include<iostream>
using namespace std;

//给第i行第j个元素赋值
void func01(int** array, int i, int j)
{
	if (i == j || j == 0)
	{
		array[i][j] = 1;
		return;
	}
	else
	{
		array[i][j] = array[i - 1][j] + array[i - 1][j - 1];
		return;
	}
}

int main()
{
	int n;
	cin >> n;
	int len = n + 1;

	//创建二维数组
	int** arr = new int* [len];//创建行指针
	for (int i = 0, j = 1; i < len; i++, j++)
	{
		arr[i] = new int[j];
	}

	//给二位数组中的元素赋值
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			func01(arr, i, j);
		}
	}

	//数值二维数组
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	//释放堆区内存
	for (int i = 0; i < len; i++)
	{
		delete arr[i];
		arr[i] = NULL;
	}
}