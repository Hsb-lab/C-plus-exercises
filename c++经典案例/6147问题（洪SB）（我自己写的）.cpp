//【题目描述】
//假设你有一个各位数字互不相同的四位数，把所有数字从大到小排序后得到a，从小到大排序后得到b，
//然后用a - b替换原来的数，并且继续操作。
//有趣的是这样操作了几次后会得到四位数6174，而对6174进行处理，为7641 - 1467 = 6174，回到了它自己。
//输入一个n位数（不一定是四位数），输出操作序列，直到第一次出现循环。
//输入保证在循环之前最多只会产生1000个整数。
//注意：若输入0则无输出
//【输入格式】
//一行一个整数
//【输出格式】
//一行输出操作序列(包括一开始的数)
//（注：序列中的每个数通过一个空格隔开。）
//【输入样例1】
//1234
//【输出样例1】
//1234 3087 8352 6174 6174
//【输入样例2】
//1234567
//【输出样例2】
//1234567 6419754 8319762 8639532 7529643 7419753 8429652 7619733
//8439552 7509843 9529641 8719722 8649432 7519743 8429652
#include<iostream>
#include <cmath>
using namespace std;
//获取n位数的函数01
int func01(int n)
{
	return log10(n) + 1;
}

//获取排序后n的最大值02
int func02(int arr[], int len)
{
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += arr[i] * pow(10, i);
	}
	return sum;
}

//获取排序后n的最小值03
int func03(int arr[], int len)
{
	int sum = 0;
	for (int i = len-1, j= 0; i >=0 ; i--)
	{
		sum += arr[i] * pow(10, j); j++;
	}
	return sum;
}

//获取处理后的数值（排序后的最大值减去最小值）
int func04(int n)
{
	int len = func01(n);//len表示n的位数
	int* arr = new int[len];
	for (int i = 0; i < len; i++)
	{
		arr[i] = (n % 10); n /= 10;
	}

	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return func02(arr, len) - func03(arr, len);

}
int main()
{
	int n; cin >> n; if (n == 0)  return 0;
	cout << n << " ";//n表示输入的样本数据 
	int x = 0; int array[1000] ;  array[0] = n;
	while (1)
	{
		cout << func04(n) <<" "; x++;
		array[x] = func04(n);
		for (int i = 0; i < x; i++)
		{
			if (array[x] == array[i])
			{
			  return 0;
		}

		}
		
		n = func04(n);
	}
	return 0;
}