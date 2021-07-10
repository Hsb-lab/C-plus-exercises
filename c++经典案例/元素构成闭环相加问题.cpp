//【题目描述】
//若干个数据首尾相连，构成一个圆环，找到连续的4个数之和最大的一段。
//【输入格式】
//一行若干个数，当输入−1时结束输入
//【输出格式】
//一行输出其中连续的4个数之和最大的一段的起始数据的位置及这4个数的和，
//若输入的数据少于4个数，输出显示“invalid input”。
//【输入样例1】
//1 23 - 1
//【输出样例1】
//invalid input
//【输入样例2】
//7 6 2 3 9 1 8 -1
//【输出样例2】
//5 25
//（注：从第5个数据开始的连续四个数据和最大, 为25）
#include <iostream>
using namespace std;
int main()
{
	int x = 0;//x表示输入的元素
	int array[1000];//创建一个足够长的数组
	int i = 0;//i有妙用（请记住这个i后面要考的）
	while (x != -1)
	{

		cin >> x; array[i] = x;
		i++;
	}
	i = i - 1;//i的值为有效数据（除-1以外的数据）的个数
	if (i < 4)  cout << "invalid input";
	else {

		int *arr = new int [i];//arr是用来接受sum的动态数组
		for (int a = 0, c = 0; a <= i - 1; a++, c++)
		{
			int sum = 0;//sum表示四个数据的总和 
			for (int b = a; b < a + 4; b++)
			{
				if (b >= i) { sum += array[b - i]; continue; }
				sum += array[b];
			}
			arr[c] = sum;
		}
		int max = arr[0];//max表示最大的sum值
		for (int c = 0; c < i; c++)
		{
			if (max < arr[c + 1])   max = arr[c + 1];

		}
		//找到目标下标
		for (int c = 0; c < i ; c++)
		{
			if (arr[c] == max) { cout << c + 1 << " "; break; }

		}
		cout << max;
	}
}